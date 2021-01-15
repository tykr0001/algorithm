#include<iostream>
#include<vector>
using namespace std;


struct input
{
    int is_same_parent;
    int a;
    int b;
};

vector<input> input_var;
vector<int> parent;

int getParent(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

void Parent_Same(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

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

    parent.resize(n+1);
    input_var.resize(m);

    for(i = 0; i <= n; i++)
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
            unionParent(input_var[i].a, input_var[i].b);
        else if(input_var[i].is_same_parent == 1)
            Parent_Same(input_var[i].a, input_var[i].b);
    }

}