#include<iostream>
#include<list>

using namespace std;

int main(void){
    int N;
    list<int> card;
    cin >> N;
    
    for(int i=0; i<N; ++i){
        card.push_back(i+1);
    }
    
    while(card.size() > 1){
        cout << card.front() << " ";
        card.pop_front();
        card.push_back(card.front());
        card.pop_front();
    }
    cout << card.front();
}
