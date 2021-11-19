#include <stdlib.h>
#include <stdio.h>

typedef struct linkedlist {
    int val;
    linkedlist* next;
} linkedlist;

linkedlist list_construct() {
    linkedlist* node = malloc(sizeof(linkedlist));
    node->next = NULL;

    return node;
}