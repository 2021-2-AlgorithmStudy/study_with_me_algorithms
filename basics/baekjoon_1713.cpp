#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, chart;
//student, value, time
vector<pair<int, pair<int,int>>> picture;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first < b.first) return true;
	else return false;
}

int main() {
	cin >> N;
	cin >> chart;

	for (int i = 0; i < chart; i++) {
		int who = 0;
		cin >> who;

		int find = -1;
		for (int j = 0; j < picture.size(); j++) {
			if (picture[j].first == who) {
				find = j;
				break;
			}
		}

		if (find!=-1) {
			picture[find].second.first++;
		}
		else {
			//picture�� ������ ������ ���
			if (picture.size() < N) {
				picture.push_back({ who,{1,i} });
			}
			else {
				//��õ���� Ƚ���� ���� ���� �л��� ������ ����
				int min = 1001;
				int index = 0;
				for (int j = 0; j < picture.size(); j++) {
					if (min > picture[j].second.first) {
						index = j;
						min = picture[j].second.first;
					}
					else if (min == picture[j].second.first) {
						if (picture[index].second.second > picture[j].second.second) {
							index = j;
						}
					}
				}

				picture[index].first = who;
				picture[index].second.first = 1;
				picture[index].second.second = i;
				
			}
		}

	}

	//����
	sort(picture.begin(), picture.end(), compare);

	for (int i = 0; i < N; i++) {
		if (i == N - 1) cout << picture[i].first;
		else cout << picture[i].first << " ";
	}

	return 0;
}