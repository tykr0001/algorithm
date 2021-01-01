#include<iostream>
#include<vector>

#define MAX 2000

using namespace std;

void Eratos(vector<bool>& prime){
    for(int i=2; i<=MAX; ++i){
        if (prime[i]) {
            for (int j = 2; i * j <= MAX; ++j) {
                prime[i * j] = false;
            }
        }
    }
}

void BipartiteMatching(vector<int>& nums){

}

int main(void){
    int N;
    cin >> N;
    
    vector<bool> prime(MAX, true);
    vector<int> nums(N);
    for(int i=0; i<N; ++i){
        cin >> nums[i];
    }

    Eratos(prime);
    BipartiteMatching(nums);

}