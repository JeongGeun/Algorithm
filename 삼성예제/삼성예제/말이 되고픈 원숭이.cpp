#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

struct horse
{
	int x;
	int y;
	int cnt;
};
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int dx2[] = {-1,-2,-2,-1,1,2,2,1};
int dy2[] = { -2,-1,1,2,2,1,-1,-2 };
int W, H;
int arr[201][201];
int visit[201][201][31];
int k;
deque<horse>q;


int bfs()
{
	memset(visit, -1, sizeof(visit));
	visit[0][0][0]++;
	q.push_back({0,0,0});
	while (!q.empty())
	{
		int nx = q.front().x;
		int ny = q.front().y;
		int nd = q.front().cnt;
		q.pop_front();
		if (visit[H-1][W-1][nd]!=-1) return visit[H-1][W-1][nd];
		for (int i = 0; i < 8; i++)
		{
			int xx = nx + dx2[i];
			int yy = ny + dy2[i];
			int nnd = nd + 1;
			if (xx >= 0 && xx < H&&yy >= 0 && yy < W&&nnd <= k)
			{
				if (visit[xx][yy][nnd]==-1&&!arr[xx][yy])
				{
					q.push_back({ xx,yy,nnd });
					visit[xx][yy][nnd] = visit[nx][ny][nd] + 1;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < H&&yy >= 0 && yy < W)
			{
				if (visit[xx][yy][nd]==-1 && !arr[xx][yy])
				{
					q.push_back({ xx,yy,nd });
					visit[xx][yy][nd] = visit[nx][ny][nd] + 1;
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin >> k;
	cin >> W >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout<<bfs()<<endl;
}