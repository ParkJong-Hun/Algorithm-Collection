//단어 개수
#include <stdio.h>
#include <string.h>
#define MAX_STRING 1000000
using namespace std;


int main(void) {
    char str[MAX_STRING] = {0,};
    gets(str);
    int count = 0;

    if(str[0] != 0) {
        for(int i = 1; i < MAX_STRING; i++) {
            if(str[i] == 32) {
                count++;
            } else if(str[i] == 0) {
                count++;
                break;
            }
        }
    }
    printf("%d", count);
    return 0;
}