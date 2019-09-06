#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

struct pic {
	int x;
	int y;
};
char arr[102][102];
int visit[102][102];
int n;
int dx[] = {1,0,-1,0};
int dy[] = { 0,1,0,-1 };

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int ret1 = 0;
	int ret2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				deque<pic>q;
				char tmp[2];
				ret1++;
				tmp[0] = arr[i][j];
				visit[i][j]++;
				q.push_back({i,j});
				while (!q.empty())
				{
					int nx = q.front().x;
					int ny = q.front().y;
					q.pop_front();
					for (int i = 0; i < 4; i++)
					{
						int xx = nx + dx[i];
						int yy = ny + dy[i];
						if (xx >= 0 && xx < n&&yy >= 0 && yy < n)
						{
							if (arr[xx][yy] == tmp[0] && !visit[xx][yy])
							{
								visit[xx][yy]++;
								q.push_back({ xx,yy });
							}
						}
					}
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				deque<pic>q;
				char tmp[2];
				ret2++;
				tmp[0] = arr[i][j];
				q.push_back({ i,j });
				visit[i][j]++;
				while (!q.empty())
				{
					int nx = q.front().x;
					int ny = q.front().y;
					q.pop_front();
					for (int i = 0; i < 4; i++)
					{
						int xx = nx + dx[i];
						int yy = ny + dy[i];
						if (xx >= 0 && xx < n&&yy >= 0 && yy < n)
						{
							if (arr[xx][yy] == tmp[0] && !visit[xx][yy])
							{
								visit[xx][yy]++;
								q.push_back({ xx,yy });
							}
						}
					}
				}
			}
		}
	}
	cout << ret1 << " " << ret2 << endl;
}