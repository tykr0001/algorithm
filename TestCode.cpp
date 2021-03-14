#include <iostream>

using namespace std;

int cnt; // �Է¹ް��� �ϴ� �迭 ũ��
typedef struct triple { // x,y,z �� �ǹ̴� D[x]+D[y]=D[z]
    int x, y, z;
} triple;

triple X; //x,y,z�� getSum�� ���ؼ� ��ȯ�ޱ� ���� ��������

void sort(int* arr, int l, int r); //����Ʈ
int partition(int* arr, int l, int r); //����Ʈ�� ����
void swap(int* a, int* b); //�����Լ�
triple getSum(int* arr); //x,y,z�� ���ϱ� ���� �ڵ�. ���� tuple���� �������� ���� ��� -1�� ����
void print(int*); //�迭 ���

int main() {
    cin >> cnt;

    int* arr = new int[cnt]; // �Է¹ޱ�
    for (int i = 0; i < cnt; i++) {
        cin >> arr[i];
    }
    if (cnt < 3) { //�Է��� 3�̻��̿��� ������ ����
        cout << "Error. Input Number is less than 3" << endl;
        return 0;
    }
    sort(arr, 0, cnt - 1); //����Ʈ 
    triple temp = getSum(arr); //getSum�� ���ؼ� x,y,z�� ���Ѵ�

    if (temp.x == -1 && temp.y == -1 && temp.z == -1) cout << "There is no triple number " << endl; //tuple���� �������� ����
    else {
        cout << "���ĵǾ��� ��� " << endl;
        print(arr);
        cout << temp.x + 1 << "��°\t" << temp.y + 1 << "��°\t" << temp.z + 1 << "��°\t" << endl;
    }
    return 0;
}

triple getSum(int* arr) {

    triple temp;
    for (int z = cnt - 1; z >= 2; z--) { //3.3������ Ǯ�̹���� cnt-2�� �����Ű�� ���� ������
        int x = 0;
        int y = z - 1;

        while (arr[x] + arr[y] != arr[z]) { //3.3������ Ǯ�̹�� ����. �ð����⵵ O(n)
            if (arr[x] + arr[y] > arr[z]) y--;
            else if (arr[x] + arr[y] < arr[z]) x++;
            if (x == y) { //x,y,z�� ���������������� �������� �Ѿ�� ���ؼ� -1�� �־���
                x = -1;
                y = -1;
                break;
            }
        }
        if (x != -1 && y != -1) { //������ �����ϴ� x,y,z�� �����ϹǷ� �� ���� ����
            temp.x = x;
            temp.y = y;
            temp.z = z;
            return temp;
        }
        cout << endl;
    }
    //tuple���� ���� ���
    temp.x = -1;
    temp.y = -1;
    temp.z = -1;
    return temp;
}

void sort(int* arr, int l, int r) {
	if(l<r) {
        int p = partition(arr, l, r);
        sort(arr, l, p - 1);
        sort(arr, p + 1, r);
	}
}

int partition(int* arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i + 1;
}

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void print(int* arr) {
    for(int i =0; i < cnt; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}