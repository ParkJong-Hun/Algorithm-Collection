//알파벳 찾기
#include <stdio.h>
#include <string.h>
using namespace std;

void FindAlphabet() {
    //문자열
    char s[100];
    for(int i = 0; i < 100; i++) {
        s[i] = 0;
    }
    //알파벳 위치 저장
    int s_count[26];
    for(int i = 0; i < 26; i++) {
        s_count[i] = -1;
    }
    //문자열 입력
    gets(s);
    for(int i = 0; i < 100; i++) {
        if(s[i] < 97 || s[i] > 116) continue;
        //아스키 코드에서 a가 97이므로 s_count는 a의 위치
        if(s_count[s[i] - 97] == -1)
            s_count[s[i] - 97] = i;
    }
    for(int i = 0; i < 26; i++) {
        printf("%d ", s_count[i]);
    }
}

int main(void) {
    FindAlphabet();
    return 0;
}