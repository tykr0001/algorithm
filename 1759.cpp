#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<char>& arr, vector<bool>& selected, const int C) {
	for (int i = 0; i < C; ++i) {
		if (selected[i] == true) cout << arr[i];
	}
	cout << endl;
	return;
}

void DFS(vector<char>& arr, vector<bool>& selected, const int L, const int C, int index, int level, int consonant, int vowel) {
	if (level == L && consonant >=2 && vowel >= 1) {
		print(arr,selected,C);
		return;
	}

	for (int i = index; i < C; ++i) {
		if (selected[i] == true) continue;
		selected[i] = true;
		if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			DFS(arr, selected, L, C, i, level + 1, consonant, vowel + 1);
		else DFS(arr, selected, L, C, i, level + 1, consonant + 1, vowel);
		selected[i] = false;
	}
}


int main(void) {
	int L, C;
	cin >> L >> C;

	vector<char> arr(C);
	vector<bool> selected(C, false);

	for (int i = 0; i < C; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	DFS(arr, selected, L, C, 0, 0, 0, 0);

}