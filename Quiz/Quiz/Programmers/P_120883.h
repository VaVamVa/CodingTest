#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/120883?language=cpp
// ·Î±×ÀÎ

string solution(vector<string> id_pw, vector<vector<string>> db) {
    for (vector<string> elem : db)
        if (id_pw[0].compare(elem[0]) == 0)
        {
            if (id_pw[1].compare(elem[1]) == 0)
                return "login";
            return "wrong pw";
        }

    return "fail";
}

//string solution(vector<string> id_pw, vector<vector<string>> db) {
//
//    map<string, string> MapDb;
//    for (vector<string> elem : db)
//        MapDb.insert({ elem[0], elem[1] });
//
//    map<string, string>::iterator iter = MapDb.find(id_pw[0]);
//    if (iter == MapDb.end())
//        return "fail";
//    else if (iter->second != id_pw[1])
//        return "wrong pw";
//
//    return "login";
//}

/////////////////////////////////////////////////////////////////////////
string SolMain()
{
    vector<string> id_pw = { "progra3mmer01", "15789" };
    
    vector<vector<string>> db = { {"programmer02", "111111"} ,{"programmer00", "134"},{"programmer01", "1145"} };

    /*
    str = "heLLo";
    */

    return solution(id_pw, db);
}