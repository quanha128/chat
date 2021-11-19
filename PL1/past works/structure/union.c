#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    enum {REC, CIR} type;
    union {
        struct {
            float w;
            float l;
        } rectangle;

        struct {
            float r;
        } circle;
    };
} figure;

float area(const figure* p)
{
    switch (p->type)
    {
    case REC:
        return p->rectangle.w * p->rectangle.l;
        break;
    
    case CIR:
        return (p->circle.r)*(p->circle.r)*M_PI;
        break;
    }
}

int main()
{
    figure a = {
        .type = REC,
        .rectangle = {.w=4.3, .l=5.6},
    };
    figure b = {
        .type = CIR,
        .circle = {.r=5.0},
    };
    printf("%f\n",area(&a));
    printf("%f\n",area(&b));
}