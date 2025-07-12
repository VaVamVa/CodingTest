#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/120871
// 저주의 숫자 3

int solution(int n) {

    int output = 0, k = 0;
    while (k != n)
    {
        output++;
        if ([](int num) -> bool
            {
                while (num % 10 != 3)
                {
                    num /= 10;
                    if (num == 0)
                        return false;
                }
                return true;
            }(output))
        {
        }
        else if (output % 3 == 0)
        {
        }
        else
        {
            k++;
        }
    }

    return output;
}



////////////////////////////////////////////////////////////////////////////

int SolMain()
{
    int q = 40;


    return solution(q);
}