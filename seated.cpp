//석차 구하기
#include <iostream>

using namespace std;
//점수와 등수
int score[2][5] = {
    {56, 60, 66, 42, 56}, 
    {1, 1, 1, 1, 1}
};
//점수의 개수
int n = 5;
//함수
void seated() {
    //기준이되는 점수를 위한 반복
    for(int i = 0; i < n; i++) {
        //비교되는 점수를 위한 반복
        for(int j = 0; j < n; j++) {
            //비교 점수가 기준 점수보다 크면 기준 점수의 등수를 1 증가
            if(score[0][i] < score[0][j]) {
                score[1][i]++;
            }
        }
    }
    //결과 출력
    for(int i = 0; i < n; i++) {
        cout << score[0][i] << "는" << score[1][i] << "등" << "\n";
    }
}

int main(void) {
    seated();
    return 0;
}