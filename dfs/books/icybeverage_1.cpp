#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int N, M;
int graph[1000][1000];

bool dfs(int x, int y)
{
	//������ ����� ����
	if (x <= -1 || x >= N || y <= -1 || y >= M) return false;

	//��带 �湮���� �ʾ�����
	if(graph[x][y] == 0)
	{
		graph[x][y] = 1;

		//�����¿�
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}

	return false;
}

int main()
{
	time_t start_time = time(0);
	//dfsȰ�� //vector(stack)
	cin >> N >> M;

	//������� �Է¹ޱ�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &graph[i][j]);
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//��� �湮�ϸ� true�� ��ȯ�ϴ� dfs��� �Լ�
			if (dfs(i, j)) result += 1;
		}
	}

	cout << result << endl;

	time_t end_time = time(0);

	cout << "time: " << end_time - start_time << endl;
	return 0;

}