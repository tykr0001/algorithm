#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> graph(M);
	queue<int> component;

	for(int i=0; i<M; ++i) {
		cin >> graph[i].first >> graph[i].second;
	}
	
	

}