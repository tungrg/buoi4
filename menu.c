#include "menu.h"
#include "tree.h"

void print_menu_main(int* lenh) {
    int index;
    printf("Menu:\n");
    printf("  1.Them mot nhan vien\n");
    printf("  2.Tinh thu nhap\n");
    printf("  3.In thong tin toan bo nhan vien\n");
    printf("  4.Thoat\n");
    printf("Vui long chon lenh: ");
    scanf("%d", &index);
    *lenh = index;
}

void print_menu_add(tree_node** head) {
    char boss_id[10];
    Data temp;
    if(*head == NULL) {
        goto add_new_node;
    }
    printf("-Nhap id cua nhan vien cap tren: ");
    scanf("%9s", boss_id);
    tree_node* founded_node = find_node_by_id(*head, boss_id);
    if (founded_node == NULL) {
        printf("Khong tim thay id cua nhan vien cap tren!!!\n");
        system("pause");
        return;
    }
    add_new_node:
        printf("-Nhap id cua nhan vien: ");
        scanf("%9s", temp.id);
        printf("-Nhap ten cua nhan vien: ");
        scanf("%29s", temp.name);
        printf("-Nhap doanh so ban hang cua nhan vien: ");
        scanf("%f", &temp.sales);
    tree_node* param_node = create_node(temp);
    if (*head == NULL) {
        add_node(head, param_node);
    }
    else {
        add_node(&founded_node, param_node);
    }
    
}

void print_menu_calculate_income(tree_node* head) {
    char find_id[10];
    printf("-Nhap id cua nhan vien: ");
    scanf("%9s", find_id);
    tree_node* founded_node = find_node_by_id(head, find_id);
    if (founded_node == NULL) {
        printf("Khong tim thay id cua nhan vien!!!\n");
        system("pause");
        return;
    }
    printf("Thu nhap cua nhan vien la: %.2f\n",calculate_income(founded_node));
    system("pause");
}

void print_menu_show_list(tree_node* head) {
    pre_order(head);
}