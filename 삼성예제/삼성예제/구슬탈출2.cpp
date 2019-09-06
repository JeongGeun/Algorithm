#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

struct ball {
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
};
int N, M;
bool check[11][11][11][11];
char arr[11][11];
int ex, ey,rx,ry,bx,by;
deque<ball>q;
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

void bfs()
{
	while (!q.empty())
	{
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop_front();
		if (cnt >= 10) break;
		for (int i = 0; i < 4; i++)
		{
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, nd = cnt + 1;
			while (1)
			{
				if (arr[nrx+dx[i]][nry+dy[i]] != '#')
				{
					if (arr[nrx + dx[i]][nry + dy[i]] == 'O')
					{
						nrx += dx[i];
						nry += dy[i];
						rc++;
						break;
					}
					nrx += dx[i];
					nry += dy[i];
					rc++;
					continue;
				}
				else break;
			}
			while (1)
			{
				if (arr[nbx + dx[i]][nby + dy[i]] != '#')
				{
					if (arr[nbx + dx[i]][nby + dy[i]] == 'O')
					{
						nbx += dx[i];
						nby += dy[i];
						bc++;
						break;
					}
					nbx += dx[i];
					nby += dy[i];
					bc++;
					continue;
				}
				else break;
			}
			if (nbx == ex && nby == ey) continue;
			if (nrx == ex && nry == ey)
			{
				cout << nd << endl;
				return;
			}
			if (nbx == nrx && nby == nry)
			{
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}
			if (check[nrx][nry][nbx][nby]) continue;
			check[nrx][nry][nbx][nby] = true;
			q.push_back({nrx,nry,nbx,nby,nd});
		}
	}
	cout << "-1" << endl;



}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R') rx = i, ry = j;
			else if (arr[i][j] == 'B') bx = i, by = j;
			else if (arr[i][j] == 'O') ex = i, ey = j;
		}
	}
	q.push_back({rx,ry,bx,by,0});
	check[rx][ry][bx][by] = true;
	bfs();
}