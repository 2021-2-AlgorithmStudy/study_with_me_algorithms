#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool dfsVisited[1002] = { false, };
bool bfsVisited[1002] = { false, };
//�� bfs rqueue�� �Ѱ����� ���߿� �˾ƺ��� �ҵ�
queue<int> bfsRq;
int dfsCount = 0, bfsCount = 0;

//preorder�� ����� dfs 1. ���� ������ϰ� link�� Ÿ�� ��
void dfs(vector<vector<int>> temp, int v, int n)
{
    //ó���� ���� v�� �� : ó�� ���� vertex
    //������ ���� : n
    dfsVisited[v] = true;
    cout << v << " ";

    if (dfsCount == n) return;

    for (int i = 0; i < temp[v].size(); i++)
    {
        if (dfsVisited[temp[v][i]] == false)
        {
            dfsCount++;
            dfs(temp, temp[v][i], n);
        }
    }

}

//levelorder�� ����ϰ�, ������ �͵� ���� �湮�ϴ� ���
void bfs(vector<vector<int>> temp, int v, int n)
{
    bfsVisited[v] = true;
    bfsRq.push(v);

    while (!bfsRq.empty())
    {
        int tmp = bfsRq.front();
        bfsRq.pop();

        cout << tmp << " ";
        for (int i = 0; i < temp[tmp].size(); i++)
        {
            if (bfsVisited[temp[tmp][i]] == false)
            {
                bfsRq.push(temp[tmp][i]);
                bfsVisited[temp[tmp][i]] = true;

            }
        }
    }
}

int main()
{
    //cin�� flush ���ָ鼭 ������ cout �Լ��� ����ߴٸ� ����� ����� �� ���̴�.
    cin.tie(NULL);

    std::ios::sync_with_stdio(false);
    //�����ǰ���, ������ ����, ó�� ���� vertex 
    int N, M, V;
    cin >> N >> M >> V;


    vector<vector<int>> arr(N + 1);

    //temp���� �ؼ� �� �����ϴ� ���
    //�켱 ��� vertex�� �ش��ϴ� ��� link�� ���� �� �־��ش�.
    for (int i = 0; i < M; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr[temp1].push_back(temp2);
        arr[temp2].push_back(temp1);
    }

    //���Ŀ� sort�� ���ִ� ���
    //�ϳ��� �������� ������ Ž���� �� node���� ���������� �����ϱ� ���ؼ�
    for (int i = 1; i <= N; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }

    dfs(arr, V, N);
    cout << "\n";
    bfs(arr, V, N);

    return 0;
}