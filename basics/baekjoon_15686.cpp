#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int answer = 1301;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<int> selected;


int distance(pair<int, int> h, pair<int, int> c) {
	return abs(h.first - c.first) + abs(h.second - c.second);
}

void combination_check(int n) {

	if (selected.size() == M) {
		int total = 0;//ġŲ �Ÿ� ����
		for (int i = 0; i < home.size(); i++) {
			int min_len = distance(home[i], chicken[selected[0]]);
			for (int j = 1; j < selected.size(); j++) {
				int len = distance(home[i], chicken[selected[j]]);
				if (min_len > len) min_len = len;
			}

			total += min_len;
		}

		if (total < answer) answer = total;
	}
	else if (n == chicken.size()) return;
	else {
		selected.push_back(n);
		combination_check(n + 1);
		//n+1��° ġŲ���� �����
		selected.pop_back();
		combination_check(n + 1);
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int number;
			cin >> number;
			if (number == 1) {
				home.push_back({ i,j });
			}
			else if (number == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	//��� ������ �� �˻�����
	combination_check(0);
	//�� ū ũ�⸦ �����ٸ� dfs��?
	
	cout << answer << '\n';
	return 0;

}

//https://koo5590.github.io/2020-05-24-B15686/