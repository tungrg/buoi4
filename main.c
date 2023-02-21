//
//  main.c
//  TreeTraversal
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "tree.h"
#include "menu.h"

tree_node* build_test_tree(void);

int main(int argc, const char * argv[])
{
    Data zero = { .id = "0", .name = "congty", .sales = 0 };
    //tree_node* a = create_node(temp);
    //tree_node *root = build_test_tree();

    //tree_node* root = NULL; if u want to add from begining

    tree_node* root = create_node(zero);
    //printf("In-order :  ");  in_order(root);   printf("\n");
    //printf("Pre-order:  ");  pre_order(root);  printf("\n");
    //printf("Post-order: ");  post_order(root); printf("\n");
    int lenh;
    do {
        print_menu_main(&lenh);
        switch (lenh)
        {
        case 1:
            print_menu_add(&root);
            break;
        case 2:
            print_menu_calculate_income(root);
            break;
        case 3:
            print_menu_show_list(root);
            break;
        }
    } while (lenh != 4);

    clear_tree(&root);
    return 0;
}

tree_node* build_test_tree(void)
{

    Data temp = { .id = "123", .name = "1st", .sales = 0 };
    tree_node* a = create_node(temp);

    /*tree_node* b = create_node('b');
    tree_node* c = create_node('c');
    tree_node* d = create_node('d');
    tree_node* e = create_node('e');
    tree_node* f = create_node('f');
    tree_node* g = create_node('g');
    tree_node* h = create_node('h');
    tree_node* i = create_node('i');
    tree_node* j = create_node('j');
    tree_node* k = create_node('k');
    tree_node* l = create_node('l');
    tree_node* m = create_node('m');
    tree_node* n = create_node('n');
    tree_node* o = create_node('o');
    tree_node* p = create_node('p');
    
    a->children[0] = b; a->children[1] = c; a->children[2] = d;
    b->children[0] = e; b->children[1] = f;
    d->children[0] = g; d->children[1] = h; d->children[2] = i;
    e->children[0] = j; e->children[1] = k;
    g->children[0] = l; g->children[1] = m;
    k->children[0] = n; k->children[1] = o; k->children[2] = p;*/
    
    return a;
}
