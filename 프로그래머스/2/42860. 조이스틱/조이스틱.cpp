#include <string>
#include <vector>

using namespace std;

int getUpDownCount(char c){
    return min(c - 'A', 'Z' - c + 1);
}

int solution(string name) {
    int answer = 0;
    int size = name.size();
    int minMove = size - 1;
    
    for(int i = 0; i < size; i++){
        answer += getUpDownCount(name[i]);
        
        int next = i + 1;
        while(next < size && name[next] == 'A'){
            next++;
        }
        
        // 1. 오른쪽으로 갔다가 왼쪽으로 꺾기
        // 이동 경로: 시작점(0) → i까지 이동 → 다시 시작점(0)으로 후진 → 맨 뒤에서부터 next까지 이동
        // 거리 계산: i (오른쪽 이동) + i (다시 0으로 후진) + (n - next) (뒤에서부터 이동)
        // 결과: 2 * i + n - next
        
        // 2. 왼쪽으로 먼저 갔다가 오른쪽으로 꺾기
        // 이동 경로: 시작점(0) → 맨 뒤에서부터 next까지 이동 → 다시 시작점(0)으로 전진 → i까지 이동
        // 거리 계산: (n - next) (왼쪽 이동) + (n - next) (다시 0으로 전진) + i (오른쪽으로 이동)
        // 결과: 2 * (n - next) + i
        
        // 왜 min(i, n - next)를 더하나요?
        // 위의 두 식(2i + (n-next)와 2(n-next) + i)을 공통된 부분으로 묶으면 다음과 같이 표현할 수 있습니다.
        // i + (n - next) + min(i, n - next)
        // i + (n - next)$: 일단 양쪽 끝에서 목표 지점들(i와 next)까지 가는 기본 거리입니다.
        // min(i, n - next): i와 n - next 중 더 짧은 거리를 한 번 더 가겠다는 뜻입니다. (갔다가 다시 돌아와야 하니까요!)
        minMove = min(minMove, i + size - next + min(i, size - next));
    }
    
    answer += minMove;
    
    return answer;
}

// 내가 작성한 코드
/* 
int getUpDownCount(char c){
    return min(c - 'A', 'Z' - c + 1);
}

int solution(string name) {
    int answer = 0;
    int size = name.size();
    int idx = 0;
    
    for(int i = 0; i < size; i++){
        if(name[i] != 'A'){
            int front = i - idx;
            // int rear = min(size-idx, size-i);
            int rear = size - i + idx;
            if(front < rear || front == rear){
                answer += front;
                idx += front;
            }else{
                answer += rear;
                idx = size - rear;
            }
            answer += upDown(name[i]);
            
            cout << "idx : " << idx << endl;
            cout << "answer : " << answer << endl;
        }
    }
    return answer;
}
*/