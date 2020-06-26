// 现在IPV4下用一个32位无符号整数来表示，一般用点分方式来显示，点将IP地址分成4个部分，每个部分为8位，表示成一个无符号整数（因此不需要用正号出现），如10.137.17.1，是我们非常熟悉的IP地址，一个IP地址串中没有空格出现（因为要表示成一个32数字）。

// 现在需要你用程序来判断IP是否合法。
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ip[4] = {0};
    char ch[3];
    while (cin >> ip[0] >> ch[0] >> ip[1] >> ch[1] >> ip[2] >> ch[2] >> ip[3])
    {
        if (ch[0] == '.' && ch[1] == '.' && ch[2] == '.')
        {
            if ((ip[0] >= 0 && ip[0] <= 255) && (ip[1] >= 0 && ip[1] <= 255) && (ip[2] >= 0 && ip[2] <= 255) && (ip[3] >= 0 && ip[3] <= 255))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}