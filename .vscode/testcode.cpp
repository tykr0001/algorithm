#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int* parent;
int N, M, i, a, b, c, sum = 0;
int MAX = 0;

int getParent(int parent[], int x)
{
    if(parent[x] == x) return x; //�θ��尡 �ڱ� �ڽ��̸�
    return parent[x] = getParent(parent, parent[x]);
}

//�� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// ���� �θ� �������� Ȯ�� (���� �׷�������)
int findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b) return 1;
    else return 0;
}

//������ ��� Ŭ����
class Edge
{
    public:
        int node[2];
        int distance;
        Edge(int a, int b, int distance)
        {
            this->node[0] = a;
            this->node[1] = b;
            this->distance = distance;
        }
        bool operator < (Edge &edge)
        {
            return this->distance < edge.distance;
        }
};

int main(void)
{
    cin>> N >> M;
    vector<Edge> v;

    for(i = 0; i < M; i++)
    {
        cin>> a >> b >> c;
        v.push_back(Edge(a, b, c));
    }

    parent = new int[N+1];
    for(i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    sort(v.begin(), v.end());

    for(i = 0; i <v.size(); i++)
    {
        //����Ŭ�� �߻����� �������� 
         if(!findParent(parent, v[i].node[0], v[i].node[1]))
        {
            unionParent(parent, v[i].node[0], v[i].node[1]);
            sum += v[i].distance;
            MAX = v[i].distance;
        }
    }

    cout<< sum - MAX << "\n";

    return 0;
}