#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class Compare {
public:
    bool operator()(const pair<LL, LL>& lhs, const pair<LL, LL>& rhs) {
        if (lhs.second != rhs.second) {
            return lhs.second < rhs.second;
        }
        else {
            return lhs.first < rhs.first;
        }
    }
};

LL N;
LL K;
LL answer;
vector<pair<LL, LL>> gem; // {mass,value}
vector<LL> bag;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    gem.resize(N);
    bag.resize(K);

    for (LL i = 0; i < N; i++) {
        cin >> gem[i].first >> gem[i].second;
    }
    for (LL i = 0; i < K; i++) {
        cin >> bag[i];
    }
    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, Compare> pq;
    LL i = 0, j = 0;
    while (i < bag.size()) {
        if (j < gem.size() && bag[i] >= gem[j].first) {
            pq.emplace(gem[j]);
            j++;
        }
        else {
            if (!pq.empty()) {
                answer += pq.top().second;
                pq.pop();
            }
            i++;
        }
    }
    cout << answer;
    return 0;
}