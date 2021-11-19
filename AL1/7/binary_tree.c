/* binary_tree.c */

#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

Node* tree_construct(int value, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->parent = NULL;
    node->left = left;
    if(left != NULL) {
        left->parent = node;
    }
    node->right = right;
    if(right != NULL) {
        right->parent = node;
    }
    
    return node;
}

void tree_free(Node* tree) {
    if(tree->left != NULL) {
        tree_free(tree->left);
    }
    if(tree->right != NULL) {
        tree_free(tree->right);
    }
    free(tree);
}

int tree_depth(Node* node) {
    int depth = 0;
    while(node->parent != NULL) {
        node = node->parent;
        depth++;
    }
    return depth;
}

int tree_height(Node* node) {
    if (node == NULL) return 0;
    else {
        int left = tree_height(node->left);
        int right = tree_height(node->right);
        if (left > right) return left+1;
        else return right+1;
    }
}

void tree_preorder(Node* tree, Visitfn f) {
    f(tree->value);

    if(tree->left != NULL) {
        tree_preorder(tree->left, f);
    }

    if(tree->right != NULL) {
        tree_preorder(tree->right, f);
    }
}

void tree_inorder(Node* tree, Visitfn f) {
    if (tree->left != NULL) {
        tree_inorder(tree->left, f);
    }

    f(tree->value);

    if (tree->right != NULL) {
        tree_inorder(tree->right, f);
    }
}

void tree_postorder(Node* tree, Visitfn f) {
    if(tree->left != NULL) {
        tree_postorder(tree->left, f);
    }

    if(tree->right != NULL) {
        tree_postorder(tree->right, f);
    }

    f(tree->value);
}