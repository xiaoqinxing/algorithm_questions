#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int max_element_in_score(int *score, int a, int b){
    int max;
    if(a>b){
        max = a;
        a=b;
        b =max;
    }
    max = score[a-1];
    for(int i=a-1;i<b;i++){
        if(max<score[i]){
            max = score[i];
        }
    }
    return max;
}
int main1(){
    int N,M,A,B;
    char C;
    int input;
    while(cin >> N >> M){
        int *score = new int[N];
        for (int i=0;i<N;i++){
            cin >> score[i];
        }
        for(int i=0;i<M;i++){
            cin >> C >> A >> B;
            if(C == 'Q'){
                cout << max_element_in_score(score,A,B) <<endl;
            }
            else if(C == 'U'){
                score[A-1] = B;
            }
        }
    }
    return 0;
}

int main(){
    int N,M,A,B,tmp1,tmp2;
    char C;
    int input;
    cin >> N >> M;
    vector<int> score;
    vector<int>::iterator score_it=score.begin();
    for (int i=0;i<N;i++){
        cin >> input;
        score.push_back(input);
    }
    for(int i=0;i<M;i++){
        cin >> C >> A >> B;
        if(C == 'Q'){
            tmp1 = A-1;
            tmp2 = B-1;
            tmp2 = *max_element(score.begin()+A-1,score.begin()+B-1);
            cout << tmp2 << endl;
        }
        else if(C == 'U'){
            *(score.begin()+(A-1)) = B;
        }
    }
    return 0;
}
//注意max_element返回的是迭代器
//注意只有vector和deque的迭代器可以随机访问，list只可以双向访问，也就是*，++,--