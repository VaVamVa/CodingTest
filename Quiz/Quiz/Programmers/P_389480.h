#pragma once

// https://school.programmers.co.kr/learn/courses/30/lessons/389480

#define F static_cast<float>

struct ForMyOrder
{
    bool operator () (const pair<int,int>& l, const pair<int, int>& r) const
    {
        float LFactor = F(l.first) / F(l.second);
        float RFactor = F(r.first) / F(r.second);
        if (LFactor == RFactor)
            return l.second > r.second;
        return LFactor > RFactor;
    }
};


int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    map<pair<int/*A*/, int/*B*/>, int/*index*/, ForMyOrder> comPair;
    
    pair<int, int> p;
    for (int i = 0; i < info.size(); i++)
    {
        p = { info[i][0], info[i][1] };
        comPair[p]++;
    }

    map<pair<int, int>, int, ForMyOrder>::iterator iter;

    for (iter = comPair.begin(); iter != comPair.end(); iter++)
    {
        int a = iter->first.first, b = iter->first.second;
        for (int i = 0; i < iter->second; i++)
        {
            if (m - b > 0)
                m -= b;
            else if (n - a > 0)
            {
                n -= a;
                answer += a;
            }
            else
                return -1;
        }
    }

    return answer;
}

////////////////////////////////////////////////////////////////////////////

void SolMain()
{
    vector<vector<int>> info;
    info = { {1, 2}, {2, 3}, {2, 1} };
    //info = { { 3, 3 }, { 3, 3 } };

    int n, m;
    n = 4, m = 4;
    //n = 7, m = 1;
    //n = 6;

    CHECK(solution(info, n, m));

    return ;
}