#include<iostream>
#include<utility>
#include<queue>
#include<string.h>
using namespace std;

queue<pair<int, int>>start;
queue<pair<int, int>>fire;
char arr[1001][1001];
bool visited[1001][1001] = {false,};
int T, w, h;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int cnt;
bool flag;

void bfs()
{
	while (!start.empty())
	{
		int ssize = start.size();
		for (int i = 0; i < ssize; i++)
		{
			int x = start.front().first;
			int y = start.front().second;
			if (x == 0 || y == 0 || x == h - 1 || y == w - 1)
			{
				cnt++;
				cout << cnt << endl;
				return;
			}
			start.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && ny >= 0 && nx < h && ny < w)
				{
					if (arr[nx][ny] == '.')
					{
						if (!visited[nx][ny])
						{
							flag = true;
							for (int k = 0; k < 4; k++)
							{
								int ddx = nx + dx[k];
								int ddy = ny + dy[k];
								if (arr[ddx][ddy] == '*')
									flag = false;
							}
							if (flag)
							{
								visited[nx][ny] = true;
								if (nx == 0 || ny == 0 || nx == h - 1 || ny == w - 1)
								{
									cnt+=2;
									cout << cnt << endl;
									return;
								
								}
								start.push(make_pair(nx, ny));
							}
						}
					}
				}
			}

		}
		if (!start.empty())
			cnt++;
		int fsize = fire.size();
		for (int i = 0; i < fsize; i++)
		{
			int fx = fire.front().first;
			int fy = fire.front().second;
			fire.pop();
			for (int j = 0; j < 4; j++)
			{
				int ffx = fx + dx[j];
				int ffy = fy + dy[j];
				if (ffx >= 0 && ffy >= 0 && ffx < h&&ffy < w)
				{

					if (arr[ffx][ffy] == '.')
					{
						arr[ffx][ffy] = '*';
						fire.push(make_pair(ffx,ffy));
					}
				}
			}

		}
	}
	cout << "IMPOSSIBLE" << endl;


};




int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')
					start.push(make_pair(i,j));
				if (arr[i][j] == '*')
					fire.push(make_pair(i, j));

			}
		}
		bfs();
		cnt = 0;
		memset(arr,'0',sizeof(arr));
		memset(visited, false, sizeof(visited));
		while (!start.empty())
			start.pop();
		while (!fire.empty())
			fire.pop();
	}
	


}