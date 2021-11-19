#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = NULL;
    array = malloc(5*sizeof(int));
    printf("%ld\n",sizeof(*array)/sizeof(array[0]));
    
    /* Now array has 5 entries, from 0 to 4 */
    array[0] = array[1] = array[2] = array[3] = array[4] = 0;
    array = realloc(array, 10*sizeof(*array));
    printf("%ld\n",sizeof(*array)/sizeof(array[0]));

    /* Now array has 10 entries, from 0 to 9 */
    array[5] = array[6] = array[7] = array[8] = array[9] = 0;
    
    free(array);
    array = NULL;
}