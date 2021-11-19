#include <stdio.h>
#include <omp.h>

/* Bank account */
typedef struct {
    char* name;    /* name */
    int   balance; /* amount of money deposited */
} Account;

/* Transfers the specified amount of money from sender to receiver */
static void transfer(Account* sender, Account* receiver, int amount)
{
    if (sender->balance < amount) return;
    sender->balance -= amount;
    receiver->balance += amount;
}

int main()
{
    Account alice = {
        .name = "Alice",
        .balance = 1000,
    };
    Account bob = {
        .name = "Bob",
        .balance = 2000,
    };

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            for (int i=0; i<100; i++) {
                #pragma omp critical
                transfer(&alice, &bob, 10); /* Alice sends 10*100 yen to Bob */
            }
        }

        #pragma omp section
        {
            for (int i=0; i<100; i++) {
                #pragma omp critical
                transfer(&bob, &alice, 20); /* Bob sends 20*100 yen to Alice */
            }
        }
    }

    printf("Alice: %d yen, Bob: %d yen\n", alice.balance, bob.balance);
    return 0;
}