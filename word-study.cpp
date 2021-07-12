//단어 공부
#include <stdio.h>
#include <string.h>
#define MAX_WORD 1000000
using namespace std;

void WordStudy() {
    char word[MAX_WORD] = {0,};
    int count[26] = {0,};
    int maxWord;
    bool isTwice;

    gets(word);
    maxWord = 0;
    isTwice = false;

    for(int i = 0; word[i] != 0; i++) {
        int temp = word[i];
        if(word[i] >= 97) {
            count[97 - temp]++;
        } else {
            count[65 - temp]++;
        }
    }
    for(int i = 0; i < 26; i++) {
        if(maxWord < count[i]) {
            isTwice = false;
            maxWord = count[i];
        } else if(maxWord == count[i]) {
            isTwice = true;
            maxWord = count[i];
        } else {
            isTwice = false;
        }
    }
    if(isTwice) {
        printf("?");
    } else {
        printf("%c", maxWord + 64);
    }
    return;
}

int main(void) {
    WordStudy();
    return 0;
}