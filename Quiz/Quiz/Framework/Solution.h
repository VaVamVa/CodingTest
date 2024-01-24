#pragma once

int solution(int n, vector<vector<int>> wires)
{
    // 자신의 총 하위 노드의 수를 value로 가지는 int 배열 생성
    vector<int> tower(n, 0);

    // 1. 각 value와 root node의 차가 해당 value와 가장 적은 차이를 나타내는 노드의 직전에서 끊으면 해결.
    // 2. tower의 0번을 첫 node를 rootnode로 하여
    // 3. 각 subtree의 하위 노드 갯수 tower 배열에 넣기
    
    map<int, vector<int>> children;

    for (int i = 0; i < n; i++)
    {
        children[wires[i][0] - 1].push_back(wires[i][1]);
    }

    // 순회 시작. 올라갈때 count 1씩 더하며 해당 node에 할당

    vector<int> stack;
    int node = 0;
    stack.push_back(0);
    while (stack.size() > 0)
    {
        if (children[node].size() == 1)
        {
            tower[node] = 1;
            int backNode = stack.back();
            stack.push_back(node);
            node = backNode;
        }
        else if (children[node][stack.back()] > 0)
        {
            stack.pop_back();
            node = stack.back();
        }
        else
        {
            for (int i = 0; i < children[node].size(); i++)
            {
                tower[node] += tower[stack.back()];
                stack.pop_back();
            }
            node = stack.back();
        }
    }
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