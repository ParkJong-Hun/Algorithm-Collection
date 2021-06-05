//항상 빠르지는 않지만 일반적인 경우 매우 빠른 문자열 매칭 알고리즘
//해시 기법 사용.
//긴 데이터를 그것을 상징하는 짧은 데이터로 바꿈.
#include <iostream>

using namespace std;

void findString(string parent, string pattern) {
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int parentHash = 0, patternHash = 0, power = 1;
    for(int i = 0; i < parentSize - patternSize; i++) {
        if(i == 0) {
            for(int j = 0; j < patternSize; j++) {
                parentHash += parent[patternSize - 1 - j] * power;
                patternHash += pattern[patternSize - 1 - j] * power;
                if(j < patternSize - 1) power *= 2;
            }
        } else {
            parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
        }
        if(parentHash == patternSize) {
            bool finded = true;
            for(int j = 0; j < patternSize; j++) {
                if(parent[i + j] != pattern[j]) {
                    finded = false;
                    break;
                }
            }
            if(finded) {
                printf("%d번째에서 발견\n", i + 1);
            }
        }
    }
}

int main(void) {
    string parent = "abcdabc";
    string pattern = "abc";
    findString(parent, pattern);
    return 0;
}