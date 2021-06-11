//석차
#include <iostream>

using namespace std;

int score[2][5] = {
    {56, 60, 66, 42, 56}, 
    {1, 1, 1, 1, 1}
};
int n = 5;

void seated() {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(score[0][i] < score[0][j]) {
                score[1][i]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << score[0][i] << "는" << score[1][i] << "등" << "\n";
    }
}

int main(void) {
    seated();
    return 0;
}