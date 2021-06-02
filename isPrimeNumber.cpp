#include <stdio.h>
#include <math.h>
//소수 판별
//시간복잡도 O(N)
bool isPrimeNumber(int x) {
    for(int i = 2; i , x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
//소수 판별하고싶은 값의 제곱근까지만 제수를 증가시키면서 나누어 떨어지는지 검사해도 소수판별이 가능하므로 더 효율적으로 검사할 수 있다.
bool isPrimeNumber2(int x) {
    int end = (int) sqrt(x);
    for(int i = 2; i <= end; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
//에라토스테네의 체. 처음으로 활성화된 수를 찾으면 그것의 배수에 해당하는 값들은 전부 비활성화 시키면서 1씩 증가시킨다.
void isPrimeNumberSieve(int x) {
    int number = x;
    int a[number];
    for(int i = 2; i <= number; i++) {
        a[i] = i;
    }
    for(int i = 2; i <= number; i++) {
        if(a[i] == 0) continue;
        for(int j = i + i; j <= number; j += i) {
            a[j] = 0;
        }
    }
    for(int i = 2; i <= number; i++) {
        if(a[i] != 0) printf("%d", a[i]);
    }
}


int main(void) {
    printf("%d", isPrimeNumber(100));
}