#pragma once

#include <stdio.h>
#include <stdlib.h>

int D(int n)
{
    int result = n;
    while (n != 0)
    {
        result += n % 10;
        n *= 0.1;
    }
    return result;
}

int BSolMain()
{
    int* arr = (int*)calloc(10001, sizeof(int));
    
    int tmp = 0;
    for (int i = 1; i < 10001; ++i)
    {
        tmp = D(i);
        if (tmp <= 10000)
            arr[tmp] = 1;
    }
    for (int i = 1; i < 10001; ++i)
        if (arr[i] != 1)
            printf("%d\n", i);

    free(arr);

    return 0;
}