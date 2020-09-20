#include<iostream>
#include<list>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, count=0;
    cin >> N >> M;
    list<int> circular;
    
    for(int i=0; i<N; ++i){
        circular.push_back(i+1);
    }
    
    list<int>::iterator iter;
    int element, left, right, index;
    for(int i=0; i<M; ++i){
        index = 0;
        cin >> element;
        
        iter = circular.begin();
        
        while(iter!=circular.end()){
            if(*iter == element) break;
            ++index;
            ++iter;
        }
        
        left = index;
        right = circular.size()-index;
        
        if(left>=right) {
            count += right;
            while(right!=0){
                circular.push_front(circular.back());
                circular.pop_back();
                
                right--;
            }
        }
        else {
            count += left;
            while(left!=0){
                circular.push_back(circular.front());
                circular.pop_front();
                left--;
            }
        }
        
        circular.pop_front();
    }
    
    cout << count;
    return 0;
}
