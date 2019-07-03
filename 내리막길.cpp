#include<iostream>
#include<string.h>
using namespace std;

int arr[501][501];
int dp[501][501];
int  m, n;
int ans, cnt;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int dfs(int x, int y)
{
	if (dp[x][y]!=-1) return dp[x][y];
	if (x == m - 1 && y == n - 1) return 1;
	
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m&&ny >= 0 && ny < n)
		{
			if (arr[nx][ny] < arr[x][y])
			{
				dp[x][y] += dfs(nx, ny);
			}
		}
	}

	return dp[x][y];
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	//dfs(0, 0);
	cout << dfs(0,0) << "\n";

}