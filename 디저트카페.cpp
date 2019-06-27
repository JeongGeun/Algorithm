#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int arr[21][21];
int visit[21][21];
int desert[101];

int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };

int T, N;
int ans = -1;
int cnt;

void dfs(int x, int y,int lastx,int lasty,int dir)
{
	if (!visit[x][y])
	{
		cnt++;
		visit[x][y]++;
		desert[arr[x][y]]++;
	}
	for (int i = dir; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (i - dir < 2)
		{
			if (nx >= 0 && nx < N&&ny >= 0 && ny < N)
			{
				if (!visit[nx][ny])
				{
					if (!desert[arr[nx][ny]])
					{
						dfs(nx, ny, lastx, lasty, i);
						cnt--;
						visit[nx][ny]--;
						desert[arr[nx][ny]]--;
					}
			
				}
				else
				{
					if (nx == lastx && ny == lasty && cnt > 3)
					{
						ans = max(cnt, ans);
						return;
					}
				}
			}
		}

	}
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("sample_input.txt","r",stdin);
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
				visit[i][j]++;
				desert[arr[i][j]]++;
				cnt++;
				dfs(i, j,i,j,0);
				visit[i][j]--;
				desert[arr[i][j]]--;
				cnt = 0;
			}
		}
		memset(arr, 0, sizeof(arr));
		memset(visit,0,sizeof(visit));
		memset(desert, 0, sizeof(desert));
		if (ans < 4)
		{
			ans=-1;
		}
		cout << "#" << t << " " << ans << "\n";
		ans = -1;
		cnt = 0;
	}


	return 0;
}