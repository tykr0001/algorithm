#include <iostream>

using namespace std;

int N;
int answer = -1;
int map[20][20]; // 1:백, 2:흑

bool BorderCheck(int i, int j, int x, int y) {
    return 1 <= i && i <= 19 && 1 <= j && j <= 19 && map[x][y] == map[i][j];
}

bool Check(int x, int y) {
    int cnt;
    int i;
    int j;

    // horizontal
    cnt = 1;
    i = x;
    j = y + 1;
    while (BorderCheck(i, j, x, y)) {
        cnt++;
        j++;
    }

    i = x;
    j = y - 1;
    while (BorderCheck(i, j, x, y)) {
        cnt++;
        j--;
    }
    if (cnt == 5) {
        return true;
    }

    // vertical
    cnt = 1;
    i = x + 1;
    j = y;
    while (BorderCheck(i, j, x, y)) {
        cnt++;
        i++;
    }

    i = x - 1;
    j = y;
    while (BorderCheck(i, j, x, y)) {
        cnt++;
        i--;
    }
    if (cnt == 5) {
        return true;
    }

    // increase diagonal
    cnt = 1;
    i = x - 1;
    j = y + 1;
    while (BorderCheck(i, j, x, y)) {
        cnt++;
        i--;
        j++;
    }

    i = x + 1;
    j = y - 1;
    while (BorderCheck(i, j, x, y)) {
        cnt++;
        i++;
        j--;
    }
    if (cnt == 5) {
        return true;
    }
    // decrease diagonal
    cnt = 1;
    i = x + 1;
    j = y + 1;
    while (BorderCheck(i, j, x, y)) {
        cnt++;
        i++;
        j++;
    }

    i = x - 1;
    j = y - 1;
    while (BorderCheck(i, j, x, y)) {
        cnt++;
        i--;
        j--;
    }
    if (cnt == 5) {
        return true;
    }

    return false;
}

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = i % 2 + 1;
        if (Check(x, y)) {
            answer = i;
            break;
        }
    }
    cout << answer << endl;

    return 0;
}