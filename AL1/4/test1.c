#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node;

int top(node* lst) {
    return lst->next->value;
}

int get(node* lst, int n) {
int cnt=0;
int value;
while (cnt<n) {
    value = cur->value;
    cur = cur->next;
}
return value;
}