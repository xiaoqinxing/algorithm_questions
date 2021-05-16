#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>

using namespace std;

template <typename Container>
void PrintContainer(Container container)
{
    cout << "[ ";
    for (auto i : container)
    {
        cout << i << ' ';
    }
    cout << "]" << endl;
}

#endif