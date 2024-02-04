#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/120909
// 제곱수 판별하기


#define TRUE 1
#define FALSE 2

int solution(int n) {
    if (n == 1) return TRUE;
    else if (n < 4) return FALSE;
    for (int i = 2; i * i <= n; i++)
    {
        if (i * i == n)
            return TRUE;
    }
    return FALSE;
}

/////////////////////////////////////////////////////////////////////////
int SolMain()
{
    int n = 144;
    
    /*
    n = 976;
    */

    return solution(n);
}