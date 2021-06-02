#include <iostream>

using namespace std;

//노드 개수
int number = 15;

//하나의 노드 정보를 treePointer라는 포인터로 선언
typedef struct node *treePointer;

//노드 구조 정의
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;

//전위 순회
void preorder(treePointer ptr) {
    if(ptr) {
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

//중위 순회
void inorder(treePointer ptr) {
    if(ptr) {
        preorder(ptr->leftChild);
        cout << ptr->data << ' ';
        preorder(ptr->rightChild);
    }
}

//후위 순회
void postorder(treePointer ptr) {
    if(ptr) {
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

//메인
int main(void) {
    //노드 객체를 선언(1 + 하는 이유는 인덱스 1부터 값을 넣으므로)
    node nodes[number+1];
    //각 노드를 만들기
    for(int i = 1; i <= number; i++) {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    //노드를 연결하기. 자신의 2 나눈 값을 부모 노드로서 자신이 짝수면 왼쪽 홀수면 오른쪽에
    for(int i = 1; i <= number; i++) {
        if(i % 2 == 0) {
            nodes[i / 2].leftChild = &nodes[i];

        } else {
            nodes[i / 2].rightChild = &nodes[i];
        }
    }
    //전위 순회
    preorder(&nodes[1]);
    return 0;
}