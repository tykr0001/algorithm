#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(const pair< int, pair<int,int> >& a, const pair< int, pair<int,int> >& b){
	return a.first < b.first;
}

int main(void){
	int N,first_country,second_country;
	cin >> N;
	vector< pair< int, pair< int, int > > > party;
	
	for(int i=0; i<N; ++i){
        int country, sid, score;
		cin >> country >> sid >> score;
		party.push_back(make_pair(score,make_pair(country,sid)));
	}
	
	sort(party.begin(),party.end(),compare);
	
	cout << party.back().second.first << " " << party.back().second.second << endl;
	first_country = party.back().second.first;
	party.pop_back();	
	
	cout << party.back().second.first << " " << party.back().second.second << endl;
	second_country = party.back().second.first;
	party.pop_back();
	
	if(first_country == second_country){
		while(second_country == party.back().second.first)
		    party.pop_back();
	}
	cout << party.back().second.first << " " << party.back().second.second << endl;
}
