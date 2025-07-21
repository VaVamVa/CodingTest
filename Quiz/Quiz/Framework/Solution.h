#pragma once



int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    
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