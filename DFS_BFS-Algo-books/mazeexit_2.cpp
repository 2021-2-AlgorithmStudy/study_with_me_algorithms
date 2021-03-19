#include<iostream>
#include<vector>
#include<ctime>
#include<queue>
using namespace std;

int N, M;
int map[201][201];

//direction�� �̵�
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0, -1,1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	//queue�� ��������
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			//�̷θ� ��� ��� �о�
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			// ���� ��� ����
			if (map[nx][ny] == 0) continue;
			// �ش� ��带 ó�� �湮�ϴ� ��쿡�� �ִ� �Ÿ� ���
			if (map[nx][ny] == 1)
			{
				map[nx][ny] = map[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	cout << map[N - 1][M - 1] << endl;
}
int main()
{
	time_t start_time = time(0);

	//�Է¹ޱ�
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &map[i][j]);
		}
	}

	//�ּ�ĭ�� ���� bfs�� ��� //fifo
	bfs(0, 0);

	//�ð� ���
	time_t end_time = time(0);
	cout << "time: " << end_time - start_time << endl;

	return 0;

}
