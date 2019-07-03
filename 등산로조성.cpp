#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string.h>
using namespace std;

int T,N, K;
int arr[21][21];
int ans;
int high;
vector<pair<int, int>> h;
bool visit[21][21];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int cnt;

void dfs(int x, int y)
{
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N&&ny < N&&ny >= 0)
		{
			if (arr[x][y] > arr[nx][ny])
			{
				if (!visit[nx][ny])
				{
					visit[nx][ny] = true;
					cnt++;
					dfs(nx, ny);
					visit[nx][ny] = false;
					cnt--;
				}
			}
		}
	}
	ans = max(cnt, ans);

}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> K;
		for (int i = 0;i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] > high)
					high = arr[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (high == arr[i][j])
				{
					h.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int a = 1; a <= K; a++)
				{
					arr[i][j] -= a;
					for (int m = 0; m < h.size(); m++)
					{
						if (h[m].first == i && h[m].second == j)
							continue;
						visit[h[m].first][h[m].second] = true;
						cnt++;
						dfs(h[m].first, h[m].second);
						visit[h[m].first][h[m].second] = false;
						cnt = 0;
					}
					arr[i][j] += a;
				}
			}
		}

		cout << "#" << t << " " << ans << "\n";
		ans = 0;
		h.clear();
		high = 0;
		memset(arr, 0, sizeof(arr));
	}




}