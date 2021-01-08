#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int N=0, sum=0, score=0;
	cin >> N;
	string* str = new string[N];
	
	for(int i=0; i<N; ++i){
		cin >> str[i];
	} 
	
	for(int i=0; i<N; ++i){
		sum = 0;
		score = 0;
		for(int j=0; j<str[i].length(); ++j){ 
			if(str[i][j]=='X') score = 0;
			if(str[i][j]=='O') score++;
			sum+=score;
		}
		cout << sum << endl;
	}
	return 0;
} 
