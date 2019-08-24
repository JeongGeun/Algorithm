#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;


int N;
int arr[101][101];
int visit[101][101];
int mi=1000;
int ma = 0;
int ans = 1;
deque<pair<int, int>>q;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };


void bfs(int num) {
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < N&&yy >= 0 && yy < N)
			{
				if (arr[xx][yy] > num && !visit[xx][yy])
				{
					visit[xx][yy]++;
					q.push_back(make_pair(xx, yy));
				}
			}
		}
	}
	
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (mi > arr[i][j])
				mi = arr[i][j];
			if (ma < arr[i][j])
				ma = arr[i][j];
		}
	}
	for (int i = mi; i <ma ; i++)
	{
		int cnt = 0;
		for (int m = 0; m < N; m++)
		{
			for (int l = 0; l < N; l++)
			{
				if (arr[m][l] > i && !visit[m][l])
				{
					visit[m][l]++;
					q.push_back(make_pair(m, l));
					bfs(i);
					cnt++;
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		ans = max(ans, cnt);
	}
	cout << ans << endl;


}