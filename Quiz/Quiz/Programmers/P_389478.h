#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/389478?language=cpp
//택배상자

bool compareForTime(int time, int log)
{
    if (time >= log)
        return true;
    if (log / 100 - time / 100 > 2) return false;
    int logMin = log % 100, timeMin = time % 100;
    if (logMin > timeMin)
        return logMin - timeMin <= 10;
    return 60 - logMin - timeMin > 10;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < timelogs[i].size(); j++)
        {
            if ((startday + j & 6) != 6)
            {
                if (!compareForTime(schedules[i], timelogs[i][j]))
                {
                    flag = false;
                    cout << i << " " << j << endl;
                    break;
                }
            }
        }
        if (flag) answer++;
    }
    return answer;
}

/////////////////////////////////////////////////////////////////////////
int SolMain()
{
    vector<int> s = { 730, 855, 700, 720 };
    vector<vector<int>> l = { {710, 700, 650, 735, 700, 931, 912} ,{908, 901, 805, 815, 800, 831, 835},{705, 701, 702, 705, 710, 710, 711}, {707, 731, 859, 913, 934, 931, 905} };
    int start = 1;
    
    return solution(s, l, start);
}