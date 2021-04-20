#include <iostream>
#include <algorithm>
using namespace std;
int X;
int dp[30001] = { 0, };
int get_one(int value) {
	
	if (value == 1) return 0;
	if (dp[value] != 0) return dp[value];
	
	int n1 = 30001, n2 = 30001, n3 = 30001, n4 = 30001;
	if (value % 5 == 0) {
		n1 = get_one(value / 5) + 1;
	}
	if (value % 3 == 0) {
		n2 = get_one(value / 3) + 1;
	}
	if (value % 2 == 0) {
		n3 = get_one(value / 2) + 1;
	}
	if (value - 1 >= 1) {
		n4 = get_one(value - 1) + 1;
	}
	int min_1 = min(n1, n2);
	int min_2 = min(n3, n4);

	return dp[value] = min(min_1, min_2);
	
}

int main() {
	cin >> X;

	////å�� Ǯ�� 
	//int d[30001];
	//// ���̳��� ���α׷���(Dynamic Programming) ����(���Ҿ�)
	//for (int i = 2; i <= X; i++) {
	//	// ������ ������ 1�� ���� ���
	//	d[i] = d[i - 1] + 1;
	//	// ������ ���� 2�� ������ �������� ���
	//	if (i % 2 == 0)
	//		d[i] = min(d[i], d[i / 2] + 1);
	//	// ������ ���� 3���� ������ �������� ���
	//	if (i % 3 == 0)
	//		d[i] = min(d[i], d[i / 3] + 1);
	//	// ������ ���� 5�� ������ �������� ���
	//	if (i % 5 == 0)
	//		d[i] = min(d[i], d[i / 5] + 1);
	//}
	//cout << d[X] << '\n';


	int answer = get_one(X);
	cout << answer << endl;
}