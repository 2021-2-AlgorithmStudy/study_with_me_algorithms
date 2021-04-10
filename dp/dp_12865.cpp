#include<iostream>
#include<algorithm>

using std::cin; 
using std::cout;
using namespace std;

int dp_12865[100001] = { 0, };

int main()
{
	std::ios::sync_with_stdio(false);
	int ans = 0;
	int N, K, W, V;
	
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> W >> V;
		if (V <= 0) continue;

		if (K < W) continue;
		else if( K == W)
		{
			//do nothing
		}
		else
		{
			for (int cur = K - W; cur >= 1; --cur)
			{
				if (dp_12865[cur] <= 0) continue;

				dp_12865[cur + W] = max(dp_12865[cur + W], dp_12865[cur] + V);
				ans = max(ans, dp_12865[cur + W]);
			}
		}
		dp_12865[W] = max(dp_12865[W], V);
		ans = max(ans, dp_12865[W]);
	}

	cout << ans << '\n';
	
	return 0;
}
//������ �������� k���� ū w�� �Է����� ������ ���
// �Է� ���� �� �ش� ���̽� �ѱ�Բ� ���Ǹ� �߰����ָ� ��� ����
//2���� �迭���� �� �������� �޸𸮿�, �ӵ� �� �����ؼ� ���ĺ���
