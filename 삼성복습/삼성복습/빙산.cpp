#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int, int> pic;

int N, M;
int arr[301][301];
vector<pic>v;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int temp[301][301];
int visit[301][301];
int blc;

void bfs()
{
	queue<pic>q;
	q.push(pic(v[0].first, v[0].second));
	visit[v[0].first][v[0].second]++;
	blc++;
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int xx = nx + dx[d];
			int yy = ny + dy[d];
			if (xx >= 0 && xx < N&&yy >= 0 && yy < M)
			{
				if (!visit[xx][yy])
				{
					if (arr[xx][yy])
					{
						blc++;
						q.push(pic(xx, yy));
						visit[xx][yy]++;
					}
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j]) v.push_back(pic(i, j));
		}
	}
	int ans = 0;
	bfs();
	if (blc != v.size()) {
		cout << ans << endl;
		return 0;
	}
	blc = 0;

	
	while (1)
	{
		v.clear();
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j]) {
					int cnt = 0;
					for (int d = 0; d < 4; d++)
					{
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (nx >= 0 && nx < N&&ny >= 0 && ny < M)
						{
							if (!arr[nx][ny]) cnt++;
						}
					}
					temp[i][j] = cnt;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				arr[i][j] -= temp[i][j];
				if (arr[i][j] < 0) arr[i][j] = 0;
				else if (arr[i][j] > 0)v.push_back(pic(i, j));
			}
		}
		if (v.size() == 0)
		{
			cout << "0" << endl;
			return 0;
		}
		else
		{
			ans++;
			bfs();
			if (blc != v.size()) {
				cout << ans << endl;
				return 0;
			}
			blc = 0;
		}
		
	}








}