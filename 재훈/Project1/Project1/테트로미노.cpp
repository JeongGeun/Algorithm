#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int N, M;
int arr[501][501];
bool visited[501][501];
int dx[] = { 1,0,-1,0 };
int dy[] = {0,1,0,-1};
int ret;
int cnt;
int cnt2;

void dfs(int row,int col,int num)
{

	if (num >=4)
	{
		ret = max(ret, cnt);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int x = row + dx[i];
		int y = col + dy[i];
		if (x >= 0 && x < N&&y >= 0 && y < M)
		{
			if (!visited[x][y])
			{
				cnt += arr[x][y];
				visited[x][y] = true;
				dfs(x, y, num + 1);
				cnt -= arr[x][y];
				visited[x][y] = false;

			}
		}
	}

}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cnt = arr[i][j];
			visited[i][j] = true;
			dfs(i, j, 1);
			visited[i][j] = false;
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && x < N&&y >= 0 && y < M)
				{
					cnt2++;
					cnt += arr[x][y];
				}
			}
			if (cnt2 == 3)
				ret = max(ret, cnt);

			if (cnt2 == 4)
			{
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					ret = max(ret, cnt - arr[x][y]);
				}
			}
			cnt2 = 0;
		}
	}
	cout << ret << endl;

}