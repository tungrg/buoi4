//
//  tree.c
//  TreeTraversal
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "tree.h"

tree_node* create_node(const Data data)
{
    tree_node* n = (tree_node*) malloc(sizeof(tree_node));
    n->data = data;
    
    for (int i = 0; i < MAX_CHILDREN; i++)
        n->children[i] = NULL;
    
    return n;
}

void add_node(tree_node** root, tree_node* agg) {
    if (*root == NULL) {
        *root = agg;
        return;
    }
    for (int i = 0; i < MAX_CHILDREN; i++) {
        if ((*root)->children[i] == NULL) {
            (*root)->children[i] = agg;
            break;
        }
    }
}

tree_node* find_node_by_id(tree_node* node, char id[]) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(node->data.id, id) == 0) {
        return node;
    }
    for (int i = 0; i < MAX_CHILDREN; i++) {
        tree_node* child = node->children[i];
        if (child != NULL) {
            tree_node* res = find_node_by_id(child, id);
            if (res != NULL) {
                return res;
            }
        }
    }
    return NULL;
}

float calculate_income(tree_node* node) {
    if (node == NULL) {
        return 0;
    }
    float sub_sum = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        sub_sum += 0.3*calculate_income(node->children[i]);
    }
    return 0.7 * node->data.sales + sub_sum;
}


void clear_tree(tree_node **root)
{
    // TODO
    // - check if root is NULL then return
    if (*root == NULL) return;
    // - clear all children of root by calling clear_tree() recursively
    for (int i = 0; i < MAX_CHILDREN; i++)
        clear_tree(&(*root)->children[i]);
    // - free root
    free(*root);
    // - set root to NULL
    *root = NULL;
}

void printfln_items(tree_node* const node) {
    printf("----------------------\n");
    printf("Id: %s\n", node->data.id);
    printf("Name: %s\n", node->data.name);
    printf("Sales: %.2f\n", node->data.sales);
}

void in_order(tree_node * const root)
{
    // TODO
    // - check if root is NULL then return
    if (root == NULL) return;
    // - print left child by calling in_order() recursively
    in_order(root->children[0]);
    // - print root data
    printfln_items(root);
    // - print right children by calling in_order() recursively
    for (int i = 1; i < MAX_CHILDREN; i++)
        in_order(root->children[i]);
}

void pre_order(tree_node * const root)
{
    // TODO
    // - check if root is NULL then return
    if (root == NULL) return;
    // - print root data
    printfln_items(root);
    // - print left child by calling pre_order() recursively
    // pre_order(root->children[0]);
    // - print right children by calling pre_order() recursively
    for (int i = 0; i < MAX_CHILDREN; i++)
        pre_order(root->children[i]);
}

void post_order(tree_node * const root)
{
    // TODO
    // - check if root is NULL then return
    if (root == NULL) return;
    // - print left child by calling post_order() recursively
    for (int i = 0; i < MAX_CHILDREN; i++)
        post_order(root->children[i]);
    // - print right children by calling post_order() recursively
    // - print root data
    printfln_items(root);
}
