#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int L, C;
vector<char> arr;
vector<bool> selected;

void print() {
    for (int i = 0; i < C; ++i) {
        if (selected[i] == true) cout << arr[i];
    }
    cout << endl;
    return;
}

void DFS(int index, int depth, int consonant, int vowel) {
    if (depth == L && consonant >= 2 && vowel >= 1) {
        print();
        return;
    }

    for (int i = index; i < C; ++i) {
        // if (selected[i] == true) continue;
        selected[i] = true;
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            DFS(i + 1, depth + 1, consonant, vowel + 1);
        else
            DFS(i + 1, depth + 1, consonant + 1, vowel);
        selected[i] = false;
    }
}


int main(void) {
    cin >> L >> C;

    arr.resize(C);
    selected.resize(C, false);

    for (int i = 0; i < C; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    DFS(0, 0, 0, 0);

}