//강하게 결합된 정점 집합
//흔히 SCC라고 불림.
//같은 SCC에 속하는 두 정점은 서로 도달 가능.
#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001//가능한 총 노드 개수

using namespace std;

int id, d[MAX]; //노드와 노드마다의 번호
bool finished[MAX]; //처리 완료된 노드
vector<int> a[MAX]; //인접노드
vector<vector<int> > SCC; //SCC 집합
stack<int> s; //부모가 같은 노드를 담을 스택

//DFS는 총 정점 갯수만큼 실행
int dfs(int x) {
    d[x] = ++id;//노드마다 고유한 번호 할당
    s.push(x);//스택에 자기 자신 삽입

    int parent = d[x];//부모 노드
    for(int i = 0; i < a[x].size(); i++) {//스택이 빌 때 까지
        int y = a[x][i];//스택의 원소들을 y에 넣음
        //방문하지 않은 이웃
        if(d[y] == 0) parent = min(parent, dfs(y));//노드 y의 값이 0이면 부모에서 해당 y에 dfs를 해서 최소값을 반환해 부모로 넣음
        //처리중인 이웃
        else if(!finished[y]) parent = min(parent,d[y]);//finished가 false면 부모에 자기 자신을 넣음
    }
    //부모가 자기 자신인 경우
    if(parent == d[x]) {
        vector<int> scc;//scc를 만듦.
        while(1) {
            int t = s.top();//
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == x) break;
        }
        SCC.push_back(scc);
    }
    //자신의 부모값 반환
    return parent;
}

int main(void) {
    int v = 11;
    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(2);
    a[4].push_back(5);
    a[5].push_back(7);
    a[6].push_back(5);
    a[7].push_back(6);
    a[8].push_back(5);
    a[8].push_back(9);
    a[9].push_back(10);
    a[10].push_back(11);
    a[11].push_back(3);
    a[11].push_back(8);
    for(int i = 1; i <= v; i++) {
        if(d[i] == 0) dfs(i);
    }
    printf("SCC의 갯수: %d\n", SCC.size());
    for(int i = 0; i < SCC.size(); i++) {
        printf("%d번째 SCC ", i + 1);
        for(int j = 0; j < SCC[i].size(); j++) {
            printf("%d ", SCC[i][j]);
        }
        printf("\n");
    }
    return 0;
}