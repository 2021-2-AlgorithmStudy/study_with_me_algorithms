#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

//quickSort�� ����Լ��� �̿�
void quickSort(int* arr, int start, int end)
{
	//���Ұ� 1�� �� ��
	if (start >= end) return;

	//pivot �� ���� ù ��° �� 
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		//�ǹ����� ū �����͸� ã�� ������ �ݺ�
		while ((left <= end) && arr[left] <= arr[pivot]) left++;
		//�ǹ����� ���� �����͸� ã�� ������ �ݺ�
		while (right > start&& arr[right] >= arr[pivot]) right++;

		//�����ȴٸ� ���� �����Ϳ� �ǹ��� ��ü
		if (left > right) swap(arr[right], arr[pivot]);
		else swap(arr[right], arr[left]);
	}

	//���ʰ� ������ �迭�� sort�ϱ� ����
	quickSort(arr, start, right-1);
	quickSort(arr, right + 1, end);
}

int main_1()
{
	time_t start_time = time(0);
	//quickSort(arr,0,n-1);
	//�Է°����� ��ü array�� start,end���� �޾ƿ�
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}
	time_t end_time = time(0);

	cout << "time : " << end_time - start_time << endl;

	return 0;
}