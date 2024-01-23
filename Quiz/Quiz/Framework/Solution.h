#pragma once

void solution();

/////////////////////////////////////////////////////////////////////////
int SolMain()
{
    /*
    "joy", "brad", "alessandro", "conan", "david"
    "alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"

    "a", "b", "c"
    "a b", "b a", "c a", "a c", "a c", "c a"
    */
    vector<string> friends = { "a", "b", "c" };
    vector<string> gifts = { "a b", "b a", "c a", "a c", "a c", "c a" };

    return solution(friends, gifts);
}