//모든 정점에서 모든 정점으로의 최단 경로를 구하는 알고리즘.
//다익스트라는 가장 적은 비용을 하나씩 선택해야 했다면 플로이드는 기본적으로 거쳐가는 정점을 기준으로 함.
#include <stdio.h>

int number = 4;
int INF = 1000000000;

//자료 배열 초기화
int a[4][4] = {
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

void floydWarshall() {
    //결과 그래프 초기화
    int d[number][number];

    for(int i = 0; i < number; i++) {
        for(int j = 0; j < number; j++) {
            d[i][j] = a[i][j];
        }
    }

    //k = 거쳐 가는 노드
    for(int k = 0; k < number; k++) {
        //i = 출발노드
        for(int i = 0; i < number; i++) {
            //j = 도착 노드
            for(int j = 0; j < number; j++) {
                //출발노드에서 k를 거쳐서 도착노드로 가는 길이가 원래 출발노드에서 도착노드
                //로 가는 길이보다 작을 경우, 간선 길이를 갱신
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    //결과 출력
    for(int i = 0; i < number; i++) {
        for(int j = 0; j < number; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    floydWarshall();
}