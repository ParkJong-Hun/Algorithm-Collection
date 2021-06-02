//다이나믹 프로그래밍을 활용한 대표적인 최단 경로 탐색 알고리즘.
//인공지능 GPS 소프트웨어 등에서 가장 많이 사용
//음의 간선을 포함할 수 없음.
//현실 세계에 매우 적합한 알고리즘.
#include <stdio.h>

int number = 6;
int INF = 1000000000;//무한 표현

//전체 그래프 초기화
int a[6][6] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
};
bool v[6]; //방문한 노드
int d[6]; //최단 거리

//가장 최소 거리 정점 반환
int getSmallIndex() {
    //최소 값을 무한대로 설정
    int min = INF;
    //시작하는 위치(선택 노드)를 0 으로 설정
    int index = 0;
    //모든 노드에
    for(int i = 0; i < number; i++) {
        //노드 거리가 최소 값보다 작고 방문되지 않았다면
        if(d[i] < min && !v[i]) {
            //최소값을 해당 노드의 간선거리로 함.
            min = d[i];
            //시작하는 위치(선택 노드)를 i로 함.
            index = i;
        }
    }
    return index;//선택 노드 인덱스를 반환.
}

//다익스트라를 수행하는 함수
void dijkstra(int start) {
    //최소 거리를 첫번째 기준 노드와 연결된 거리로 초기화.
    for(int i = 0; i < number; i++) {
        d[i] = a[start][i];
    }
    //첫번째 기준 노드를 방문 처리.
    v[start] = true;
    //처음은 방문처리했고, 끝은 방문처리할 필요가 없으니 노드 개수 - 2보다 클 경우까지
    for(int i = 1; i < number - 2; i++) {
        int current = getSmallIndex();//선택 노드를 해당 노드의 가장 거리가 가까운 노드로 설정
        v[current] = true;//선택 노드를 방문 처리
        for(int j = 0; j < 6; j++) {
            if(!v[j]) {//해당 노드를 방문하지 않았다면
                if(d[current] + a[current][j] < d[j]) {//지금 방문하는 비용이 전의 비용보다 작으면
                    d[j] = d[current] + a[current][j];//최소 비용을 지금 방문하는 비용으로 갱신
                }
            }
        }
    }
}

int main(void) {
    dijkstra(0);
    for(int i = 0; i < number; i++) {
        printf("%d ", d[i]);
    }
}