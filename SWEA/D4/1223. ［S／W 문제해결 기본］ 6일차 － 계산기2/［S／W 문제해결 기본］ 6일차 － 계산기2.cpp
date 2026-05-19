#include<iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i <= 10; i++){
        int n;
        string s;
        cin >> n >> s;
        string postfix = "";
        for(int j = 0; j < n; j++){
            if(s[j] == '+'){
                postfix += s[++j];
                while(s[++j] == '*'){
                    postfix += s[++j];
                    postfix += '*';
                }
                
                postfix+= '+';
                j--;
            }else{
                if(s[j] == '*'){
                    postfix += s[++j];
                    postfix += '*';
                }else{
                    postfix += s[j];     
                }
                
            }
        }

        // for(int j = 0; j < n; j++){
        //     cout << postfix[j];
        // }
        // cout << endl;
        // cout << endl;
        stack<int> st;
        for(int j = 0; j < n; j++){
            if(postfix[j] == '+' || postfix[j] == '*'){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(postfix[j] == '+'){
                    st.push(a+b);
                }else{
                    st.push(a*b);
                }
                
            }else{
                st.push(postfix[j] - '0');
            }
        }
        int answer = st.top();
        cout << '#' << i << ' ' << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}