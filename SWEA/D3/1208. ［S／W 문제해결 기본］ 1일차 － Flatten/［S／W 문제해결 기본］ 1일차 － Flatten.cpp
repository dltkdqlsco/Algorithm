#include <iostream>
#include <queue>


using namespace std;

int main(int argc, char **argv) {

    for(int i = 1; i <= 10; ++i){
        int n; // 덤프 횟수
        cin >> n;
        priority_queue<int, vector<int>,  greater<int>> sq;  // 최소힙
        priority_queue<int, vector<int>> gq;  // 최대힙
        for(int j = 0; j < 100; ++j){
            int value;
            cin >> value;
            sq.push(value);
            gq.push(value);
        }
        
        for(int j = 0; j < n; ++j){
            int sNum = sq.top();
            sq.pop();
            int gNum = gq.top();
            gq.pop();
            // cout << "#" << j << ' ' << sNum << endl;
            // cout << "#" << j << ' ' << gNum << endl;
            if((gNum - sNum) > 1){
                sq.push(++sNum);
                gq.push(--gNum);
            }
            
        }

        int sNum = sq.top();
        int gNum = gq.top();
        cout << "#" << i << ' ' << gNum - sNum << endl;
    }
    
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}