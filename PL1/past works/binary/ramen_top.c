#include <stdio.h>

typedef enum {
    Shoyu, Miso, Shio, Tonkotsu
} Flavor;

typedef struct {
    Flavor flavor;
    int large;
    int nori;
    int egg;
    int pork;
    int onion;
} Ramen;

int ramen_price(Ramen* a)
{
    int price = 0;
    if (a->flavor == Miso) price += 700;
    else price += 650;
    if (a->large) price += 100;
    if (a->nori) price += 50;
    if (a->egg) price += 50;
    if (a->pork) price += 150;
    if (a->onion) price += 50;
    printf("%d\n", price);
    return price;
}

int main(){
    Ramen A = {
        .flavor = Shoyu,
        .large = 0,
        .nori = 1,
        .egg = 0,
        .pork = 0,
        .onion = 0,
    };
    ramen_price(&A);
    return 0;
}