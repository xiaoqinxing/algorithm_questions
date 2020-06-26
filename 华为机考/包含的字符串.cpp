#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char string[100]={0};
	char string_out[100]={0};
	int string_out_len=0;
	bool isfind=false;
	while(cin>>string){
		for(int i=0;i<strlen(string);++i){
			isfind=false;
			for(int j=0;j<string_out_len;++j){
				if(string_out[j] == string[i]){
					isfind=true;
					break;
				}	
			}
			if(false == isfind){
				string_out[string_out_len] = string[i];
				++string_out_len;
			}
		}
		cout << string_out << endl;
		memset(string_out,'\0',sizeof(string_out)*sizeof(char));
		string_out_len=0;
	}
	return 0;
}