#ifndef DEFINE_H_SET
#define DEFINE_H_SET

#include <stdbool.h>

/* Set data structure */
typedef struct SET SET;

/* create an empty new set with integers of range 0 to n */
SET* set_create(unsigned int n);

/* removes a set */
void set_destroy(SET* set);

/* return the number of elements in set */
int set_count(const SET* set);

/* add an element to set */
void set_append(SET* set, unsigned int value);

/* removes an element from set */
void set_remove(SET* set, unsigned int value);

/* returns whether the element is contained in set or not */
bool set_contains(const SET* set, unsigned int value);

/* shows set elements on console */
void set_print(const SET* set);

#endif /* DEFINE_H_SET */