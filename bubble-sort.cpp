//기준 인덱스와 인접한 다음 인덱스와 비교해 값이 작은 것을 앞에 위치하게 하여 처음부터 끝 인덱스
//(마지막 인덱스 - 회전 수)까지 차례대로 위의 작업을 하는 것이 1회전이다.
//시간 복잡도는 선택 정렬과 함께 가장 안좋은 축에 속함.
#include <iostream>

using namespace std;
//데이터를 저장하는 배열, 스왑에 사용할 임시 저장 변수
int data[10], k;
//버블 정렬
void BubbleSort() {
    //각 배열에 들어갈 데이터 입력
    for(int i = 0; i < 9; i++) {
        cin >> data[i];
    }
    //9번째까지 기준 인덱스 정함.(9번째의 다음이 10번째이므로 9가 마지막)(회전수)
    for(int i = 0; i < 9; i++) {
        //비교 되는 인덱스. 회전마다 마지막 값이 제일 큰 값이 되므로, 마지막 인덱스가 1씩 
        //줄어들게 함.
        for(int j = 0; j < 9 - i; j++) {
            //데이터가 큰 값이 뒤로 오게 스왑
            if(data[j] > data[j + 1]) {
                k = data[j];
                data[j] = data[j + 1];
                data[j + 1] = k;
            }
        }
    }
    //결과 출력
    for(int i = 0; i <= 9; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

int main(void) {
    BubbleSort();
    return 0;
}