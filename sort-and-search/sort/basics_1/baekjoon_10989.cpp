#include <iostream>
using namespace std;

int N;
int cnt[10001] = { 0, };
int main() {
	cin >> N;
	//������ ������ ũ�� ������ ª�� : ��� ����
	for (int i = 0; i < N; i++) {
		int x;
		scanf_s("%d", &x);
		cnt[x]++;
	}

	for (int i = 0; i <= 10000; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}