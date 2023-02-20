//
//  tree.h
//  TreeTraversal
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILDREN 3


typedef struct data
{
    char id[10];
    char name[30];
    int sales;
} Data;
typedef struct str_tree_node* child;
struct str_tree_node
{
    Data data;
    child children[MAX_CHILDREN];
};

typedef struct str_tree_node tree_node;



tree_node* create_node(const Data data);
void clear_tree(tree_node **root);
void in_order(tree_node * const root);
void pre_order(tree_node * const root);
void post_order(tree_node * const root);

#endif /* tree_h */
