//2차원 배열로 직각 삼각형 만들기
#include <iostream>

using namespace std;
//배열
int arr[5][5];
//증가하는 값
int cnt = 1;
//함수
void CreateTriangle() {
    //행
    for(int i = 0; i < 5; i++) {
        //열
        for(int j = 0; j <= i; j++) {
            //값을 넣음
            arr[i][j] = cnt;
            //값을 증가
            cnt++;
        }
    }
    //결과 출력
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j <= i; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main(void) {
    CreateTriangle();
    return 0;
}