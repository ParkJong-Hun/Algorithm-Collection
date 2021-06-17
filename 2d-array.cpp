//2차원 배열 기본형
#include <iostream>

using namespace std;

int arr[5][5];
int cnt = 1;

void TwoDArray() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            arr[i][j] = cnt;
            cnt++;
        }
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
    return;
}

int main(void) {
    TwoDArray();
    return 0;
}