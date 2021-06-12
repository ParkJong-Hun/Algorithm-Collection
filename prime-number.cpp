//소수 판별
#include <iostream>

using namespace std;

void findPrimeNumber(int a) {
    int i, j;
    i = a - 1;
    j = 2;
    while(1) {
        if (j <= 1)
            if(a % j == 0) {
                cout << "소수 아님";
                break;
            } else j++;
        else {
            cout << "소수";
            break;
        }
    }
}

int main(void) {
    findPrimeNumber(3);
    return 0;
}