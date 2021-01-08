#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<int, int> sequence;
map<int, int> frequency;
vector< pair<int, int> > answer;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return sequence[a.first] < sequence[b.first];
	else
		return a.second > b.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		if(!sequence[input])
			sequence[input] = i+1;
		frequency[input]++;
	}
	map<int, int>::iterator map_iter = frequency.begin();
	while (map_iter != frequency.end()) {
		answer.emplace_back(map_iter->first, map_iter->second);
		map_iter++;
	}

	sort(answer.begin(), answer.end(), compare);

	vector< pair<int, int> >::iterator vec_iter = answer.begin();
	while (vec_iter != answer.end()) {
		int i = 0;
		while(i != vec_iter->second) {
			cout << vec_iter->first << " ";
			i++;
		}
		vec_iter++;
	}
	
	return 0;
}