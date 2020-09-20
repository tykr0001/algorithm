#include<iostream>
#include<algorithm>

//퀵소트하면 시간제한 걸림
 
using namespace std;

class meeting {
public:
	   int start, end;
};

bool cmp(const meeting* p1, const meeting* p2){
    if((*p1).end < (*p2).end){
        return true;
    }
    else if((*p1).end == (*p2).end){
        return (*p1).start < (*p2).start;
    }
    else{
        return false;
    }
}

int main(void){
	meeting* temp;
	int N,count=1;
	cin >> N;
	meeting **meetings = new meeting*[N];
	for(int i=0; i<N; ++i){
		meetings[i] = new meeting;
	} 
	
	for(int i=0; i<N; ++i){ // initialize
		cin >> (*meetings[i]).start >> (*meetings[i]).end; 
	}

	sort(meetings, meetings+N, cmp);
	
	for(int i=0,j=1; j<N; ++j){
		if((*meetings[i]).end <= (*meetings[j]).start){
		++count;
		i=j;
		}
	}

 	cout << count << endl;
	return 0; 
}
