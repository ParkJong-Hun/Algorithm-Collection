//이분 검색
//정렬 된 데이터에서만 사용 가능
//찾을 값이 나올 때 까지 반을 나누어서 검색하는 방법
#include <iostream>

using namespace std;

void BinarySearch() {
    int k, L, h, m;//찾는 값, 시작위치, 마지막위치, 중간위치
    //데이터 저장 배열
    int data[10] = {1, 3, 6, 9, 10, 13, 24, 33, 34, 50};
    //찾을 값 입력
    cin >> k;
    //데이터 시작 위치 초기화
    L = 0;
    //데이터 끝 위치 초기화
    h = 9;
    while(1) {
        //시작위치가 끝위치와 같거나 클 때 찾지 못했음을 의미
        if(L <= h) {
            //시작위치와 끝위치를 이용해중간 위치를 계산
            m = (L + h) / 2;
            //찾는 값이 중간 위치의 데이터와 같으면
            if(k == data[m]) {
                cout << k << "는" << m + 1 << "번째에 위치";
                break;
            }
            if(k < data[m]) h = m - 1;
            else L = m + 1;
        } else {
            cout << k << "를 못 찾음";
            break;
        }
    }
    return;
}

int main(void) {
    BinarySearch();
    return 0;
}