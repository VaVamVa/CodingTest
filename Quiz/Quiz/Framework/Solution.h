#pragma once

int ToIntAndClear(string& loaded_elem)
{
    int elem = stoi(loaded_elem);
    loaded_elem.clear();
    return elem;
}

vector<int> Result(vector<set<int>*> arr)
{
    vector<int> result;
    set<int>* prevNode = nullptr;
    for (set<int>* elems : arr)
    {
        if (elems == nullptr) break;
        if (!prevNode) result.push_back(*elems->begin());
        else
        {
            for (int elem : *elems)
            {
                if (prevNode->find(elem) == prevNode->end())
                {
                    result.push_back(elem);
                    break;
                }
            }
        }
        prevNode = elems;
    }

    for (set<int>* elems : arr)
    {
        delete elems;
    }

    return result;
}


vector<int> solution(string s) {
    vector<set<int>*> checkArr(500, nullptr);
    set<int>* elems = nullptr;

    string loading_elem = "";

    int tmp_elem = 0;
    int count = 0;
    bool flag = false;
    for (char& digit : s) {
        switch (digit)
        {
        case '{':
            elems = new set<int>;
            count = 0;
            flag = true;
            break;
        case '}':
            if (flag == false) {
                return Result(checkArr);
            }
            flag = false;
            elems->insert(ToIntAndClear(loading_elem));
            checkArr[count] = elems;
            break;
        case ',':
        if (flag)
        {
            count++;
            elems->insert(ToIntAndClear(loading_elem));
        }
            break;
        default:
            if (flag) loading_elem += digit;
            break;
        }
    }
    return {};
}

////////////////////////////////////////////////////////////////////////////

void SolMain()
{
    string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";

    CHECK_1(solution(s));

    return ;
}