typedef struct {
    int n;
    int* digit;
} bigint;

extern void bigint_set_int(bigint*, int);
extern void bigint_add(bigint*, bigint*);
extern void bigint_mul(bigint*, bigint*);
extern void bigint_print(bigint*);
