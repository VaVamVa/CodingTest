#pragma once

// https://school.programmers.co.kr/learn/courses/30/lessons/12946
// 하노이의 탑

// https://ko.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/a/towers-of-hanoi
// https://ko.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/a/towers-of-hanoi-continued

void hanoi(int source, int destination, int intersection, int n, vector<vector<int>>& container)
{
    if (n == 1)
        container.push_back({ source, destination });
    else
    {
        hanoi(source, intersection, destination, n - 1, container);
        hanoi(source, destination, intersection, 1, container);
        hanoi(intersection, destination, source, n - 1, container);
        
    }
}


vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;

    hanoi(1, 3, 2, n, answer);

    return answer;
}








/////////////////////////////////////////////////////////////////////////
vector<vector<int>> SolMain()
{
    int n = 2;

    return solution(n);
}