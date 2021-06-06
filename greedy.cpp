//당장 눈 앞에 보이는 최적의 상황을 쫓는 알고리즘
//단순한 알고리즘
//항상 최적의 결과를 도출하는 것은 아니지만 어느정도 최적의
//근사값을 빠르게 구할 수 있음. ex) 거스름돈
#include <iostream>

using namespace std;

int main(void) {
    int n, result = 0;
    cin >> n;
    result += n / 500;
    n %= 500;
    result += n / 100;
    n %= 100;
    result += n / 50;
    n %= 50;
    result += n / 10;
    cout << result;
    return 0;
}