#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool check[8]; //�ߺ��� ���� ���� �ʱ� ���� �迭
int Nums[8], result[8];

void solve(int count) {
	
	//M���� ����ٸ� ���
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int prev_num = -1;
	for (int i = 0; i < N; i++) {
		if (!check[i] && prev_num != Nums[i]) {
			check[i] = true;
			result[count] = Nums[i];
			prev_num = Nums[i];
			solve(count + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> Nums[i];
		
		//������ ������� ���� ��� with sort
	}

	sort(Nums, Nums + N);
	solve(0);
	return 0;

}

//https://seokeeee.tistory.com/151