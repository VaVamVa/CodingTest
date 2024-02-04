#pragma once

// https://school.programmers.co.kr/learn/courses/30/lessons/181832
// 정수를 나선형으로 배치하기

vector<vector<int>> solution(int n) {
    vector<vector<int>> table;
    
    vector<int> aLine(n, 0);
    table.assign(n, aLine);

    enum D
    {
        RIGHT = 0,
        DOWN,
        LEFT, 
        UP
    };

    int num = 1;
    int direction = 0;
    int x = 0, y = 0;

    while (num <= n * n)
    {
        if (x < n && y < n && x >= 0 && y >= 0 && table[y][x] == 0)
        {
            table[y][x] = num;
            num++;
            switch (direction)
            {
            case RIGHT:
                x++;
                break;
            case DOWN:
                y++;
                break;
            case LEFT:
                x--;
                break;
            case UP:
                y--;
                break;
            }
        }
        else
        {
            switch (direction)
            {
            case RIGHT:
                x--;
                break;
            case DOWN:
                y--;
                break;
            case LEFT:
                x++;
                break;
            case UP:
                y++;
                break;
            }

            direction++;
            direction %= 4;

            switch (direction)
            {
            case RIGHT:
                x++;
                break;
            case DOWN:
                y++;
                break;
            case LEFT:
                x--;
                break;
            case UP:
                y--;
                break;
            }
        }
        
    }


    return table;
}






/////////////////////////////////////////////////////////////////////////
vector<vector<int>> SolMain()
{
    int n = 4;
    n = 5;

    return solution(n);
}