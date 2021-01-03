#include<iostream>
#include<vector>

using namespace std;

vector<int>::iterator next_constructor(vector<int>&, vector<int>::iterator);
void self_number(void);

int main(void){
	self_number();
	
	return 0;
}

void self_number(void){
	vector<int> vec;
	vector<int>::iterator iter_i;
	vector<int>::iterator iter_j;
	vector<int>::iterator iter_j_next;
	vector<int>::iterator temp;
	for(int i=1; i<=10000; ++i){
		vec.push_back(i);
	}
	
	for(iter_i=vec.begin(); iter_i<vec.end(); ++iter_i){
		for(iter_j=next_constructor(vec,iter_i); iter_j<vec.end(); iter_j = iter_j_next){
			iter_j_next = next_constructor(vec,iter_j) -1;
			vec.erase(iter_j);
		}
	}
	
	for(iter_i=vec.begin(); iter_i<vec.end(); ++iter_i){
		cout << *iter_i << endl;
	}
}

vector<int>::iterator next_constructor(vector<int>& vec, vector<int>::iterator iter){
	int temp, num = *iter;
	temp = num;
	do{
		num += temp % 10;
		temp /= 10;
	}while(temp>0);
	for(iter; iter<vec.end(); ++iter)
		if(*iter==num) return iter;
	return vec.end();
}
