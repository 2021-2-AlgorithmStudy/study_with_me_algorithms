#include <iostream>
using namespace std;
#define MAX 1000000

int n, r;
bool check[MAX] = { false, };
int ansArr[MAX] = { 0, };

void printArray(int* arr) {
    for (int i = 0; i < r; i++) {
        cout << arr[i] <<' ';
    }
    cout << '\n';
}

void permutation(int depth) {

    //���� ���
    if (depth == r) {
        printArray(ansArr);
        return;
    }

    //��� �Լ�
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            check[i] = true;
            ansArr[depth] = i;
            permutation(depth + 1);
            check[i] = false;
        }
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r;

    permutation(0);
    return 0;
    
 }


//https://hongchan.tistory.com/5