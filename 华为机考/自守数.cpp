//自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n以内的自守数的个数
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main1(){
    int n,num;
    string squr,n_s;
    bool isOK=true;
    while(cin >> n){
        num = 0;
        for(int i=0;i<n;i++){
            n_s = to_string(i);
            squr = to_string(i*i);
            string::reverse_iterator rit = n_s.rbegin();
            string::reverse_iterator squrit = squr.rbegin();
            isOK=true;
            for(;rit!=n_s.rend();++rit){
                if(*rit != *squrit){
                    isOK = false;
                    break;
                }
                ++squrit;
            }
            if(isOK == true){
                ++num;
            }
        }
        cout << num <<endl;
    }
    return 0;
}
int main()
{
    long n;
    while(cin>>n){
        int ans = 2;// 0, 1也是
        for(long i = 3; i<=n; i++){
            long n2 = i*i;
            string s1 = to_string(i);
            string s2 = to_string(n2);
            int pos = s2.size()- s1.size();
            if(s2.find(s1,pos) != s2.npos)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

//数字转字符串 a = to_string(str)
//字符串转数字 str = stoi(a)
//如果找到字符串：s2.find(s1,pos) != s2.npos
//其实思路很简单，只要平方减去数本身然后没%以一下，如果是0就ok