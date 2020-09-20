#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool possible_term(const int term, const int M, const vector<int>& rest) {
	int count = 0, cur = rest.front();
	vector<int>::const_iterator iter = rest.begin();
	while (cur <= rest.back() && iter != rest.end()) {
		if (cur + term < *iter) {
			cur += term;
			count++;
		}
		else {
			cur = *iter;
			iter++;
		}
	}

	return count <= M;
}

int find_max_term(const int M, const vector<int>& rest) {
	int begin = 1, end = rest.back();
	int ret = -1;
	while (begin <= end) {
		int term = (begin + end) / 2;
		if (possible_term(term, M, rest)) {
			ret = term;
			end = term - 1;
			term = (begin + end) / 2;
		}
		else {
			begin = term + 1;
			term = (begin + end) / 2;
		}
	}
	return ret;
}

int main(void) {
	int N, M, L;
	cin >> N >> M >> L;

	vector<int> rest(N+2);

	rest[0] = 0;
	for (int i = 1; i < N+1; ++i) {
		cin >> rest[i];
	}
	rest[N + 1] = L;
	sort(rest.begin(), rest.end());
	cout << find_max_term(M,rest);
	return 0;
}

/*
12 82@ 152 201@ 271 341 411@ 481 551 555@ 622@ 692 755@
0 82@ 182 201@ 301 401 411@ 511 555@ 622@ 722 755@

*/