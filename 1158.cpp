#include<iostream>
#include<list>

using namespace std;

int main(void)
{
	list<int> my_list;
	int N, K;
	cin >> N >> K;
	
	for(int i=1; i<=N; ++i)
		my_list.push_back(i);
		
	list<int>::iterator iter = my_list.begin();	

	cout << '<';
	for(int i=0; i<N-1; ++i){
		for(int j=0; j<K-1; ++j){
			if(iter == my_list.end())
				iter = my_list.begin();
			iter++;
			if(iter == my_list.end())
				iter = my_list.begin();
		}
		cout << *iter << ", ";
		iter = my_list.erase(iter);
	}
	if(iter == my_list.end())
		iter = my_list.begin();
	cout << *iter << '>' << endl;
	return 0;
}
