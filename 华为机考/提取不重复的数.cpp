#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    string str;
    set<char> diff_char;
    while (cin >> str)
    {
        diff_char.clear();
        reverse(str.begin(), str.end());
        for (int i = 0; i < str.size(); i++)
        {
            if (diff_char.find(str[i]) != diff_char.end())
            {
                str.erase(i, 1);
                --i;
            }
            else
            {
                diff_char.insert(str[i]);
            }
            cout << str << endl;
        }
        cout << str << endl;
    }
    return 0;
}