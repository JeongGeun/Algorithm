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
int N, M;
int arr[102][102];
int temp[102][102];
int visit[102][102];
deque<pic>cheese;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
deque<pic>air;
bool bfs()
{
	vector<pic>v;
	vector<pic>ch;
	bool flag = false;
	while (!cheese.empty())
	{
		int nx = cheese.front().x;
		int ny = cheese.front().y;
		cheese.pop_front();
		int rcnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 & xx < N&&yy >= 0 && yy < M)
			{
				if (temp[xx][yy]==2)
				{
					rcnt++;
				}
			}
		}
		if (rcnt >= 2) { 
			flag = true;
			v.push_back({ nx,ny }); 
		}
		else ch.push_back({ nx,ny });
	}
	
	for (int i = 0; i < v.size(); i++)
	{
		temp[v[i].x][v[i].y] = 2;
		air.push_back({v[i].x,v[i].y});
	}
	for (int i = 0; i < ch.size(); i++)
	{
		cheese.push_back({ ch[i].x,ch[i].y });
	}
	return flag;
}



void melt()
{
	
	memset(visit, 0, sizeof(visit));
	visit[0][0]++;
	air.push_back({ 0,0 });
	temp[0][0] = 2;
	while (!air.empty())
	{
		int nx = air.front().x;
		int ny = air.front().y;
		air.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 & xx < N&&yy >= 0 && yy < M)
			{
				if (!arr[xx][yy] && !visit[xx][yy])
				{
					visit[xx][yy]++;
					air.push_back({ xx,yy });
					temp[xx][yy] = 2;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
			if (arr[i][j])
			{
				cheese.push_back({ i,j });
			}
		}
	}
	while (1)
	{
		melt();
		if (bfs())ans++;
		else break;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				arr[i][j] = temp[i][j];
	}
	cout << ans << endl;
}