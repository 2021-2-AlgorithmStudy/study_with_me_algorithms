#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
//201C101 ������ ����
int dp[201][201];
int skip;

void solution(int x, int y, string answer) {

	//���� ���
	if (skip < 0) return;
	if (x == 0 && y == 0) {
		if (skip == 0) cout << answer;
		skip--;
		return;
	}
	if (dp[x+y][y] <= skip) {
		skip -= dp[x + y][y];
		return;
	}
	if (x > 0) {
		solution(x - 1, y, answer + "a");
	}
	if (y > 0) {
		solution(x, y - 1, answer+"z");
	}

}
void makedp() {
	//0���� ���� ���� mCm�� ��� ���� 0�� ���� �̿�
	//�̸� ������ ������ 
	// mCn = m-1Cn + m-1Cn-1 ����� �̿��Ѵ�.
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) {
				dp[i][j] = 1;
				continue;
			}
			else {
				dp[i][j] = min(1000000000, dp[i - 1][j - 1] + dp[i - 1][j]);
			}
		}
	}
	return;
}
int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	//�ð� ������ ���߱� ���ؼ� 
	// mCn = m-1Cn + m-1Cn-1 ����� �̿��Ѵ�.
	dp[0][0] = 1;
	makedp();

	//�� k-1�ϴ��� �𸣰ٴ�.
	skip = k - 1;
	//dp�� ������ skip���� Ŭ ��쿡 return -1
	if (dp[m + n][n] <= skip) {
		cout << "-1";
		return 0;
	}

	solution(n, m, "");
	return 0;

}

//https://chosh95.tistory.com/177