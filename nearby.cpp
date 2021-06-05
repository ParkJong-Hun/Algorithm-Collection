//가까운 수 구하기 알고리즘
#include <stdio.h>

using namespace std;

void nearby(int arr[], int num, int n) {
    //num = 기준값 //n = 원소 개수
    int m = 1000000000;//초기 최솟값
    int c, s;//각 배열 요소를 기준값과 계산해 얻은 차이, 결과
    for(int i = 0; i < n; i++) {
        if(arr[i] >= num) c = arr[i] - num;
        else c = num - arr[i];
        if(m > c) {
            m = c;//뺀 값이 원래 최솟값보다 작다면 갱신
            s = arr[i];
        }
    }
    printf("%d가 %d에 가장 가깝습니다.", s, num);
    return;
}

int main(void) {
    int t[10] = {11, 200, 77, 66, 8, 14, 13, 16, 19, 20};
    nearby(t, 30, 10);
    return 0;
}