#include<iostream>

using namespace std;

int main(void){
	int E, S, M;
	
	cin >> E >> S >> M;
	
	while(!(E==S && S==M)){
		if(E<S || E<M) E+=15;
		if(S<E || S<M) S+=28;
		if(M<E || M<S) M+=19;
	}
	
	cout << E;
	
	return 0;
}
