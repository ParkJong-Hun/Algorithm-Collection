//소인수 분헤
#include <iostream>

using namespace std;

void primeFactor(int n) {
    while(n != 1) {//나눈 몫이 1이면 해당 소인수 분해가 끝남을 의미.
        for(int i = 2; i <= n; i++) {//2부터 시작해서 n까지 제수를 늘려감.
            if(n % i == 0) {//몫과 제수를 나눈 나머지가 0이면 해당 제수는 소인수임.
                cout << i << " ";//출력
                n /= i;//제수와 몫을 나누어 얻은 새 몫을 구해서 그것을 기준으로 반복하게 함.
                break;//다시 2부터 시작하게 함.(소인수 분해는 약수를 구하는게 아닌, 소인수를 구하는 것)
            }
        }
    }
}

int main(void) {
    primeFactor(36);
}