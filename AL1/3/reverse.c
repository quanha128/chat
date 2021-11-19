#include <stdio.h>
#include "array_list.h"
#include <stdlib.h>

LIST reverse(LIST lst) {
    LIST new = list_construct();
    POSITION p = list_first(lst);
    POSITION q = list_first(new);
    POSITION r = list_last(lst)-1;
    while(p != list_last(lst)) {
        int value = list_retrieve(lst, r);
        list_insert(new, q, value);
        q = list_next(new, q);
        p = list_next(lst, p);
        r = list_previous(lst, r);
    }
    return new;
}

int main(int argc, char* argv[]) {
    LIST lst = list_construct();
    POSITION p = list_first(lst);

    for(int i = 0; i < 20; i++) {
        list_insert(lst, p, rand() % 10);
    }
    list_print(lst);
    list_print(reverse(lst));

    return 0;
}