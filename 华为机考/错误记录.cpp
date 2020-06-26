#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool isBigger(const pair<string,pair<int,int> > &a, const pair<string,pair<int,int> > &b){
    if(a.second.first > b.second.first)
        return true;
    else if(a.second.first == b.second.first){
        if(a.second.second < b.second.second)
            return true;
    }
    return false;
}
int main(){
    string str;
    string filename;
    int index;
    int show_line=0;
    int len;
    map<string,pair<int,int> > fileRecorder;
    map<string,pair<int,int> >::iterator fileRecorder_it;
    while(getline(cin,str)){
        show_line++;
        index = str.find_last_of('\\');
        filename = str.substr(index+1);
        fileRecorder_it=fileRecorder.find(filename);
        //找找看map中有没有，如果有的话，数量就加1，没有的话，新增一个，并记录第一次出现的行号。
        if(fileRecorder_it!=fileRecorder.end()){
            fileRecorder_it->second.first += 1;
        }
        else{
            //fileRecorder.insert(make_pair(filename,make_pair(0,show_line)));
            fileRecorder.insert(make_pair(filename, make_pair(1,show_line)));
        }
    }
    vector<pair<string,pair<int,int> > > vec(fileRecorder.begin(),fileRecorder.end());
    sort(vec.begin(),vec.end(),isBigger);
    len = vec.size()>=8? 8:vec.size();
    for(int i=0;i<len;++i){
        index = vec[i].first.find_first_of(' ');
        if(index > 16)
            filename = vec[i].first.substr(index - 16);
        else
            filename = vec[i].first;
        cout << filename << ' ' << vec[i].second.first << endl;
    }
    return 0;
}
//如果要对map中的value进行排序，需要将map中的内容放到venctor中。注意vector的定义一定要是pair的， 因为它只接受一个类！！！
//注意sort中的compare函数，参数一定要是容器的值