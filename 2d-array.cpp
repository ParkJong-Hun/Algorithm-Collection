//2차원 배열 기본형
#include <iostream>

using namespace std;
//배열
int arr[5][5];
//각 인덱스에 들어갈 값
int cnt = 1;
//함수
void TwoDArray() {
    //행
    for(int i = 0; i < 5; i++) {
        //열
        for(int j = 0; j < 5; j++) {
            //값을 넣음
            arr[i][j] = cnt;
            //값을 1 증가
            cnt++;
        }
    }
    //결과 출력
    for(int i = 0; i < 5; i++) {
        //각 행의 값들을 모두 출력
        for(int j = 0; j < 5; j++) {
            cout << arr[i][j] << "\t";
        }
        //행의 값이 모두 출력되면 줄바꿈
        cout << "\n";
    }
    return;
}

int main(void) {
    TwoDArray();
    return 0;
}