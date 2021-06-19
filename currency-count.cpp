//화폐 매수 계산
//사실은 화폐 단위에 따른 배열을 하나 더 만들어서 for문을 돌리는 것이 더 좋다...
#include <iostream>

using namespace std;

int money;
int c[9];
int temp;

void CurrencyCount() {
    cin >> money;
    temp = money;
    //50000원 매수
    c[0] = (int)(temp / 50000);
    temp -=  ((int)(temp / 500000) * 50000);
    //10000원 매수
    c[1] = (int)(temp / 10000);
    temp -= ((int)(temp/ 10000) * 10000);
    //5000원 매수
    c[2] = (int)(temp / 5000);
    temp -= ((int)(temp / 5000) * 5000);
    //1000원 매수
    c[3] = (int)(temp / 1000);
    temp -= ((int)(temp / 1000) * 1000);
    //500원 매수
    c[4] = (int)(temp / 500);
    temp -= ((int)(temp / 500) * 500);
    //10원 매수
    c[5] = (int)(temp / 100);
    temp -= ((int)(temp / 100) * 100);
    //50원 매수
    c[6] = (int)(temp / 50);
    temp -= ((int)(temp / 50) * 50);
    //10원 매수
    c[7] = (int)(temp / 10);
    temp -= ((int)(temp / 10) * 10);
    //1원 매수
    c[8] = temp;
    cout << money << "의 화폐 매수 계산 결과" << "\n";
    for(int i = 0; i < 9; i++) {
        cout << c[i] << "\n";
    }
    return;
}

int main(void) {
    CurrencyCount();
    return 0;
}