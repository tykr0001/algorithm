#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N, cycle = 0;
		cin >> N;
		vector<int> node(N), vertex(N);

		for (int i = 0; i < N; ++i) {
			node[i] = i;
			cin >> vertex[i];
			vertex[i]--;
		}

		for (int i = 0; i < N; ++i) {
			int init = node[i];
			int next = vertex[i];
			int iter = i;
			if (init == -1)
				continue;
			while (init != next) {
				node[iter] = -1;
				iter = next;
				next = vertex[iter];
			}
			node[iter] = -1;
			iter = next;
			next = vertex[iter];
			cycle++;
		}
		cout << cycle << endl;
	}
}