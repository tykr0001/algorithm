#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct student{
    string name;
    int day;
    int month;
    int year;
}student;

bool compare(student& a, student& b){ //어린 순서대로 
    if(a.year != b.year) return a.year > b.year;
    else if(a.month != b.month) return a.month > b.month;
    else return a.day > b.day;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<student> students;
    students.resize(n);
    for(int i=0; i<n; ++i){
        cin >> students[i].name >> students[i].day >> students[i].month >> students[i].year;
    }
    
    sort(students.begin(), students.end(), compare);
    
    cout << students[0].name << '\n' << students[n-1].name; 
    
    return 0;
}
