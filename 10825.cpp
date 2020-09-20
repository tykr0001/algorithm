#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

class student{
public:
    string name;
    int lang;
    int eng;
    int math;
    student() {}
    student(string _name, int _lang, int _eng, int _math)
        :name(_name), lang(_lang), eng(_eng), math(_math) {}
    friend bool compare(student& a, student& b);
    void print();
};

bool compare(student& a, student& b){
    if(a.lang != b.lang) return a.lang > b.lang;
    else{
        if(a.eng != b.eng) return a.eng < b.eng;
        else{
            if(a.math != b.math) return a.math > b.math;
            else{
                return a.name < b.name;
            }
        }
    }
}

void student::print(){
    //debugging cout << name << " " << lang << " " << eng << " " << math << endl;
    cout << name << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    student students[N];
    
    for(int i=0; i<N; ++i){
        string name;
        int lang, eng, math;
        cin >> students[i].name >> students[i].lang 
            >> students[i].eng >> students[i].math;
    }
    
    sort(students, students+N, compare);
    
    for(int i=0; i<N; ++i){
        cout << students[i].name << '\n';
    }
}
