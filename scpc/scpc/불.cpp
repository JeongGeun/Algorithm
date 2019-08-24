#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<string.h>
#include<algorithm>
using namespace std;

char arr[1001][1001];
int visit[1001][1001];
int visit2[1001][1001];
int r, c;
deque<pair<int, int>>fire;
deque<pair<int, int>>p;
int dx[] = {1,-1,0,0};
int dy[] = { 0,0,1,-1 };
int ans = 0;

void bfs()
{
	while (!p.empty())
	{
		int psize = p.size();
		for (int i = 0; i < psize; i++)
		{
			int nx = p.front().first;
			int ny = p.front().second;
			p.pop_front();
			for (int j = 0; j < 4; j++)
			{
				int xx = nx + dx[j];
				int yy = ny + dy[j];
				if (xx >= 0 && xx < r&&yy >= 0 && yy < c)
				{
					bool flag = true;
					for (int m = 0; m < 4; m++)
					{
						int rx = xx + dx[m];
						int ry = yy + dy[m];
						if (rx >= 0 && rx < r&&ry >= 0 && ry < c)
						{
							if (visit2[rx][ry])
							{
								flag = false;
								break;
							}
						}
					}
					if (!flag) continue;
					if (!visit[xx][yy])
					{
						if (arr[xx][yy] == '.')
						{
							if (xx == 0 || xx == r - 1 || yy == 0 || yy == c - 1)
							{
								ans++;
								cout << ++ans << endl;
								exit(0);
							}
							visit[xx][yy]++;
							p.push_back(make_pair(xx, yy));
						}
					}
				}
			}
		}
		if (!p.empty())ans++;

		int fsize = fire.size();
		for (int i = 0; i < fsize; i++)
		{
			int nx = fire.front().first;
			int ny = fire.front().second;
			fire.pop_front();
			for (int j = 0; j < 4; j++)
			{
				int xx = nx + dx[j];
				int yy = ny + dy[j];
				if (xx >= 0 && xx < r&&yy >= 0 && yy < c)
				{
					if (arr[xx][yy] != '#')
					{
						if (!visit2[xx][yy])
						{
							visit2[xx][yy]++;
							fire.push_back(make_pair(xx, yy));
						}
					}
				}
			}
		}
	}

}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'F')
			{
				fire.push_back(make_pair(i, j));
				visit2[i][j]++;
			}
			if (arr[i][j] == 'J')
			{
				if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
				{
					cout << "1" << endl;
					return 0;
				}
				visit[i][j]++;
				p.push_back(make_pair(i, j));
			}
		}
	}
	bfs();
	cout << "IMPOSSIBLE" << endl;
}

