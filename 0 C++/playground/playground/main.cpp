#include <stdio.h>
#include <stdlib.h>


struct Node {   // 연결 리스트의 노드 구조체
    int data;   // 데이터를 저장할 멤버
    struct Node *next;  // 다음 노드의 주소를 저장할 포인터
};

void add_front(Node *root, int data) {
    // root 노드 뒤에 새로운 노드를 삽입한다.
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

void remove_front(Node *root) {
    // root 노드의 앞에 있는 노드를 삭제한다.
    Node *front = root->next;
    root->next = front->next;
    free(front);
}

void free_all(Node *head) {
    // 연결 리스트 메모리 해제
    Node *cur = head->next;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

void show_all(Node *head) {
    Node *cur = head->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    struct Node *head = (Node*)malloc(sizeof(Node));    // 머리 노드 생성, head에는 값 부여 x
    struct Node *node1 = (Node*)malloc(sizeof(struct Node));   // 첫 번째 노드 생성
    head->next = node1; // head에 다음 node1의 주소를 저장하면서 연결
    node1->data = 1; // 첫 번째 노드에 값 1 부여
    struct Node *node2 = (Node*)malloc(sizeof(struct Node));   // 두 번째 노드 생성
    node1->next = node2; // node2에 다음 node2의 주소를 저장하면서 연결
    node2->data = 2; // 두 번째 노드에 값 2 부여
    node2->next = NULL; // node2가 마지막 node이므로 다음 주소에 NULL 저장
    remove_front(node1);
    add_front(head, 17);
    show_all(head);
    free_all(head);
    printf("\n");
    return 0;
}

/*
 [출력]
 17 1 
 */
