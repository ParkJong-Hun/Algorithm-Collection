//다익스트라 알고리즘을 힙을 히용해 만들어서 시간 복잡도를 낮춤.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int> > a[7]; //간선 정보
int d[7];//최소 간선 비용

void dijkstra(int start) {
    d[start] = 0;//자기 자신을 0으로
    priority_queue<pair<int, int> >pq; //힙 구조
    pq.push(make_pair(start, 0));
    //가까운 순서대로 처리하는 큐 사용
    while(!pq.empty()) {//힙이 빌 때까지
        int current = pq.top().first; //선택된 노드를 힙의 가장 최상단의 첫번째를 반환.
        //짧은 것이 먼저 오도록 음수화
        int distance = -pq.top().second; //간선 거리를 선택된 노드의 두번째 값(선택된 노드의 
        //인접 노드와의 거리를 음수화 해서 반환.(가장 위의 값을 음수화해서 가장 최소값이 되게 하기 위해)
        pq.pop();//가장 위의 값을 힙에서 없앰.
        //최단 거리가 아닌 경우 스킵
        if(d[current] < distance) continue;
        //간선의 선택 노드의 인덱스에 저장된 2차 인덱스의 끝까지
        for(int i = 0; i < a[current].size(); i++) {
            //선택된 노드의 인접 노드
            int next = a[current][i].first;
            //선택된 노드를 거쳐 인접 노드로 가는 비용
            int nextDistance = distance + a[current][i].second;
            //기존 최소 비용보다 더 저렴하면 교체.
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}

int main(void) {
    //기본적으로 연결되지 않은 경우 비용 무한
    for(int i = 1; i <= number; i++) {
        d[i] = INF;
    }
    //해당 노드의 인접노드와 인접노드의 거리를 추가.
    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(3, 5));
    a[1].push_back(make_pair(4, 1));

    a[2].push_back(make_pair(1, 2));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(4, 2));

    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(2, 3));
    a[3].push_back(make_pair(4, 3));
    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(6, 5));

    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(5, 1));

    a[5].push_back(make_pair(3, 1));
    a[5].push_back(make_pair(4, 1));
    a[5].push_back(make_pair(6, 2));

    a[6].push_back(make_pair(3, 5));
    a[6].push_back(make_pair(5, 2));

    dijkstra(1);
    for(int i = 1; i <= number; i++) {
        printf("%d ", d[i]);
    }
}