#pragma once

// https://school.programmers.co.kr/learn/courses/30/lessons/181831
// 특별한 이차원 배열

#define TRUE 1
#define FALSE 0

int solution(vector<vector<int>> arr) {
    int n = 0;
    while (n < arr.size())
    {
        for (int i = n; i < arr.size() - n; i++)
        {
            if (arr[n][i] != arr[i][n])
                return FALSE;
        }
        n++;
    }
    return TRUE;
}



/////////////////////////////////////////////////////////////////////////
int SolMain()
{
    vector<vector<int>> quest =
    {
        {5, 192, 33},
        {192, 72, 95},
        {33, 95, 999}
    };
    /*
        {19, 498, 258, 587},
        {63, 93, 7, 754}, 
        {258, 7, 1000, 723}, 
        {587, 754, 723, 81}
    */

    return solution(quest);
}