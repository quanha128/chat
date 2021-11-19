/* binary_tree_traverse.c */

#include <stdio.h>
#include "binary_tree.h"

void print_node(int value) {
    printf(" %d ", value);
}

int main(int argc, char** argv) {
    Node* node4 = tree_construct(4, NULL, NULL);
    Node* node5 = tree_construct(5, NULL, NULL);
    Node* node6 = tree_construct(6, NULL, NULL);
    
    Node* node2 = tree_construct(2, node4, node5);
    Node* node3 = tree_construct(3, node6, NULL);
    Node* node1 = tree_construct(1, node2, node3);

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