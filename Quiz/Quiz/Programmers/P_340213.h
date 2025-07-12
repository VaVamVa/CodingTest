#pragma once

//https://school.programmers.co.kr/learn/courses/30/lessons/340213?language=cpp
// 동영상 재생기


int ConvertMinToSec(string strTime)
{
    int result = (strTime[0] - '0') * 600 + (strTime[1] - '0') * 60 + (strTime[3] - '0') * 10 + (strTime[4] - '0');
    return result;
}

string ConvertSecToMin(int intTime)
{
    string result = "";
    result += to_string(intTime / 600);
    intTime %= 600;
    result += to_string(intTime / 60);
    intTime %= 60;

    result += ":";

    result += to_string(intTime / 10);
    intTime %= 10;
    result += to_string(intTime);
    return result;
}

struct ConvInfo
{
    ConvInfo(string video_len, string present_pos, string op_start, string op_end)
    {
        len = ConvertMinToSec(video_len);
        pos = ConvertMinToSec(present_pos);
        op_s = ConvertMinToSec(op_start);
        op_e = ConvertMinToSec(op_end);
    }

    ConvInfo() :len(0), pos(0), op_s(0), op_e(0)
    {}

    int len;
    int pos;
    int op_s;
    int op_e;
};

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {

    ConvInfo info(video_len, pos, op_start, op_end);
    
    for (string command : commands)
    {
        if (info.pos >= info.op_s && info.pos < info.op_e)
            info.pos = info.op_e;

        if (command[0] == 'n')
        {
            info.pos += 10;

            if (info.pos > info.len)
                info.pos = info.len;
        }
        else
        {
            info.pos -= 10;

            if (info.pos < 0)
                info.pos = 0;
        }
    }

    if (info.pos >= info.op_s && info.pos < info.op_e)
        info.pos = info.op_e;

    return ConvertSecToMin(info.pos);
}

string SolMain()
{
    string video_len = "30:00";
    string pos = "01:05";
    string op_start = "01:00";
    string op_end = "01:30";
    vector<string> commands = { "prev" };


    return solution(video_len,
        pos,
        op_start,
        op_end,
        commands
    );
}