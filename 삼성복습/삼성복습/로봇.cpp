#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

struct bot {
	int r;
	int c;
	int d;
};
int M, N;
int arr[101][101];
int visit[101][101][4];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
deque<bot>q;
int ex, ey, ed;


int main()
{
	memset(visit, -1, sizeof(visit));
	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 2; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		z--;
		if (z == 0) z = 1;
		else if (z == 1) z = 3;
		else if (z == 2) z = 2;
		else if (z == 3)z = 0;
		if (q.empty()) {
			visit[x][y][z]++;
			q.push_back({ x,y,z});
		}
		else {
			ex = x, ey = y, ed = z;
		}
	}

	while (!q.empty())
	{
		int nx = q.front().r;
		int ny = q.front().c;
		int nd = q.front().d;
		q.pop_front();
		if (nx == ex && ny == ey && nd == ed)
		{
			cout<< visit[ex][ey][ed]<<endl;
			return 0;
		}
		for (int i = 1; i < 4; i++)
		{
			int xx = nx + dx[nd] * i;
			int yy = ny + dy[nd] * i;
			if (xx<1 || xx>M || yy<1 || yy>N) break;
			if (arr[xx][yy]) break;
			if (visit[xx][yy][nd] != -1) continue;
			visit[xx][yy][nd] = visit[nx][ny][nd] + 1;
			q.push_back({xx,yy,nd});
		}
		for (int i = 0; i < 4; i++)
		{
			if (i == nd) continue;
			int k = abs(i - nd);
			if (k > 2)k = 1;
			if (visit[nx][ny][i] == -1)
			{
				q.push_back({nx,ny,i});
				visit[nx][ny][i] = visit[nx][ny][nd] + k;
			}

		}
	}

}
