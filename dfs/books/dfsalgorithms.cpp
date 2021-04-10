#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> visited(9, false);
vector<int> graph[9];

void dfs(int node)
{
    visited[node] = true;
    cout << node << ' ';
    //����� �ٸ� ��带 ��������� �湮
    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextnode = graph[node][i];
        if (visited[nextnode]==false) dfs(nextnode);
    }
}

int main_dfs()
{
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	sort(graph[1].begin(), graph[1].end());

    // ��� 2�� ����� ��� ���� ���� 
    graph[2].push_back(1);
    graph[2].push_back(7);

    // ��� 3�� ����� ��� ���� ���� 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // ��� 4�� ����� ��� ���� ���� 
    graph[4].push_back(3);
    graph[4].push_back(5);

    // ��� 5�� ����� ��� ���� ���� 
    graph[5].push_back(3);
    graph[5].push_back(4);

    // ��� 6�� ����� ��� ���� ���� 
    graph[6].push_back(7);

    // ��� 7�� ����� ��� ���� ���� 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // ��� 8�� ����� ��� ���� ���� 
    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs(1);
    return 0;
}