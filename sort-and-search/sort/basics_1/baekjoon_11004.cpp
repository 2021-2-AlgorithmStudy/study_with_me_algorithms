#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> numbers;
int main() {
	//�������� ������ �� �տ������� K��° �ִ� ��
	//NlogN
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		numbers.push_back(x);
	}

	sort(numbers.begin(), numbers.end());
	printf("%d", numbers[K-1]);

	return 0;
}
