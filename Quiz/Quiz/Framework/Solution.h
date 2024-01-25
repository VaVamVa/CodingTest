#pragma once

// https://school.programmers.co.kr/learn/courses/30/lessons/258705
// 산 모양 타일링

/* 점화식
2n + 1 의 도형에 대하여, tops = {0, } 이면,
f(n).
n = 1 : f(1) = 1 + (1 + 1) = 3
n = 2 : f(2) = 1 + (2 + 2) + (2 + 1) <마름모의 갯수&모양 에 따라> = 8
n = 3 : f(3) = 1 + (3 + 3) + (4 + 3 + 2 + 1) + (2 + 1 + 1) = 21
n = 4 : f(4) = 1 + (4 + 4) + (6 + 5 + 4 + 3 + 2 + 1) + (4 + 3 + 3 + 2 + 1 + 1) + (

마지막 점의 위치에 따라...
n = 1 : 2 ~ 1
n = 2 : 1 + 3 + 2 + 1 + 1
n = 3 : 6 ~ 1

f(1) = 3
if (k > 1) f(k) = f(k-1)*3 - (2 * (k - 1) - 1)
*/

int solution(int n, vector<int> tops)
{
    int answer = 0;
    return answer;
}






/////////////////////////////////////////////////////////////////////////
int SolMain()
{
    int n = 0;
    vector<int> tops;

    /*
    n = 2;
    tops = { 0, 1 };

    n = 10;
    tops = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    */

    n = 4;
    tops = { 1, 1, 0, 1 };

    return solution(n, tops);
}