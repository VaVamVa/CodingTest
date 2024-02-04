#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/120910
// ¼¼±Õ Áõ½Ä

/*
int solution(int n, int t)
{
    for (int i = 0; i < t; i++)
        n *= 2;
    return n;
}
*/

int solution(int n, int t) {
    return n << t;
}

/////////////////////////////////////////////////////////////////////////
int SolMain()
{
    int n = 2;
    int t = 10;
    
    /*
    n = 7;
    t = 15;
    */

    return solution(n, t);
}