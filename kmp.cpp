//문자열 매칭 알고리즘
//Kruth Morris Pratt
//특정 글이 있을 때 그 글 안에서 하나의 문자열을 찾는 알고리즘
#include <iostream>

using namespace std;

int findString(string parent, string pattern) {
    int parentSize = parent.size();
    int patternSize = pattern.size();
    for(int i = 0; i <= parentSize - patternSize; i++) {
        bool finded = true;
        for(int j = 0; j < patternSize; j++) {
            if(parent[i + j] != pattern[j]) {
                finded = false;
                break;
            }
        }
        if(finded) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    string parent = "Hello World!";
    string pattern = "llo W";
    int result = findString(parent, pattern);
    if(result == -1) {
        printf("일치하는 문자열이 없음");
    } else {
        printf("%d번째에 발견", result + 1);
    }
}