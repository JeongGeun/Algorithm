#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int, int>pic;
int N, M;
int arr[102][102];
int temp[102][102];
int visit[102][102];
int ans = 0;
deque<pic>q;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
deque<pic>que;
void bfs2()
{
	memset(visit, 0, sizeof(visit));
	while (!que.empty())
	{
		int nx = que.front().first;
		int ny = que.front().second;
		que.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < N&&yy >= 0 && yy < M)
			{
				if (arr[xx][yy] == 0 && !visit[xx][yy])
				{
					arr[xx][yy] = 2;
					que.push_back(pic(xx, yy));
					visit[xx][yy]++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			temp[i][j] = arr[i][j];
	}

}
void bfs() {
	while (!q.empty())
	{
		int qsize = q.size();
		for (int a = 0; a < qsize; a++)
		{
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop_front();
			int rcnt = 0;
			for (int d = 0; d < 4; d++)
			{
				int xx = nx + dx[d];
				int yy = ny + dy[d];
				if (xx >= 0 && xx < N&&yy >= 0 && yy < M)
				{
					if (arr[xx][yy] == 2) rcnt++;
				}
			}
			if (rcnt >= 2) {
				temp[nx][ny] = 2;
			}
			else {
				q.push_back(pic(nx, ny));
			}
		}
		ans++;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				arr[i][j] = temp[i][j];
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
			temp[i][j] = arr[i][j];
			if (arr[i][j]) {
				q.push_back(pic(i, j));
			}
			else {
				que.push_back(pic(i, j));
			}
		}
	}
	bfs();
	cout << ans << endl;

}