#pragma once

template <typename T>
void PrintData(T result)
{
    cout << result << endl;
}

template <typename T>
void PrintDatas(T& result)
{
    for (auto elem : result)
        cout << elem << " ";
    cout << endl;
}

template <typename T>
void PrintDatasTwice(T& result)
{
    for (auto elems : result)
    {
        for (auto elem : elems)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;
}

template <typename T>
void PrintArrayData(T* result, int size)
{
    if (size < 0) return;
    for (int i = 0; i < size; i++)
    {
        cout << *(result + sizeof(T) * i) << " ";
    }
    cout << endl;
}