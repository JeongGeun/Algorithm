#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

struct g {
	int x;
	int y;

};
int arr[10][9];
int visit[10][9];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int r1, r2;
int er, ec;
deque<g>q;
void bfs()
{
	while (!q.empty())
	{
		int nx = q.front().x;
		int ny = q.front().y;
		q.pop_front();
	
		for (int d = 0; d < 4; d++)
		{
			int ddx1[] = {-1,-1};
			int ddy1[] = { -1,1 };
			int ddx2[] = { 1,-1 };
			int ddy2[] = { 1,1 };
			int ddx3[] = { 1,1 };
			int ddy3[] = {1,-1};
			int ddx4[] = {1,-1};
			int ddy4[] = {-1,-1};

			int xx = nx + dx[d];
			int yy = ny + dy[d];
			if (xx >= 0 && xx < 10 && yy >= 0 && yy < 9)
			{
				if (!arr[xx][yy])
				{
					if (d == 0)
					{
						int nnx, nny;
						for (int j = 0; j < 2; j++)
						{
							int cnt = 0;
							for (int i = 0; i < 2; i++)
							{
								nnx = xx + ddx1[j] * (i + 1);
								nny = yy + ddy1[j] * (i + 1);
								if (nnx >= 0 && nnx < 10 && nny >= 0 && nny < 9)
								{
									if (i==1&&nnx == er && nny == ec)
									{
										visit[nnx][nny] = visit[nx][ny] + 1;
										cout << visit[nnx][nny] << endl;
										return;
									}
									if (!arr[nnx][nny])
									{
										cnt++;
									}
								}
							}
							if (cnt == 2)
							{
								if (visit[nnx][nny] == -1)
								{
									q.push_back({ nnx,nny });
									visit[nnx][nny] = visit[nx][ny] + 1;
								}
							}
						}
	
					}
					if (d == 1)
					{
						
						int nnx, nny;
						for (int j = 0; j < 2; j++)
						{
							int cnt = 0;
							for (int i = 0; i < 2; i++)
							{
								nnx = xx + ddx2[j] * (i + 1);
								nny = yy + ddy2[j] * (i + 1);
								if (nnx >= 0 && nnx < 10 && nny >= 0 && nny < 9)
								{
									if (i == 1 && nnx == er && nny == ec)
									{
										visit[nnx][nny] = visit[nx][ny] + 1;
										cout << visit[nnx][nny] << endl;
										return;
									}
									if (!arr[nnx][nny])
									{
										cnt++;
									}
								}
							}
							if (cnt == 2)
							{
								if (visit[nnx][nny] == -1)
								{
									q.push_back({ nnx,nny });
									visit[nnx][nny] = visit[nx][ny] + 1;
								}
							}
						}
					}
					if (d == 2)
					{
						int nnx, nny;
						for (int j = 0; j < 2; j++)
						{
							int cnt = 0;
							for (int i = 0; i < 2; i++)
							{
								nnx = xx + ddx3[j] * (i + 1);
								nny = yy + ddy3[j] * (i + 1);
								if (nnx >= 0 && nnx < 10 && nny >= 0 && nny < 9)
								{
									if (i == 1 && nnx == er && nny == ec)
									{
										visit[nnx][nny] = visit[nx][ny] + 1;
										cout << visit[nnx][nny] << endl;
										return;
									}
									if (!arr[nnx][nny])
									{
										cnt++;
									}
								}
							}
							if (cnt == 2)
							{
								if (visit[nnx][nny] == -1)
								{
									q.push_back({ nnx,nny });
									visit[nnx][nny] = visit[nx][ny] + 1;
								}
							}
						}
					}
					if (d == 3)
					{
						int nnx, nny;
						for (int j = 0; j < 2; j++)
						{
							int cnt = 0;
							for (int i = 0; i < 2; i++)
							{
								nnx = xx + ddx4[j] * (i + 1);
								nny = yy + ddy4[j] * (i + 1);
								if (nnx >= 0 && nnx < 10 && nny >= 0 && nny < 9)
								{
									if (i == 1 && nnx == er && nny == ec)
									{
										visit[nnx][nny] = visit[nx][ny] + 1;
										cout << visit[nnx][nny] << endl;
										return;
									}
									if (!arr[nnx][nny])
									{
										cnt++;
									}
								}
							}
							if (cnt == 2)
							{
								if (visit[nnx][nny] == -1)
								{
									q.push_back({ nnx,nny });
									visit[nnx][nny] = visit[nx][ny] + 1;
								}
							}
						}
					}
				}
			}
		}

	}
	cout << "-1" << endl;
}
int main()
{
	memset(visit, -1, sizeof(visit));
	cin >> r1 >> r2;
	cin >> er >> ec;
	visit[r1][r2]++;
	arr[er][ec]++;
	q.push_back({r1,r2});
	bfs();

}