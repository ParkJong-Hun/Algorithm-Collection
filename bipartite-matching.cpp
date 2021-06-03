//이분 매칭
//네트워크 플로우 알고리즘과 연계되는 개념
//두 개의 집단으로 나누어질 때만 사용
#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

//노드에 무엇을 연결하는지 저장
vector<int> a[MAX];
//연결된 노드
int d[MAX];
//처리되었는지
bool c[MAX];
int n = 3, m;

//매칭
bool dfs(int x) {
    //연결된 모든 노드에 대해서 들어갈 수 있는지 시도
    for(int i = 0; i < a[x].size(); i++) {
        //벡터를 이용해 x 노드에 i번째 값을 t에 저장
        int t = a[x][i];
        //이미 처리된 노드는 더 이상 볼 필요 없음
        if(c[t]) continue;
        //노드 처리
        c[t] = true;
        //비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
        if(d[t] == 0 || dfs(d[t])) {
            //노드 x를 d[t]에 대입
            d[t] = x;
            //매칭 성공
            return true;
        }
    }
    //매칭 실패
    return false;
}

int main(void) {
    a[1].push_back(1);
    a[1].push_back(2);
    a[1].push_back(3);
    a[2].push_back(1);
    a[2].push_back(2);
    a[3].push_back(2);
    //몇개 매칭됐는지 저장하는 변수
    int count = 0;
    //c의 모든 요소를 false로 초기화하고 dfs 1부터 n까지 실행
    for(int i = 1; i <= n; i++) {
        fill(c, c + MAX, false);
        //dfs에서 매칭 성공하면 count 증가
        if(dfs(i)) count++;
    }
    printf("%d개의 매칭이 이루어짐\n", count);
    for(int i = 1; i < MAX; i++) {
        if(d[i] != 0) printf("%d -> %d\n", d[i], i);
    }
    return 0;
}