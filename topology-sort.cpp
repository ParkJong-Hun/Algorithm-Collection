//순서가 정햐져있는 작업을 차례로 수행해야할 때 그 순서를 결정하기 위한 알고리즘
//사이클이 발생한 경우 위상정렬을 수행할 수 없음
#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

//노드 개수, 노드의 차수
int n, inDegree[MAX];
//벡터
vector<int> a[MAX];

//위상 정렬
void topologySort() {
    //결과 저장하는 배열 선언
    int result[MAX];
    //차례대로 노드를 넣을 큐 선언
    queue<int> q;
    //진입 차수가 0인 노드를 큐에 삽입
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) q.push(i);
    }
    //위상 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문
    for(int i = 1; i <= n; i++) {
        //큐가 비었다면
        if(q.empty()) {
            printf("사이클 발생");
            return;
        }
        //큐의 가장 앞 원소를 x라는 변수에 저장
        int x = q.front();
        //큐의 가장 앞 원소를 없앰
        q.pop();
        //저장한 x의 값을 결과(방문 순서)에 추가.
        result[i] = x;
        //벡터의 최대 크기까지
        for(int i = 0; i < a[x].size(); i++) {
            //벡터의 x번째의 i번째 인덱스의 값을 y에 추가.
            int y = a[x][i];
            //y의 차수를 1 뺀 값이 0과 같을 경우
            if(--inDegree[y] == 0) {
                //큐에 y를 푸쉬
                q.push(y);
            }
        }
    }


    //결과 출력
    for(int i = 1; i <= n; i++) {
        printf("%d ", result[i]);
    }
}

int main(void) {
    n = 7;
    a[1].push_back(2);
    inDegree[2]++;
    a[1].push_back(5);
    inDegree[5]++;
    a[2].push_back(3);
    inDegree[3]++;
    a[3].push_back(4);
    inDegree[4]++;
    a[4].push_back(6);
    inDegree[6]++;
    a[5].push_back(6);
    inDegree[6]++;
    a[6].push_back(7);
    inDegree[7]++;

    topologySort();
}