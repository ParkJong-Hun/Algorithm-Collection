//문자열 반복
#include <stdio.h>
#include <string.h>

using namespace std;

//입력횟수
int t;
//반복횟수
int r;
//출력횟수
char s[20] = {0,};
int length;

void StringRepeat() {
    scanf("%d", &t);
    //출력횟수
    char s[1000][20] = {0,};
    for(int i = 0; i < t; i++) {
        scanf("%d", &r);
        for(int j = 0; j < 20; j++) {
            scanf("%c", &s[i][j]);
            if(s[i][j] == '\n') {
                break;
            }
        }
    }

    //결과값 출력
    for(int i = 0; i < t; i++) {
        for(int j = 1; s[i][j]!= '\n'; j++) {
            for(int k = 0; k < r; k++) {
                printf("%c", s[i][j]);
            }
        }
        printf("\n");
    }
}

int main(void) {
    StringRepeat();
    return 0;
}