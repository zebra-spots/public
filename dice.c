#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum { die_size = 6};
int main(void)
{
    int die_1st;
    int die_2nd;
    int die_3rd;
    time_t now = time(0);               //Uses the time as a seed
    srand((unsigned int)now);           //Casts the time to an unseeded integer
    do
    {
        die_1st = rand() % die_size + 1;
        die_2nd = rand() % die_size + 1;
        die_3rd = rand() % die_size + 1;
        //printf("Roll:\n Die 1 = %d\n Die 2 = %d\n", die_1st, die_2nd);
        printf("Roll:\n Die 1 = %d\n Die 2 = %d\n Die 3 = %d\n", die_1st, die_2nd, die_3rd);
        if (die_1st == die_2nd)
        {
            puts("\nReroll!\n");
        }
    }
    while (die_1st == die_2nd);         //This will re-roll the dice if 1 and 2 match

    return 0;
}
