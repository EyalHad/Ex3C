#include <stdio.h>
#include "isort.h"

#define LEN 50

int main()
{
    int arr[LEN] = {0};
    int i;
    for (i = 0; i < LEN; i++)
    {
        scanf("%d", arr + i);
    }
    insertion_sort(arr, LEN);

    for (i = 0; i < LEN; i++)
    {
        printf("%d,%s", *(arr + i)," ");
        if(i%10 == 0 && i != 0){
            printf("\n");
        }
    }

    return 0;
}