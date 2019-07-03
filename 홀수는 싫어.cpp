#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

int T, N;
int arr[301][301];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int ansh=987654321;
int ansj=987654321;
vector<pair<int, int>> dp[301][301];


pair<int, int> dfs(int x, int y, int h, int j)
{
	if (!dp[x][y].empty()) return dp[x][y][0];
	if (x == N - 1 && y == N - 1)
	{
		if (arr[x][y] % 2 == 0)
		{
			return make_pair(1, 0);
		}
		else
		{
			return make_pair(0, 1);

		}
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny < N&&nx < N&&ny >= 0)
		{
			
		}
	}

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
		if (arr[0][0] % 2 == 0)
			dfs(0, 0, 0, 1);
		else
			dfs(0, 0, 1,0);

		cout << "#" << t << " " <<ansh<<" "<<ansj<< "\n";
		memset(arr, 0, sizeof(arr));
		int ansh = 987654321;
		int ansj = 987654321;
	}


}