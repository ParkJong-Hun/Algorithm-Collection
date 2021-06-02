//큐 사용. 너비 우선 탐색
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;//몇개의 원소가 있는지
int c[8];//방문 표시
vector<int> a[8];//사용할 각 원소를 인덱스로서 사용해 배열(벡터)을 만듦.

void bfs(int start) {
    queue<int> q;//큐 선언
    q.push(start);//큐에 인자로 가져온 값을 원소를 추가
    c[start] = true;//가져온 값의 방문을 처리
    while(!q.empty()) {//큐에 원소가 있을 동안
        int x = q.front();//큐의 가장 앞 원소를 x에 넣어줌.
        q.pop();//큐의 가장 앞 원소를 내보냄.
        printf("%d ", x);//내보낸 원소를 출력(방문을 처리했음을 사람에게 알림)
        for(int i = 0; i < a[x].size(); i++) {//해당 원소의 인덱스(해당 원소와 이어진 자식값들)을 모두 방문할 때까지 순차적으로 방문
            int y = a[x][i];//해당 원소와 이어진 값을 y에 넣음.
            if(!c[y]) {//y가 방문되지 않았으면,
                q.push(y);//큐에 y를 추가
                c[y] = true;//y를 방문 처리
            }
        }
    }
}

int main() {
    //원소 추가
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    //너비 우선 검색을 실행(가장 처음 시작(루트 노드)을 1)
    bfs(1);
    return 0;
}