#include <iostream>

using namespace std;

int cnt; // 입력받고자 하는 배열 크기
typedef struct triple { // x,y,z 의 의미는 D[x]+D[y]=D[z]
    int x, y, z;
} triple;

triple X; //x,y,z를 getSum을 통해서 반환받기 위한 전역변수

void sort(int* arr, int l, int r); //퀵소트
int partition(int* arr, int l, int r); //퀵소트의 분할
void swap(int* a, int* b); //스왑함수
triple getSum(int* arr); //x,y,z를 구하기 위한 코드. 만약 tuple수가 존재하지 않을 경우 -1을 리턴
void print(int*); //배열 출력

int main() {
    cin >> cnt;

    int* arr = new int[cnt]; // 입력받기
    for (int i = 0; i < cnt; i++) {
        cin >> arr[i];
    }
    if (cnt < 3) { //입력이 3이상이여야 문제가 성립
        cout << "Error. Input Number is less than 3" << endl;
        return 0;
    }
    sort(arr, 0, cnt - 1); //퀵소트 
    triple temp = getSum(arr); //getSum을 통해서 x,y,z를 구한다

    if (temp.x == -1 && temp.y == -1 && temp.z == -1) cout << "There is no triple number " << endl; //tuple수가 존재하지 않음
    else {
        cout << "정렬되었을 경우 " << endl;
        print(arr);
        cout << temp.x + 1 << "번째\t" << temp.y + 1 << "번째\t" << temp.z + 1 << "번째\t" << endl;
    }
    return 0;
}

triple getSum(int* arr) {

    triple temp;
    for (int z = cnt - 1; z >= 2; z--) { //3.3문제의 풀이방법을 cnt-2번 적용시키기 위한 루프문
        int x = 0;
        int y = z - 1;

        while (arr[x] + arr[y] != arr[z]) { //3.3문제의 풀이방법 적용. 시간복잡도 O(n)
            if (arr[x] + arr[y] > arr[z]) y--;
            else if (arr[x] + arr[y] < arr[z]) x++;
            if (x == y) { //x,y,z가 존재하지않음으로 다음으로 넘어가기 위해서 -1을 넣어줌
                x = -1;
                y = -1;
                break;
            }
        }
        if (x != -1 && y != -1) { //조건을 만족하는 x,y,z가 존재하므로 각 값을 리턴
            temp.x = x;
            temp.y = y;
            temp.z = z;
            return temp;
        }
        cout << endl;
    }
    //tuple수가 없을 경우
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