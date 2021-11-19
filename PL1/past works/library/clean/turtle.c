#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double theta;
} turtle;

void turtle_forward(turtle* t, double len)
{
    t->x += len*cos(t->theta);
    t->x += len*sin(t->theta);
}

void turtle_left(turtle* t, double deg)
{
    t->theta += deg * M_PI / 180;
}

int main()
{
    turtle kame = {
        .x=0, .y=0, .theta=0,
    };

    turtle_forward(&kame, 100);
    turtle_left(&kame, 45);
    turtle_forward(&kame, 100);

    printf("kame is at (%f,%f)\n", kame.x, kame.y);
    return 0;
}