#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

int main(void){
	int arr[100]={0};
	string str;
	cin >> str;
	
	for(int i=0; i<str.length(); ++i){
		if(str[i]<95)
			arr[str[i]]++;
		else
			arr[str[i]-32]++;
	}
	
	int *first = (int*)max_element(arr,arr+100);
	int *second = (int*)max_element(first+1,arr+100);
	if(*first == *second) cout << '?';
	else printf("%c", (first-(int*)arr));
	
	return 0;
}
