#include<iostream>

using namespace std;

int main(void){
	int N, kilogram, five=0, three=0;
	
	cin >> N;
	kilogram = N;
	while(kilogram>=5){
		kilogram -= 5;
		five++;
	}
	
	if(kilogram==0){
		cout << five << endl;
		return 0;
	}
	
	do{
		while(kilogram>=3){
			kilogram -= 3;
			three++;
		}
		if(kilogram==0)
			break;
		else{
			kilogram += 5;
			five--;
		}
	}while(five>=0);
	
	if(five<0) cout << -1;
	else cout << five+three;
	
	return 0;
}
