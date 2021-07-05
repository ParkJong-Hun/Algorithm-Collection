//최소공배수 최대공약수 찾기
//유클리드 호제법 이용
#include <iostream>

using namespace std;
//최대공약수
int gcd(int a, int b) {
    //b가 0이될 때까지
    while(b != 0) {
        //a에 b를 나눈 나머지 저장
        int r = a % b;
        //b의 값을 a에 넣음
        a = b;
        //나머지를 b에 넣음
        b = r;
    }
    //b가 0일 때 a의 값은 최대공약수
    return a;
}
//최소공배수
int lcm(int a, int b) {
    //a x b 값에 최대공약수를 나눈 값은 최소공배수.
    return a * b / gcd(a, b);
}

int main(void) {
    cout << "최대 공약수 : " << gcd(10, 8) << "\n";
    cout << "최소 공배수 : " << lcm(10, 8) << "\n";
    return 0;
}