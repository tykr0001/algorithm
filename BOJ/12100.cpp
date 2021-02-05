/********* github.com/tykr0001/algorithm *********\
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
*$*                                             *$*
*$*    ||||||||  ||    ||  ||   |||  |||||||    *$*
*$*       ||      ||  ||   || |||    ||    ||   *$*
*$*       ||        ||     |||       |||||||    *$*
*$*       ||        ||     || |||    ||  ||     *$*
*$*       ||        ||     ||   |||  ||   |||   *$*
*$*                                             *$*
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
\*************  2021-02-05 00:28:05  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector 
#define s stack
#define q queue 
#define l list 
#define pq priority_queue 
#define p pair
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define si stack<int>
#define qi queue<int>
#define li list<int> 
#define pii pair<int,int>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/
int n;
int mat[20][20];
// idx = ���� ����
int solve(int idx) {
    // ���̰� 5�� ���
    if (idx == 5) {
        int ret = 0;
        // ����߿� �ִ� ����� ã��
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ret = max(ret, mat[i][j]);
        return ret;
    }
    int ret = 0;
    //�����¿� 4���⿡ ���ؼ� 0��1��2��3��
    for (int i = 0; i < 4; i++) {
        //���� ���� ������ ����
        int temp[20][20];
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                temp[j][k] = mat[j][k];
        //q��(�Ǵ� ��)�� ���ؼ� ����� �����ϰ� ��ħ
        for (int q = 0; q < n; q++) {
            //������ ������ ��� ��� ���� ������
            //������ 1�Ǵ� 3�ΰ�� ������ ������
            vector<int> temp;
            for (int p = 0; p < n; p++)
                //0�� �ƴ� ���Ҹ� temp �迭�� ����
                if ((i < 2 ? mat[q][p] : mat[p][q]) != 0)
                    temp.push_back(i < 2 ? mat[q][p] : mat[p][q]);
            //������
            if (i == 1 || i == 3)
                reverse(temp.begin(), temp.end());
            vector<int> perm;
            for (int p = 0; p < temp.size(); p++)
                //���� �Ͱ� ���ؼ� ���� ��� 2��� �÷��� perm�迭�� ����, ���� ���Ҵ� �ǳ� ��
                if (p + 1 < temp.size() && temp[p] == temp[p + 1]) {
                    perm.push_back(temp[p] * 2);
                    p++;
                }
            //�ƴ� ��� �׳� ����
                else
                    perm.push_back(temp[p]);
            //�� ������ŭ 0 �߰�
            for (int p = perm.size(); p < n; p++)
                perm.push_back(0);
            //������
            if (i == 1 || i == 3)
                reverse(perm.begin(), perm.end());
            //���� ���� ������ ����
            for (int p = 0; p < n; p++)
                (i < 2 ? mat[q][p] : mat[p][q]) = perm[p];
        }
        //���� ���� �������� ����
        ret = max(ret, solve(idx + 1));
        //���� ���� ���� ����
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                mat[j][k] = temp[j][k];
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    printf("%d\n", solve(0));
    return 0;
}
