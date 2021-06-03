#include <iostream>
using namespace std;

int N;
int input[101];
//dp[���� N��][���� �� �ִ� ��]
unsigned long long dp[101][21] = { 0, };

void solution() {

	dp[1][input[1]] = 1;

	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			//���� ���� �����ϴ��� Ȯ��
			if (dp[i-1][j] >= 0) {
				//������ �´��� Ȯ��
				if (j - input[i] >= 0) {
					dp[i][j - input[i]] += dp[i - 1][j];
				}
				if (j + input[i] <= 20) {
					dp[i][j + input[i]] += dp[i - 1][j];
				}
			}
		}
	}
	
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i < N+1; i++) {
		cin >> input[i];
	}

	//dp�� ���� ��
	//dp[����� ��� ��] = ����� ��
	solution();

	cout << dp[N-1][input[N]] << '\n';
	return 0;
}