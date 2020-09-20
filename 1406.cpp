#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int N;
    cin >> input >> N;

    list<char> line(input.begin(), input.end());
    list<char>::iterator cursor = line.end();
    
    
    for(int i=0; i<N; ++i){
        char op;
        cin >> op;
        switch(op){
            case 'L':
                if(cursor != line.begin()) cursor--;
                break;
            case 'D':
                if(cursor != line.end()) cursor++;
                break;
            case 'B':
                if(cursor != line.begin()){
                    --cursor;
                    cursor = line.erase(cursor);
                }
                break;
            case 'P':
                char input;
                cin >> input;
                line.insert(cursor, input);
                break;
        }
    }
    
    for(list<char>::iterator iter = line.begin(); iter != line.end(); ++iter){
        cout << *iter;
    }
    return 0;
}
