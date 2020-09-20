#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, max_count=0, cur_count=0;
    string answer;
    cin >> N;
    
    vector<string> books;
    books.resize(N);
    
    for(int i=0; i<N; ++i){
        string input;
        cin >> input;
        books[i] = input;
    }
    
    sort(books.begin(), books.end());
    
    answer = books[0];
    
    for(int i=1; i<N; ++i){
        if(books[i] == books[i-1]) cur_count++;
        else if(cur_count > max_count){
            max_count = cur_count;
            answer = books[i-1];
            cur_count = 0;
        }
        else{
            cur_count = 0;
        }
    }
    if(cur_count > max_count) answer = books[N-1];
    
    cout << answer;
}
