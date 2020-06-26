// 题目描述 

//    Redraiment是走梅花桩的高手。Redraiment总是起点不限，从前到后，往高的桩子走，但走的步数最多，不知道为什么？你能替Redraiment研究他最多走的步数吗？ 

// 样例输入
// 6

// 2 5 1 5 4 5

// 样例输出

// 3

// 提示

// Example: 
// 6个点的高度各为 2 5 1 5 4 5 
// 如从第1格开始走,最多为3步, 2 4 5 
// 从第2格开始走,最多只有1步,5 
// 而从第3格开始走最多有3步,1 4 5 
// 从第5格开始走最多有2步,4 5

// 所以这个结果是3。
#include <iostream>
using namespace std;
int steps_in_array(int* a, int start_index,int num){
    int max = a[start_index];
    int ret = 1;
    for(int i=start_index+1;i<num;i++){
        if(max < a[i]){
            max = a[i];
            ++ret;
        }
    }
    return ret;
}
int main(){
    int num;
    int max_steps=0,steps;
    while(cin >> num){
        //input
        int* array = new int[num];
        for(int i=0;i<num;i++){
            cin >> array[i];
        }
        //process
        for(int i=0;i<num;i++){
            steps = steps_in_array(array,i,num);
            if(max_steps < steps)
                max_steps = steps;
        }
        //out
        cout << max_steps <<endl;
        delete array;
    }
}
//最长上升子序列
//动态规划