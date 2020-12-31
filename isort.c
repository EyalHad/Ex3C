#include <stdio.h>
#include "isort.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shift_element(int *arr, int i)
{
    int k;
    for (k = 0; k != i - 1; k++)
    {
        *(arr + k) = *(arr + k + 1);
    }
}

void insertion_sort(int *arr, int len)
{
    int i, j, a;
    for (i = 1; i < len; i++)
    {
        a = *(arr + i);
        j = i - 1;
        while ((j >= 0) && (a < *(arr + j)))
        {
            *(arr + j + 1) = *(arr + j);
            --j;
        }
        *(arr + j + 1) = a;
    }
}
