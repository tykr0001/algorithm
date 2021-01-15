#include<iostream>
#include<vector>
using namespace std;

struct input
{
    int is_same_parent;
    int a;
    int b;
};

int getParent(int parent[], int x)
{
    if(parent[x] = x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

void Parent_Same(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);

    if(a == b)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main(void)
{
    int n, m, i, j;
    cin>> n;
    cin>> m;

    int parent[n];
    vector<input> input_var(m);

    for(i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for(i = 0; i < m; i++)
    {
        cin>> input_var[i].is_same_parent >> input_var[i].a >> input_var[i].b;
    }

    for(i = 0; i < m; i++)
    {
        if(input_var[i].is_same_parent == 0)
            unionParent(parent, input_var[i].a, input_var[i].b);
        else if(input_var[i].is_same_parent == 1)
            Parent_Same(parent, input_var[i].a, input_var[i].b);
    }

}