#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/120911
// ¼¼±Õ Áõ½Ä

string solution(string my_string) {
    string answer = "";
    vector<int> order(26, 0);

    int index;
    for (char c : my_string)
    {
        index = c < 'a' ? c - 'A' : c - 'a';
        order[index]++;
    }

    for (int i = 0; i < order.size(); i++)
    {
        for (int count = 0; count < order[i]; count++)
            answer += 'a' + i;
    }

    return answer;
}

/////////////////////////////////////////////////////////////////////////
string SolMain()
{
    string str = "Bcad";
    
    /*
    str = "heLLo";
    */

    return solution(str);
}