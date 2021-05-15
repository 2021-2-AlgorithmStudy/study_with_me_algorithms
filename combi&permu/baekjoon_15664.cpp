#include<algorithm>
#include<iostream>
using namespace std;

bool check[8]; // �ߺ��� ���� ���� �ʱ� ���� �迭
int n, m, num[8], result[8];

// �Է¹��� n���� ���� �߿��� ����� ������ �Ȱ��� ������
// ���� �ʰ� m���� ���� ������ִ� �Լ�
void getResult(int count, int start) {

    // m���� ����ٸ� ����մϴ�
    if (count == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    int prev_num = -1; // �ٷ� ������ ����� ���� �����ϴ� ����

    // �Լ��� ���ڷ� ���� start���� ���� ���� �մϴ�
    for (int i = start; i < n; i++) {
        if (!check[i] && prev_num != num[i]) {
            check[i] = true;
            result[count] = num[i];
            prev_num = num[i];

            getResult(count + 1, i);
            check[i] = false;
        }
    }
}

int main(void) {

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n);

    getResult(0, 0);
    return 0;
}

//https://seokeeee.tistory.com/152