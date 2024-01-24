#pragma once

int solution(int n, vector<vector<int>> wires)
{
    // �ڽ��� �� ���� ����� ���� value�� ������ int �迭 ����
    vector<int> tower(n, 0);

    // 1. �� value�� root node�� ���� �ش� value�� ���� ���� ���̸� ��Ÿ���� ����� �������� ������ �ذ�.
    // 2. tower�� 0���� ù node�� rootnode�� �Ͽ�
    // 3. �� subtree�� ���� ��� ���� tower �迭�� �ֱ�
    
    map<int, vector<int>> children;

    for (int i = 0; i < n; i++)
    {
        children[wires[i][0] - 1].push_back(wires[i][1]);
    }

    // ��ȸ ����. �ö󰥶� count 1�� ���ϸ� �ش� node�� �Ҵ�

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