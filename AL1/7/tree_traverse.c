/* tree_traverse.c */

#include <stdio.h>
#include "tree.h"

void print_node(int value) {
    printf(" %d ", value);
}

int main(int argc, char** argv) {
    Node* node4 = tree_construct(4, NULL, 0);
    Node* node5 = tree_construct(5, NULL, 0);
    Node* node6 = tree_construct(6, NULL, 0);
    Node* nodes456[3] = { node4, node5, node6 };
    Node* node2 = tree_construct(2, nodes456, 3);
    Node* node3 = tree_construct(3, NULL, 0);
    Node* nodes23[2] = { node2, node3 };
    Node* node1 = tree_construct(1, nodes23, 2);

    printf("Preorder:");
    tree_preorder(node1, print_node);
    printf("\n");

    printf("Inorder:");
    tree_inorder(node1, print_node);
    printf("\n");

    printf("Postorder:");
    tree_postorder(node1, print_node);
    printf("\n");

    tree_free(node1);

    return 0;
}