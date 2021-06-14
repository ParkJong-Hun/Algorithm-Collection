//삽입 정렬
//선택, 버블 정렬과 같이 시간 복잡도가 매우 높음.
//두 번째 자료부터 시작해 그 앞의 자료들과 비교해 삽입할 위치를 지정해 삽입하고 나머지 자료들을 뒤로 옮김
#include <iostream>

using namespace std;
//데이터 저장 배열
int n = 5;
int data[5];
//비교데이터 위치 변수, 기준 데이터 값 변수
int j, k;
void InsertionSort() {
    //데이터 입력
    for(int i = 0; i < n; i++) {
        cin >> data[i];
    }
    //회전수
    for(int i = 1; i < n; i++) {
        //k(기준 데이터)에 현재 회전수의 자리의 데이터를 저장
        k = data[i];
        //현재 회전수에서 1뺀 값부터 0번째 인덱스까지 차례대로 뺌
        for(j = i - 1; j > -1; j--) {
            //기준 데이터가 비교 데이터보다 작을 경우 비교 데이터를 한 칸 미룸
            if(data[j] > k) data[j + 1] = data[j];
            //작지 않을 경우 반복문을 빠져 나옴
            else break;
        }
        //빠져나왔을 때의 비교 데이터보다 기준 데이터가 크기때문에 비교 데이터보다 한 칸 뒤의 자리에 기준 데이터를 삽입
        data[j + 1] = k;
    }
    //결과 출력
    for(int i = 0; i < n; i++) {
        cout << data[i];
    }
    return;
}

int main(void) {
    InsertionSort();
    return 0;
}