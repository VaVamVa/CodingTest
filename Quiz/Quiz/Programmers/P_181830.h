#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/181830
// 정사각형으로 만들기

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer = arr;

    int rowSize = arr.size();
    int colSize = arr[0].size();

    if (rowSize > colSize)
    {
        for (int y = 0; y < rowSize; y++)
            for (int x = 0; x < rowSize - colSize; x++)
                answer[y].push_back(0);
    }
    else
        for (int i = 0; i < colSize - rowSize; i++)
        {
            vector<int> padding(colSize, 0);
            answer.push_back(padding);
        }

    return answer;
}

/////////////////////////////////////////////////////////////////////////
vector<vector<int>> SolMain()
{
    vector<vector<int>> quest =
    {
        {19, 498, 258, 587},
        {63, 93, 7, 754}, 
        {258, 7, 1000, 723}, 
        {587, 754, 723, 81},
        {587, 754, 723, 81},
        {587, 754, 723, 81}
    };
    /*
        {5, 192, 33, 3},
        {192, 72, 95, 4},
        {33, 95, 999, 5}
        
    */

    return solution(quest);
}