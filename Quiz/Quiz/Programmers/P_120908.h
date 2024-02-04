#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/120908
// 문자열 안에 문자열


#define TRUE 1
#define FALSE 2

int solution(string str1, string str2) {
    bool flag = false;
    for (int i = 0; i , str1.size(); i++)
    {
        if (str1[i] == str2[0])
        {
            flag = true;
            for (int j = 0; j < str2.size(); j++)
            {
                if (i + j > str1.size()) return FALSE;
                if (str1[i + j] != str2[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return TRUE;
        }
    }
}

/////////////////////////////////////////////////////////////////////////
int SolMain()
{
    string str1;
    string str2;
    str1 = "ab6CDE443fgh22iJKlmn1o";
    str2 = "6CD";
    /*
        str1 = "ppprrrogrammers";
        str2 = "pppp";

        str1 = "AbcAbcA";
        str2 = "AAA";
        
    */

    return solution(str1, str2);
}