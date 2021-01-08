#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(const string& a, const string& b){
	if(a.length() == b.length()) return a < b;
	else return a.length() < b.length();
}

int main(void){
	vector<string> vec;
	string temp;
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end(),compare);
	
	
	for(int i=0; i<N-1; ++i){
		if(vec[i]!=vec[i+1]) cout << vec[i] << endl;
	}
	cout << vec.back() << endl;
	return 0;
}
