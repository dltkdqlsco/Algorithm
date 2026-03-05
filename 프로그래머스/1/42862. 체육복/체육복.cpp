#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int clothes[n];
    
    for(int i = 0; i < n; i++) clothes[i] = 1;

    for(int i : lost) clothes[i-1]--;

    for(int i : reserve) clothes[i-1]++;

     for(int i = 0; i < n; i++){
         if(clothes[i] == 0){
             if(i > 0 && clothes[i-1] > 1){
                 clothes[i]++;
                 clothes[i - 1]--;
             }else if(i < n-1 && clothes[i+1] > 1){
                 clothes[i]++;
                 clothes[i + 1]--;
             }
         }
     }
    
    for(int i : clothes){
        if(i != 0) answer++;
    }
    return answer;
}