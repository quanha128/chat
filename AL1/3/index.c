#include <stdio.h>
#include "dlinked_list.h"
#include <stdlib.h>

// POSITION index(LIST lst, int value)
// {
//     POSITION p = list_first(lst);
//     POSITION last = list_last(lst);
//     for (p ;p != last; p = list_next(lst, p)) {
//         if (list_retrieve(lst, p) == value) {
//             return p;
//         }
//         continue;
//     }
//     return list_previous(lst, p);
// }

int main() {
    LIST lst = list_construct();
    POSITION p = list_first(lst);

    for(int i = 0; i < 20; i++) {
        list_insert(lst, p, rand() % 10);
    }
    list_print(lst);
    int value;

    scanf("%d", &value);


    printf("Position of %d in list is %d\n", value, (list_index(lst, value))->value);

    return 0;
}