#include <iostream>
using namespace std;

int N;
int dp[1001] = { 0, };
int main() {
	cin >> N;

	//��ǻ� ���� = 1�� ä��� ����� 1����
	//���� = 2�� ä��� ����� 2����
	dp[1] = 1;
	dp[2] = 3;
	
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 796796;
	}

	cout << dp[N] << endl;
	return 0;

}