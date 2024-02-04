#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/181829
// 이차원 배열 대각 순회하기

int solution(vector<vector<int>> board, int k) {
    int answer = 0;

    int rowSize = board.size();
    int colSize = board[0].size();

    for (int y = 0; y < rowSize; y++)
    {
        if (y > k) break;
        for (int x = 0; x < colSize; x++)
        {
            if (x + y > k)
                break;
            answer += board[y][x];
        }
    }

    return answer;
}


/////////////////////////////////////////////////////////////////////////
int SolMain()
{
    vector<vector<int>> quest =
    {
        {5, 192, 33, 3},
        {192, 72, 95, 4},
        {33, 95, 999, 5}
    };
    /*
        {19, 498, 258, 587},
        {63, 93, 7, 754}, 
        {258, 7, 1000, 723}, 
        {587, 754, 723, 81},
        {587, 754, 723, 81},
        {587, 754, 723, 81}
        
    */

    return solution(quest, 3);
}