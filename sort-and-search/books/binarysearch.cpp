#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int binarySearch(vector<int> arr, int target, int start, int end)
{
	//����Լ����� ���� Ż���ϳ�
	if (start>end) return -1;

	int mid = (start + end) / 2;

	//target�� ���� mid�� ���� ���
	if (arr[mid] == target)
	{
		return mid;
	}
	else if (arr[mid] > target)
	{
		binarySearch(arr, target, start, mid - 1);
	}
	else
	{
		binarySearch(arr, target, mid + 1, end);
	}
}

int main()
{
	time_t start_time = time(0);
	//��ü input������ ã������ target�� �Է�
	int n, target;
	cin >> n >> target;

	vector<int> arr(n,0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int answer = binarySearch(arr, target, 0, n - 1);

	//�������� ���� ��
	if (answer == -1)
	{
		cout << "�迭�ȿ� target�� �������� �ʴ´�" << endl;
	}

	else
	{
		cout << "�迭�ȿ��� �� target�� ��ġ�� : " << answer << endl;
	}

	time_t end_time = time(0);

	cout << "time : " << end_time - start_time << endl;
	return 0;
}