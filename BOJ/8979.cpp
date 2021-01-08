#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef struct country{
    int number;
    int gold;
    int silver;
    int bronze;
} country;

bool compare(country& a, country& b){ //내림차순 
    if(a.gold != b.gold) return a.gold > b.gold;
    else if(a.silver != b.silver) return a.silver > b.silver;
    else return a.bronze > b.bronze;
}

int main(void){
    int N,K,rating=1;
    srand(time(NULL));
    cin >> N >> K;
    vector<country> countrys;
    
    countrys.resize(N);
    for(int i=0; i<N; ++i){
        cin >> countrys[i].number >> countrys[i].gold >> countrys[i].silver >> countrys[i].bronze;
        /*countrys[i].number = i+1;
        countrys[i].gold = rand()%10;
        countrys[i].silver = rand()%10;
        countrys[i].bronze = rand()%10;*/
    }
    
    sort(countrys.begin(), countrys.end(), compare);
    
    if(countrys[0].number == K){
        cout << rating;
        return 0;
    }
    
    for(int i=1; i<N; ++i){
        if(!(countrys[i].gold == countrys[i-1].gold && countrys[i].silver == countrys[i-1].silver && countrys[i].bronze == countrys[i-1].bronze))
            rating = i+1;
        if(countrys[i].number == K) break;
        
        //cout << countrys[i].number << " " << countrys[i].gold << " " << countrys[i].silver << " " << countrys[i].bronze << endl;
    }
    cout << rating;
}
