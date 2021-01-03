#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	vector<pair<int, string>> answer; // age name
	answer.resize(N);

	for (int i = 0; i < N; ++i) {
		cin >> answer[i].first >> answer[i].second;
	}
	stable_sort(answer.begin(), answer.end(), compare);
	
	vector<pair<int, string>>::iterator iter = answer.begin();
	while (iter != answer.end()) {
		cout << iter->first << " " << iter->second << '\n';
		iter++;
	}
	return 0;
}