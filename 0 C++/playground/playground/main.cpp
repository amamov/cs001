#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 999999

int stack[SIZE];
int top = -1;

void push(int data) {
    if (top == SIZE - 1) {
        printf("스택 오버플로우가 발생했습니다."); // 스택이 가득찼습니다.
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("스택 언더플로우가 발생했습니다.");
        return -INF;
    }
    return stack[top--];
}

void show() {
    printf("-- 스택의 최상단 --\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
    printf("-- 스택의 최상단 --\n");
}

int main(void) {
    push(1);
    push(7);
    pop();
    push(2);
    push(3);
    pop();
    push(4);
    push(5);
    push(6);
    show();
    return 0;
}



/*
 -- 스택의 최상단 --
 6
 5
 4
 2
 1
 -- 스택의 최상단 --
*/
