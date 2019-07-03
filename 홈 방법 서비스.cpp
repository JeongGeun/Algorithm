#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;



int T, N,M;
int arr[21][21];
deque<pair<int, int>>q;
int ans;
int visit[21][21];
int cnt;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


void bfs(int x,int y)
{
	visit[x][y]++;
	q.push_back(make_pair(x, y));
	int cost = 0;
	int ret = 0;
	if (arr[x][y] == 1)
		ret++;
	if(cost<= (M*ret-(cnt*cnt+(cnt-1)*(cnt-1)) ) )
	{
		ans = max(ans,ret);
	}
	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop_front();
			for (int j = 0; j < 4; j++)
			{
				int xx = nx + dx[j];
				int yy = ny + dy[j];
				if (xx >= 0 && xx < N&&yy >= 0 && yy < N)
				{
					if (!visit[xx][yy])
					{
						visit[xx][yy]++;
						q.push_back(make_pair(xx, yy));
						if (arr[xx][yy] == 1)
							ret++;
					}
				}
			}
		}
		if (!q.empty())
		{
			cnt++;
		}
		if (cost <= (M*ret - (cnt*cnt + (cnt - 1)*(cnt - 1))))
		{
			ans = max(ans, ret);
		}

	}
	q.clear();
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M;
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
				cnt++;
				bfs(i, j);
				cnt = 0;
				memset(visit, 0, sizeof(visit));
			}
		}

		cout << "#" <<t<< " " << ans << "\n";
		ans = 0;
		memset(arr, 0, sizeof(arr));
	}



}