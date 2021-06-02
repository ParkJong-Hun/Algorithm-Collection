//노드가 같은 그래프에 속한지 알려면, 자신의 부모를 찾고, 부모는 또 부모의 부모를 찾아서 최종적으로 원소와 부모의 값이 같은 노드를 찾아간다.
//이런 식으로 원소와 부모가 같은 노드로서 있는 다른 자식 노드들을 union아라고 한다.

#include <stdio.h>

//부모 노드를 가져오는 함수
int getParent(int parent[], int x) {
    if(parent[x] == x) return x;//현재 원소가 가리키는 부모 값이 자기 자신일 때 자기 자신의 값을 리턴함.
    return parent[x] = getParent(parent, parent[x]);//현재 원소가 가리키는 부모 값이 자기 자신이 아닐 때, 자기 자신일 때까지 부모로 이동해 이 함수를 재귀적으로 실행
}

//두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);//a의 부모의 값을 찾음
    b = getParent(parent, b);//b의 부모의 값을 찾음
    if(a < b) parent[b] = a;//a가 b보다 작으면 b의 부모의 값을 a
    else parent[a] = b;//아니면 a의 부모의 값을 b로
}

//같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);//a의 부모의 값을 찾음
    b = getParent(parent, b);//b의 부모의 값을 찾음
    if(a == b) return 1;//두 부모 값이 같으면 1 반환
    return 0;//아니면 0 반환
}

int main(void) {
    int parent[11];
    for(int i = 1; i <= 10; i++) {
        parent[i] = i;
    }
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);
    printf("5의 부모는? %d\n", getParent(parent, 5));
    printf("1과 5는 연결되어 있는가? %d\n", findParent(parent, 1, 5));

    return 0;
}