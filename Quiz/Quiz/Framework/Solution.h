#pragma once

// Ctrl + Click

#define TARGET_R(order, index) points[routes[order][index]][0]
#define TARGET_C(order, index) points[routes[order][index]][1]

#define CUR_R(order) robots[order][0]
#define CUR_C(order) robots[order][1]

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    int maxX = 0, maxY = 0;
    for (int i = 0; i < points.size(); ++i)
    {
        points[i][0]--;
        points[i][1]--;
        maxY = maxY < points[i][0] ? points[i][0] : maxY;
        maxX = maxX < points[i][1] ? points[i][1] : maxX;
    }
    vector<vector<bool>> grid(maxY + 1, vector<bool>(maxX + 1, false));

    //grid 초기화용
    vector<vector<int>> visits(routes.size(), { 0, 0 });
    int uniqueCount = 0;

    //robot의 현재 좌표
    vector<vector<int>> robots(routes.size(), { 0, 0 });

    // 각 robot의 목표 포인트
    vector<int> indices(routes.size(), 1);
    int endPoint = routes[0].size();

    for (int order = 0; order < routes.size(); ++order)
    {
        for (int i = 0; i < endPoint; ++i)
        {
            routes[order][i]--;
            routes[order][i]--;
        }
        robots[order] = { TARGET_R(order, 0), TARGET_C(order, 0) };
    }

    // 종료조건. 모두 endPoint 도달
    int finish = routes.size();
    int count = 0;
    while (count != finish)
    {
        count = 0;
        uniqueCount = 0;
        for (int order = 0; order < routes.size(); ++order)
        {
            // 탈출한 로봇
            if (indices[order] == endPoint)
            {
                count++;
                continue;
            }

            // Next Point 갱신
            if (CUR_R(order) == TARGET_R(order, indices[order])
                && CUR_C(order) == TARGET_C(order, indices[order]))
            {
                indices[order]++;
                if (indices[order] == endPoint)
                {
                    count++;
                    continue;
                }
            }

            // R -> C 우선순위로 증가
            if (CUR_R(order) != TARGET_R(order, indices[order]))
                CUR_R(order) += TARGET_R(order, indices[order]) < CUR_R(order) ? -1 : 1;
            else if (CUR_C(order) != TARGET_C(order, indices[order]))
                CUR_C(order) += TARGET_C(order, indices[order]) < CUR_C(order) ? -1 : 1;
            
            // 방문 좌표 표시
            if (grid[CUR_R(order)][CUR_C(order)])
                answer++;
            else
            {
                uniqueCount++;
                visits[uniqueCount] = { CUR_R(order), CUR_C(order) };
            }
        }
        for (int i = 0; i < uniqueCount; ++i)
        {
            grid[visits[i][0]][visits[i][1]] = false;
        }
    }

    return answer;
}
/// <summary>
/// 
/// </summary>


void ProgrammersMain()
{
    vector<vector<int>> points = { { 3, 2 }, { 6, 4 }, { 4, 7 }, { 1, 4 } };
    vector<vector<int>> routes = { {4, 2} ,{1, 3},{2, 4} };
    solution(points, routes);
}

int BaekjoonMain()
{
    return 0;
}
