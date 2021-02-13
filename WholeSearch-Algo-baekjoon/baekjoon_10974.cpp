#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printAnswer(vector<int> picked)
{
	for (int i = 0; i < picked.size(); i++)
	{
		cout << picked[i] << " ";
	}
	cout << "\n";
}

void pick(int n, vector<int> picked, vector<bool> check)
{
	//���� ���
	if (picked.size() == n)
	{
		printAnswer(picked);
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (check[i])
			continue;

		check[i] = true;
		picked.push_back(i);
		pick(n, picked, check);
		picked.pop_back();
		check[i] = false;
	}
}

int main()
{
	//��� ���� : ���� �⺻ ����
	int N = 0; 
	vector<int> picked;
	vector<bool> checked;

	cin >> N;

	checked.assign(N + 1, false);

	pick(N, picked, checked);

}

