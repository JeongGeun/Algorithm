#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

struct pic
{
	int x;
	int y;
	int age;
	int stime;
	int etime;
};
int n, m,k,tc;
int arr[1000][1000];
int visit[1000][1000];
deque<pic>q;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int bfs()
{
	int time = 0;
	while (!q.empty())
	{
		int qsize = q.size();
		if (time == k)
		{
			int rcnt = 0;
			for (int i = 0; i < qsize; i++)
			{
				if (arr[q[i].x][q[i].y] == q[i].age) rcnt++;
			}
			return rcnt;
		}
		for (int a = 0; a < qsize; a++)
		{
			int x = q.front().x;
			int y = q.front().y;
			int age = q.front().age;
			int stime = q.front().stime;
			int etime = q.front().etime;
			q.pop_front();
			if (arr[x][y] != age) continue;
			if (stime != age)
			{
				stime++;
				q.push_back({ x,y,age,stime,etime });
			}
			else {
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (arr[nx][ny] < arr[x][y])
					{
						if (visit[nx][ny] == -1)
						{
							arr[nx][ny] = arr[x][y];
							visit[nx][ny] = time+ 1;
							q.push_back({ nx,ny,arr[x][y],0,0, });
						}
						else if (visit[nx][ny] == time+1)
						{
							arr[nx][ny] = arr[x][y];
							q.push_back({ nx,ny,arr[x][y],0,0, });
						}
					}
				}
				etime++;
				if (etime != age)
				{
					q.push_back({ x,y,age,stime,etime });
				}
			}
		}
		time++;
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		memset(visit, -1, sizeof(visit));
		int ans = 0;
		cin >> n >> m>>k;
		for (int i = 500; i < 500 + n; i++)
		{
			for (int j = 500; j < 500 + m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j])
				{
					q.push_back({i,j,arr[i][j],0,0});
					visit[i][j]++;
				}
			}
		}
		ans=bfs();
		q.clear();
		memset(arr, 0, sizeof(arr));
		cout << "#" << t << " "<<ans<<endl;
	}









}