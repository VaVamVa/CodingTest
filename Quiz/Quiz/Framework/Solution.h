#pragma once

//https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=7-day-campaign
//anagram

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

#define N_INF -2147483648
#define INF 2147483647

struct RoundResult
{
    RoundResult(int max, vector<int> result)
    : max(max), result(result) {}

    int max = -1;
    int minPoint = 11;
    int minPointCount = 0;
    vector<int> result = vector<int>(11,0);
};

RoundResult Counting(int startPoint, int shootCount, int apeachScore, vector<int> apeachInfo);

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11, 0);

    int apeach = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (info[i] > 0)
        {
            apeach += 10 - i;
        }
    }
    if (apeach == 55 - (0.5 * (10 - n) * (10 - n + 1)))
    {
        return { -1 };
    }

    int max = N_INF;
    int minPoint = 11;
    int minPointCount = 0;
    for (int i = 0; i < 11; ++i)
    {
        RoundResult Case = Counting(i, n, apeach, info);

    }



    return answer;
}


RoundResult Counting(int startPoint, int shootCount, int apeachScore, vector<int> apeachInfo)
{

}

////////////////////////////////////////////////////////////////////////////

void SolMain()
{
    CHECK_1(solution(5, { 2,1,1,1,0,0,0,0,0,0,0 }));

    return ;
}