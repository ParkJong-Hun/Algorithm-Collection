//선택 정렬
//첫 번째 자료를 두 번째 자료부터 마지막 자료까지 차례대로 비교해
//가장 작은 값을 찾아 첫 번째에 놓음.
//이후에는 두 번째 자료 ... 세 번쨔 자료 반복
#include <iostream>

using namespace std;

//스왑에 사용할 임시 저장소
int k;
//각 데이터가 저장될 곳.
int data[10];

void SelectionSort() {
    //10개의 인덱스가 있는 배열의 각 인덱스에 주어질 값을 입력
    for(int i = 0; i < 10; i++) {
        cin >> data[i];
    }
    //기준이 되는 자리. 10이 아닌 9인 이유는 9번째 자리까지 비교하면
    //10번째 자리는 저절로 가장 높은 자리가 되기 때문(1회전)
    for(int i = 0; i < 9; i++) {
        //비교되는 값 = 기준이 되는 자리부터 9까지
        for(int j = i; j < 10; j++) {
            //기준 자리의 값이 비교되는 값보다 크면
            //기준 자리와 비교 자리의 값을 스왑
            if(data[i] > data[j]) {
                k = data[i];
                data[i] = data[j];
                data[j] = k;
            }
        }
    }
    //출력
    for(int i = 0; i < 10; i++) {
        cout << data[i];
    }
    return;
}

int main(void) {
    SelectionSort();
    return 0;
}