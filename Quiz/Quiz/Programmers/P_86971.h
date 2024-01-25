#pragma once

// https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=cpp
// ���¸��� �ѷ� ������

#define INT_INF 2147483647

int solution(int n, vector<vector<int>> wires)
{
    // �ڽ��� �� ���� ����� ���� value�� ������ int �迭 ����
    vector<int> tower(n, 0);

    // 1. �� value�� root node�� ���� �ش� value�� ���� ���� ���̸� ��Ÿ���� ����� �������� ������ �ذ�.
    // 2. tower�� 0���� ù node�� rootnode�� �Ͽ�
    // 3. �� subtree�� ���� ��� ���� tower �迭�� �ֱ�
    
    vector<vector<bool>> children(n, vector<bool>(n, false));

    //for (int i = 0; i < n; i++)
    //    children[i] = vector<int>();
    for (int i = 0; i < wires.size(); i++)
    {
        children[wires[i][0] - 1][wires[i][1] - 1] = true;
        children[wires[i][1] - 1][wires[i][0] - 1] = true;
    }

    // ��ȸ ����. �ö󰥶� count 1�� ���ϸ� �ش� node�� �Ҵ�

    vector<int> nodeStack;
    int curNode = 0;
    int parentNode = -1;
    nodeStack.push_back(0);

    // �� node�� ������� children[node].size() ��ŭ order ������.
    // order�� size�� �������� �ڽĳ�� ��� ���ϰ� parent�� ���ƿ���.
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
    int n;  // ����ž ����
    vector<vector<int>> wires;  // size = n - 1 �� ���� ���� ���赵
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