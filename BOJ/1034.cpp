#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int row = 0, col = 0, k = 0, count = 0, max = 0;
	cin >> row >> col;
	vector<pair<string, pair<int,int>>> answer; //input string, num of dupli, num of zero
	for (int i = 0; i < row; ++i) {
		string input;
		int zero=0;
		cin >> input;
		int rep = col;
		while (rep) {
			rep--;
			if (input[rep] == '0')
				zero++;
		}
		vector<pair<string, pair<int, int>>>::iterator iter = answer.begin();
		while (iter != answer.end()) {
			if (input == iter->first) {
				iter->second.first++;
				break;
			}
			iter++;
		}
		if (iter == answer.end())
			answer.emplace_back(input, make_pair(1,zero));
	}
	cin >> k;
	vector<pair<string, pair<int, int>>>::iterator iter = answer.begin();
	while (iter != answer.end()) {
		if (k >= iter->second.second && iter->second.second % 2 == k % 2) {
			if (max < iter->second.first)
				max = iter->second.first;
		}
		iter++;
	}

	cout << max;
}