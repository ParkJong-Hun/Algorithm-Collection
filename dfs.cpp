//주로 스택 사용. 알고리즘 대회에서는 재귀함수 사용. 깊이 우선 탐색
#include <iostream>
#include <vector>
using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void dfs(int x) {
    if(c[x]) return;//방문이 되어있으면 바로 함수를 종료.
    c[x] = true;//방문이 되어 있지 않으면 방문 처리를 해줌.
    cout << x << ' ';//방문 처리된 값을 출력
    for(int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];//해당 원소와 연결된 자식값을 순서대로 가져와 dfs 실행
        dfs(y);
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

    //깊이 우선 검색을 실행(가장 처음 시작(루트 노드)을 1)
    dfs(1);
    return 0;
}