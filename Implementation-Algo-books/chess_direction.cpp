#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
using namespace std;

int main()
{
	//�ð� ���
	time_t start_time = time(0);

	//�Է� �ޱ�
	string input;
	cin >> input;

	//������//�������� ��ĭ �̵� �� �Ʒ�//���η� ��ĭ �̵�
	//�Ʒ���//���� ��ĭ �̵� �� ������//�������� �̵�
	int dx[] = { -2,-2,-1,-1,1,1,2,2 };
	int dy[] = { 1,-1,2,-2,2,-2,1,-1 };
	//��ü 8

	int loc1 = input.at(0) - 'a' +1;
	int loc2 = input.at(1) - '0';

	int loc1_end = 0;
	int loc2_end = 0;
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		loc1_end = loc1 + dx[i];
		loc2_end = loc2 + dy[i];
		if (loc1_end >= 1 && loc1_end <= 8 && loc2_end >= 1 && loc2_end <= 8)
			count++;

	}
	cout << count << endl;

	time_t end_time = time(0);
	cout << "time :" << end_time - start_time << endl;

	return 0;

}