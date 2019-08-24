#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int, int>pic;
int N;
int arr[20][20];
int visit[20][20];

int bfs()
{
	deque<pair<pic,int>>q;
	visit[1][1]++;
	visit[1][2]++;
	q.push_back(make_pair(pic(1, 2),0));
	while (!q.empty())
	{
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int last = q.front().second;
		q.pop_front();
		if (last == 0)
		{
			int dx[2] = {0,1};
			int dy[2] = {1,1};
			for (int i = 0; i < 2; i++)
			{
				int xx = nx + dx[i];
				int yy = ny + dy[i];
				if (xx >= 1 && xx <= N && yy >= 1 && yy <= N)
				{
					if (!arr[xx][yy])
					{
						if (i == 0)
						{
							visit[xx][yy]++;
							q.push_back(make_pair(pic(xx, yy), 0));
						}
						else if (i == 1)
						{
							if (!arr[xx - 1][yy] && !arr[xx][yy - 1])
							{
								q.push_back(make_pair(pic(xx, yy), 2));
								visit[xx][yy]++;
							}
						}
					}
				}
			}
		}
		else if (last == 1)
		{
			int dx[2] = { 1,1 };
			int dy[2] = { 0,1 };
			for (int i = 0; i < 2; i++)
			{
				int xx = nx + dx[i];
				int yy = ny + dy[i];
				if (xx >= 1 && xx <= N && yy >= 1 && yy <= N)
				{
					if (!arr[xx][yy])
					{
						if (i == 0)
						{
							visit[xx][yy]++;
							q.push_back(make_pair(pic(xx, yy), 1));
						}
						else if (i == 1)
						{
							if (!arr[xx - 1][yy] && !arr[xx][yy - 1])
							{
								q.push_back(make_pair(pic(xx, yy), 2));
								visit[xx][yy]++;
							}
						}
					}
				}
			}
		}
		else if (last == 2)
		{
			int dx[3] = { 0,1 ,1};
			int dy[3] = { 1,0, 1};
			for (int i = 0; i < 3; i++)
			{
				int xx = nx + dx[i];
				int yy = ny + dy[i];
				if (xx >= 1 && xx <= N && yy >= 1 && yy <= N)
				{
					if (!arr[xx][yy])
					{
						if (i == 0)
						{
							visit[xx][yy]++;
							q.push_back(make_pair(pic(xx, yy), 0));
						}
						else if (i == 1)
						{
							visit[xx][yy]++;
							q.push_back(make_pair(pic(xx, yy), 1));
						}
						else if (i == 2)
						{
							if (!arr[xx - 1][yy] && !arr[xx][yy - 1])
							{
								q.push_back(make_pair(pic(xx, yy), 2));
								visit[xx][yy]++;
							}
						}
					}
				}
			}
		}
	}
	return visit[N][N];
}


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
	cout<<bfs()<<endl;



}