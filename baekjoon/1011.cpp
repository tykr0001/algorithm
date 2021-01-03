#include<iostream>
#include<cmath>

using namespace std;

int main(void){
	int T,x,y,temp;
	cin >> T;
	for(int i=0; i<T; ++i){
		cin >> x >> y;
		int distance = y-x;
		temp = (int)sqrt(distance);
		if(distance - pow(temp,2) >= pow(temp+1,2) - distance )
			cout << temp*2 + 1 << endl;
		else if( distance - pow(temp,2) != 0 )
	 		cout << temp*2 << endl;
		else
			cout << temp*2 - 1 << endl;
	}
	return 0;
}
/*
int count_jump(int distance, int present_move, int count);

int main(void){
	int T,x,y,distance,temp=0;
	cin >> T;
	for(int i=0; i<T; ++i){
		cin >> x >> y;
		distance = y-x;
		cout << count_jump(distance,0,0) << endl;
	}
	return 0;
}

int count_jump(int distance, int present_move,int count){
	int sum=0, temp=present_move;
	
	if(distance==0 && present_move==1) return count;
	
	count++;
	
	while(temp>0){
		sum+=temp--;
	}
	if(distance>=sum+present_move+1){
		count_jump(distance-present_move-1, present_move+1, count);	
	}
	else if(distance>=sum){
		count_jump(distance-present_move, present_move, count);	
	}
	else count_jump(distance-present_move+1, present_move-1, count);
}

/*
1 1			1	1
2 11			2
3 111			3
4 121		2	3
5 1211			4
6 1221			4
7 12211			5
8 12221			5
9 12321		3	5
10 123211		6
11 123221		6
12 123321		6
13 1233211		7
14 1233221		7
15 1233321		7
16 1234321	4	7
17 12343211		8
18 12343221		8

1
2
33
44
555
666
7777
8888
99999
...

1 2 3 3 4 4 5 5 5 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9 9 10 10 10 10 10
1 2 3 4 5 6 7 8 9 10
*/
