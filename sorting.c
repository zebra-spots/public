#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_VALUES 5
//prototype for qsort's comparitor
int comparitor(const void *, const void *);
int comparitor2(const void *, const void *);

int main()
{
    //Unsorted data and loop to print the data
    int values[] = {10,30,20,-15,45};
    float values2[] = {10.0,0.20,21.0,-15.0,45.0};

    puts("Values before sorting...\n");
    for (int i=0; i<SIZE_OF_VALUES; i++)
    {
        printf("%d \n", values[i]);
    }
    puts("Float values before sorting...\n");
    for (int i=0; i<SIZE_OF_VALUES; i++)
    {
        printf("%.2f \n", values2[i]);
    }

    //sort the data
    qsort(values, SIZE_OF_VALUES, sizeof(int), comparitor);
    qsort(values2, SIZE_OF_VALUES, sizeof(float), comparitor);
    //qsort(values, sizeof(values), sizeof(int), comparitor); //WORKING ON THIS


    //Sorted data... and loop to print the data
    puts("\nValues after sorting...\n");
    for (int i=0; i<SIZE_OF_VALUES; i++)
    {
        printf("%d \n", values[i]);
    }
    puts("\nFloat values after sorting...\n");
    for (int i=0; i<SIZE_OF_VALUES; i++)
    {
        printf("%.2f \n", values2[i]);
    }

    return 0;
}

int comparitor(const void *num1, const void *num2)
{
    return (*(int*)num1 - *(int*)num2);
    //Takes 2 void pointers, casts them to an int pointer, dereferences them and then subtracts one from the other and returns the result
    //qsort will use that returned value to compare the two numbers
}
int comparitor2(const void *num1, const void *num2)
{
    float n1 = *(float*)num1;
    float n2 = *(float*)num2;

    if (n1 == n2)
    {
        return 0;
    }
    if (n1 < n2)
    {
        return 1;
    }

    return -1;


    //sorting negative numbers incorrectly (if 0.21 is before -15.0 it sorts it correctly. If 21.0 it sorts it wrong.
}
