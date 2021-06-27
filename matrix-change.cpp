//행렬 변환
//행과 열의 갯수가 서로 반대인 배열A의 것을 배열B에 차례대로 옮김
#include <iostream>

using namespace std;

int r, c;
int i, j, l, m;

void MatrixChange() {
    //A 배열의 행, 열 갯수 B 배열의 열,행 갯수 설정
    cin >> r >> c;
    int a[r][c];
    int b[c][r];
    int k = 0;
    //A배열에 값 넣음
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            k++;
            a[i][j] = k;
        }
    }
    //B배열의 행, 열을 초기화(m(열)이 -1로 초기화 되는 이유는 밑에 알고리즘에서 1을 추가하기 때문)
    l = 0;
    m = -1;
    //A의 행 만큼 반복
    for(i = 0; i < r; i++) {
        //A의 열 만큼 반복
        for(j = 0; j < c; j++) {
            //값을 넣을 B의 열을 1 증가
            m+=1;
            //B[l][m]에 A[i][j]의 값을 넣음
            b[l][m] = a[i][j];
            //B의 열이 A의 행 길이(B의 열 길이) 보다 클 경우 B의 행을 1증가시키고 열을 -1로 초기화
            if(m > r - 2) {
                l++;
                m = -1;
            }
        }
    }
    //A배열 출력
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
    //B배열 출력
    for(i = 0; i < c; i++) {
        for(j = 0; j < r; j++) {
            cout << b[i][j] << "\t";
        }
        cout << "\n";
    }
    return ;
}

int main(void) {
    MatrixChange();
    return 0;
}