//특정 지점에서 다른 지점으로 얼마나 많은 양의 데이터가 흐르고 있는지 측정.
//교통 체증, 네트워크 데이터 전송 등 분야에서 활용
//에드몬드 카프 알고리즘이라고 부름
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 1000000000

using namespace std;

//원소개수, 최대 유량 값
int n = 6, result = 0;
//각 노드 용량, 유량 길이, 
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end) {
    while(1) {
        fill(d, d + MAX, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int i = 0; i < a[x].size(); i++) {
                int y = a[x][i];
                //방문하지 않은 노드 중 용량이 남은 경우
                if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    q.push(y);
                    d[y] = x;//경로 기억
                    if(y == end) break;//도착지에 도달한 경우
                }
            }
        }
        //모든 경로를 다 찾은 경우 탈출
        if(d[end] == -1) break;
        int flow = INF;
        //거꾸로 최소 유량 탐색
        for(int i = end; i != start; i = d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        //최소 유량만큼 추가
        for(int i = end; i != start; i = d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        result += flow;
    }
}

int main(void) {
    //원소 넣기
    a[1].push_back(2);
    a[2].push_back(1);
    c[1][2] = 12;

    a[1].push_back(4);
    a[4].push_back(1);
    c[1][4] = 11;

    a[2].push_back(3);
    a[3].push_back(2);
    c[2][3] = 6;

    a[2].push_back(4);
    a[4].push_back(2);
    c[2][4] = 3;

    a[2].push_back(5);
    a[5].push_back(2);
    c[2][5] = 5;

    a[2].push_back(6);
    a[6].push_back(2);
    c[2][6] = 9;

    a[3].push_back(6);
    a[6].push_back(3);
    c[3][6] = 8;

    a[4].push_back(5);
    a[5].push_back(4);
    c[4][5] = 9;

    a[5].push_back(3);
    a[3].push_back(5);
    c[5][3] = 3;

    a[5].push_back(6);
    a[6].push_back(5);
    c[5][6] = 4;

    //최대 유량 구하기
    maxFlow(1, 6);
    printf("%d", result);
}