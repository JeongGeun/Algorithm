#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

struct pic {
	int x;
	int y;
	int dir;
	int mi;
};
int N;
char arr[51][51];
int visit[51][51][4];
deque<pic>q;
int ex, ey;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ans = 1e9;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int mi = q.front().mi;
		q.pop_front();
		if (x == ex && y == ey)
		{
			cout << mi << endl;
			return;
		}
		while (1)
		{
			int xx = x + dx[dir];
			int yy = y + dy[dir];
			if (xx < 0 || xx >= N || yy < 0 || yy >= N) break;
			if (arr[xx][yy] == '*') break;
			if (arr[xx][yy] == '!')
			{
				if (!visit[xx][yy][(dir + 1) % 4])
				{
					visit[xx][yy][(dir+1)%4]++;
					q.push_back({ xx,yy,(dir + 1) % 4,mi + 1 });
				}
				if (!visit[xx][yy][(dir + 3) % 4])
				{
					visit[xx][yy][(dir + 3) % 4]++;
					q.push_back({ xx,yy,(dir + 3) % 4,mi + 1 });
				}
			}
			else if (xx == ex && yy == ey)
			{
				if (!visit[xx][yy][dir])
				{
					q.push_back({ xx,yy,dir,mi });
				}
				break;
			}
			
			x = xx;
			y = yy;
			
		}
	}
	cout << ans << endl;
}
int main()
{
	cin >> N;
	int dir = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '#')
			{
				if (q.empty())
				{
					for (int d = 0; d < 4; d++)
					{
						visit[i][j][d]++;
						q.push_back({ i,j,d,0 });
					}
				}
				else
				{
					ex = i, ey = j;
				}
			}
		}
	}
	bfs();
}