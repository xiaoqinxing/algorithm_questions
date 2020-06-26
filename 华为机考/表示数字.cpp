#include <iostream>
#include <string>
using namespace std;
bool judge_char(char a){
    if(a >= '0'&& a <= '9')
        return true;
    else
        return false;
}
int main(){
    string str;
    while(cin >> str){
        int len = str.size();
        int i=0;
        if(judge_char(str[0]) == true){
            str.insert(0,"*");
            i=1;
        }
        if(judge_char(str[str.size()-1]) == true){
            str.insert(str.size(),"*");
        }

        while(i<(str.size()-1)){
            if(judge_char(str[i])==false && judge_char(str[i+1]) == true){
                str.insert(i+1,"*");
                i++;
            }
            else if(judge_char(str[i])==true && judge_char(str[i+1]) == false){
                str.insert(i+1,"*");
                i++;
            }
            i++;
        }
        if(str[str.size()-1] == '*')
            str.erase(str.size()-1);
        cout << str <<endl;
    }
    return 0;
}