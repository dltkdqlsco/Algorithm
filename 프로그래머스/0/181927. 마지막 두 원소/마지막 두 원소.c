#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * n + 1);
    int last = num_list[n - 1];
    int second_last = num_list[n - 2];
    
    memcpy(answer, num_list, sizeof(int) * n);
    
    if(last > second_last){
        answer[n] = last - second_last;
    }else{
        answer[n] = last * 2;
    }
    return answer;
}