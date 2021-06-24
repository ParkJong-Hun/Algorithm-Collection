#include <iostream>

void FileIO() {
    FILE *fp;
    fp = fopen("/text.txt", "wt");
    if(fp == NULL) {
        printf("파일이 없어요.");
        return;
    }
    fprintf(fp, "Text");
    fclose(fp);
    printf("작성 완료");
    return;
}

int main(void) {
    FileIO();
    return 0;
}