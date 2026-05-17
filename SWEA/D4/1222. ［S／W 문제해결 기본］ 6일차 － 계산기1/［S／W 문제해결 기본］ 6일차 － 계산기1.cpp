#include<iostream>
#include <string>
#include <bitset>
using namespace std;

int main(int argc, char** argv){
	int size;
    
	for(int i = 1; i <= 10; i++){
        string s;
        cin >> size;
        cin >> s;
        string postfix = "";
        int sum = 0;
        for(int j = 0; j < size; j++){
            if(s[j] == '+'){
                postfix += s[++j];
                postfix += '+';
            }else{
                postfix += s[j];
            }
        }

        for(int j = 0; j < size; j++){
            if(postfix[j] != '+'){
                sum += postfix[j] - '0';
            }
        }
        cout << "#" << i << ' ' << sum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}