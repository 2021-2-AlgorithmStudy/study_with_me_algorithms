//ū�� ��Ģ
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	//�ð� üũ
	//time_t  start_time = time(0);

	int N, M, K;
	int sum = 0;
	int count = 0, check = 0;
	cin >> N >> M >> K;

	vector<int> number(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
	}

	//���� vector ����(��������)
	sort(number.begin(), number.end(), comp);

	while (count != M)
	{
		if (check == 0)
		{
			for (int j = 0; j < K; j++)
			{
				sum += number[check];
				count++;
			}
			check = 1;
		}
		else
		{
			sum += number[check];
			count++;
			check = 0;
		}
	}

	cout << sum;
	//time_t end_time = time(0);

	//cout << "time : " << end_time - start_time;
	////time = 17

}