#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int N, T;
int arr[501][501];
bool visit[501][501];
int ans,cnt;
int dp[501][501];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


int dfs(int x,int y)
{
	if (dp[x][y] != 0) return dp[x][y];

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny < N&&nx < N&&ny >= 0 )
		{
			if (arr[nx][ny] > arr[x][y]) {
				dp[x][y] = max(dp[x][y], dfs(nx, ny));
			}
		}
	}

	dp[x][y]++;
	return dp[x][y];
}


int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//cnt++;
				//visit[i][j] = true;
				//if(!dp[i][j])
				dfs(i, j);
				ans = max(ans, dp[i][j]);
				//dp[i][j] = ans;
				//cnt=0;
				//visit[i][j] = false;
			}
		}



		cout << "#" << t << " " << ans << "\n";
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		memset(dp, 0, sizeof(dp));
		ans = 0;
	}



}