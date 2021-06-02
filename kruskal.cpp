//1. 간선의 값을 오름차순으로 정렬함.
//2. 가장 작은 값부터 채택함.
//3. 채택한 것을 넣으면 사이클이 발생하는지 확인. 이 때 유니온 파인드 함수를 사용
//4. 간선이 노드-1개일 때가 될 때까지 반복
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
//간선
class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this -> node[0] = a;
        this -> node[1] = b;
        this -> distance = distance;
    }
    bool operator <(Edge &edge) {
        return this-> distance < edge.distance;
    }
};
//메인
int main(void) {
    //노드 개수
    int n = 7;
    //간선 개수
    int m = 11;
    //간선 넣기
    vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));
    v.push_back(Edge(1, 5, 17));
    //간선 오름차순 정렬
    sort(v.begin(), v.end());
    //노드의 부모 값 설정
    int parent[n];
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    //연결되는 노드의 부모가 각각 같은지 확인해서, 부모가 같지 않으면 부모를 갖게 하고(간선을 합치고) 간선 값을 sum에 추가
    int sum = 0;
    for(int i = 0; i < v.size(); i++) {
        if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
            sum += v[i].distance;
            unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }
    //출력
    printf("%d", sum);
    return 0;
}