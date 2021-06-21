//모래시계
#include <iostream>

using namespace std;

int cnt = 1;
int n = 0;
int m = 5;;
int arr[5][5];

void CreateHourglass() {
    for(int i = 0; i < 3; i++) {
        for(int j = n; j < m; j++) {
            arr[i][j] = cnt;
            cnt++;        
        }
        n++;
        m--;
    }
    n = 1;
    m = 4;
    for(int i = 3; i < 5; i++) {
        for(int j = n; j < m; j++) {
            arr[i][j] = cnt;
            cnt++;
        }
        n--;
        m++;
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
    CreateHourglass();
    return 0;
}