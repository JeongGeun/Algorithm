#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;


int N, L, R;
int arr[51][51];
int visit[51][51];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool flag;

void bfs(int x, int y)
{
	int cnt = 1;
	int tot = 0;
	deque<pair<int, int>>q;
	q.push_back(make_pair(x, y));
	visit[x][y]++;
	tot += arr[x][y];
	vector<pair<int, int>>uni;
	uni.push_back(make_pair(x, y));
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < N&&yy >= 0 && yy < N)
			{
				if (!visit[xx][yy])
				{
					if (abs(arr[xx][yy] - arr[nx][ny]) >= L && abs(arr[xx][yy] - arr[nx][ny]) <= R)
					{
						visit[xx][yy]++;
						uni.push_back(make_pair(xx, yy));
						q.push_back(make_pair(xx, yy));
						cnt++;
						tot += arr[xx][yy];
						flag = true;
					}
				}
			}
		}
	}
	for (int i = 0; i < uni.size(); i++)
	{
		arr[uni[i].first][uni[i].second] = tot / cnt;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	while (1)
	{
		flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j])
					bfs(i, j);
			}
		}
		if (!flag) break;
		memset(visit, 0, sizeof(visit));
		ans++;
		
	}
	cout << ans << endl;
}