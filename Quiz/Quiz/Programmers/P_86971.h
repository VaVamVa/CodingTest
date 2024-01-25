#pragma once

// https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=cpp
// 전력망을 둘로 나누기

#define INT_INF 2147483647

int solution(int n, vector<vector<int>> wires)
{
    // 자신의 총 하위 노드의 수를 value로 가지는 int 배열 생성
    vector<int> tower(n, 0);

    // 1. 각 value와 root node의 차가 해당 value와 가장 적은 차이를 나타내는 노드의 직전에서 끊으면 해결.
    // 2. tower의 0번을 첫 node를 rootnode로 하여
    // 3. 각 subtree의 하위 노드 갯수 tower 배열에 넣기
    
    vector<vector<bool>> children(n, vector<bool>(n, false));

    //for (int i = 0; i < n; i++)
    //    children[i] = vector<int>();
    for (int i = 0; i < wires.size(); i++)
    {
        children[wires[i][0] - 1][wires[i][1] - 1] = true;
        children[wires[i][1] - 1][wires[i][0] - 1] = true;
    }

    // 순회 시작. 올라갈때 count 1씩 더하며 해당 node에 할당

    vector<int> nodeStack;
    int curNode = 0;
    int parentNode = -1;
    nodeStack.push_back(0);

    // 한 node를 잡았으면 children[node].size() 만큼 order 돌리기.
    // order이 size와 같아지면 자식노드 모두 더하고 parent로 돌아오기.
    while (nodeStack.size() > 0)
    {
        curNode = nodeStack.back();
            
        bool flag = true;
        int leafFlag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (parentNode == i)
                continue;
            else if (children[curNode][i] == true)
            {
                if (tower[i] == 0)
                {
                    parentNode = curNode;
                    nodeStack.push_back(i);
                    flag = false;
                    break;
                }
                else
                    continue;
            }
            else
                leafFlag++;
        }
        if (leafFlag == n - 1 && parentNode != -1)
        {
            tower[curNode] = 1;
            nodeStack.pop_back();
            if (nodeStack.size() > 1) parentNode = nodeStack[nodeStack.size() - 2];
            else parentNode = -1;
        }
        else if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                if (children[curNode][i] == true)
                    tower[curNode] += tower[i];
            }
            tower[curNode]++;
            nodeStack.pop_back();
            if (nodeStack.size() > 1) parentNode = nodeStack[nodeStack.size() - 2];
            else
                parentNode = -1;
        }
    }

    int resultValue = INT_INF;
    int resultNode = 0;
    for (int i = 1; i < tower.size(); i++)
    {
        int comparing = abs(tower[0] - tower[i] - tower[i]);
        if (comparing < resultValue)
        {
            resultValue = comparing;
            resultNode = i;
        }
    }

    return resultValue;
}













/////////////////////////////////////////////////////////////////////////
int SolMain()
{
    int n;  // 송전탑 갯수
    vector<vector<int>> wires;  // size = n - 1 인 전선 연결 관계도
    /*
    n = 4;
    wires = { {1, 2}, {2, 3}, {3, 4} };

    n = 7;
    wires = { {1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7} };

    */
    n = 9;
    wires = { {1,3}, {2,3}, {3,4}, {4,5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };

    return solution(n, wires);
}