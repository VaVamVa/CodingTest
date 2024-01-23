#pragma once

// https://school.programmers.co.kr/learn/courses/30/lessons/258712

void MakeContainer(vector<string> friends, unordered_map<string, int>& container)
{
    for (int i = 0; i < friends.size(); i++)
    {
        container[friends[i]] = i;
    }
}

vector<string> StringParser(string input)
{
    vector<string> parsingResult(2);
    int index = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ')
            index++;
        else
            parsingResult[index] += input[i];
    }

    return parsingResult;
}

int solution(vector<string> friends, vector<string> gifts)
{
    unordered_map<string, int> keyNameTable;

    MakeContainer(friends, keyNameTable);

    vector<vector<int>> graph(friends.size());
    
    for (int i = 0; i < friends.size(); i++)
    {
        vector<int> temp(friends.size(), 0);
        graph[i] = temp;
    }

    vector<string> giverAndReceiver(2);
    string giver = "";
    string receiver = "";
    for (string aLine : gifts)
    {
        giverAndReceiver = StringParser(aLine);
        giver = giverAndReceiver[0];
        receiver = giverAndReceiver[1];
        graph[keyNameTable[giver]][keyNameTable[receiver]]++;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        int score = 0;
        for (int j = 0; j < friends.size(); j++)
        {
            score += graph[i][j] - graph[j][i];
        }
        graph[i][i] = score;
    }


    int maxCount = 0;

    for (int i = 0; i < friends.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < friends.size(); j++)
        {
            if (graph[i][j] > graph[j][i])
                count++;
            else if (graph[i][j] == graph[j][i] && graph[i][i] > graph[j][j])
                count++;
        }
        if (maxCount < count)
            maxCount = count;
    }

    return maxCount;
}


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