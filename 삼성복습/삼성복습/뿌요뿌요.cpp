#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int,int>pic;
char arr[20][20];
char temp[20][20];
int visit[20][20];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int bfs(int x, int y)
{
	deque<pic>q;
	vector<pic>v;
	visit[x][y]++;
	char tmp[2];
	tmp[0] = temp[x][y];
	q.push_back(pic(x, y));
	v.push_back(pic(x, y));
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < 12 && yy >= 0 && yy < 6)
			{
				if (tmp[0] == temp[xx][yy]&&!visit[xx][yy])
				{
					visit[xx][yy]++;
					q.push_back(pic(xx, yy));
					v.push_back(pic(xx, yy));
				}
			}
		}
	}
	if (v.size() >= 4)
	{
		temp[x][y] = '.';
		for (int i = 0; i < v.size(); i++)
		{
			temp[v[i].first][v[i].second] = '.';
		}
		return 1;
	}
	else
		return 0;

}

int main()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
		}
	}
	int ans = 0;
	while (1)
	{
		char map[20][20];
		memset(visit, 0, sizeof(visit));
		
		bool flag = false;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (temp[i][j] != '.')
				{
					if (bfs(i, j))
					{
						flag = true;
					}
				}
			}
		}
		for (int i = 10; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				int x = i;
				if (temp[i][j] != '.')
				{

					while (1)
					{
						if (x == 11) { 
							char test[2];
							test[0] = temp[i][j];
							temp[i][j] = '.';
							temp[x][j] = test[0];
							break; 
						}
						if (temp[x + 1][j] == '.')
						{
							x++;
						}
						else {
							char test[2];
							test[0] = temp[i][j];
							temp[i][j] = '.';
							temp[x][j] = test[0];
							break;
						}
					}
				}
			}
		}
		if (flag) ans++;
		else break;
	}
	cout << ans << endl;

}