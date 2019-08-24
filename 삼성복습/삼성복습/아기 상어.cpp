#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<string.h>
#include<algorithm>
using namespace std;

typedef pair<int, int> pic;
int N;
int arr[21][21];
int visit[21][21];
deque<pic>start;
vector<pic>fish;
int ssize = 2;
int scnt;
int ans = 0;
bool flag;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };


bool check()
{
	int fl = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j])
			{
				if (arr[i][j] < ssize)
				{
					fl = 1;
				}
			}
		}
	}
	if (fl) return true;
	else return false;
}

int bfs()
{
	visit[start[0].first][start[0].second]++;
	while (!start.empty())
	{
		int qsize = start.size();
		for (int m = 0; m < qsize; m++)
		{
			int nx = start[0].first;
			int ny = start[0].second;
			start.pop_front();
			for (int i = 0; i < 4; i++)
			{
				int xx = nx + dx[i];
				int yy = ny + dy[i];
				if (xx >= 0 && xx < N&&yy >= 0 && yy < N)
				{
					if (visit[xx][yy] == -1)
					{
						if (arr[xx][yy] < ssize&&arr[xx][yy]>0)
						{
							visit[xx][yy] = visit[nx][ny] + 1;
							fish.push_back(pic(xx, yy));
						}
						if (!arr[xx][yy] || arr[xx][yy] == ssize)
						{
							visit[xx][yy] = visit[nx][ny] + 1;
							start.push_back(pic(xx, yy));
						}
					}
				}
			}
		}
		if (!fish.empty())
		{
			sort(fish.begin(), fish.end());
			arr[fish[0].first][fish[0].second] = 0;
			scnt++;
			if (scnt == ssize)
			{
				ssize++;
				scnt = 0;
			}
			start.clear();
			start.push_back(pic(fish[0].first,fish[0].second));
			return visit[fish[0].first][fish[0].second];
		}
	}
	flag = true;
	return 0;
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				start.push_back(pic(i, j));
				arr[i][j] = 0;
			}
		}
	}
	memset(visit, -1, sizeof(visit));
	while (1)
	{
		if (check()) 
		{
			ans += bfs();
			fish.clear();
			memset(visit, -1, sizeof(visit));
			if (flag) break;
		}
		else break;
	}
	cout << ans << endl;
}