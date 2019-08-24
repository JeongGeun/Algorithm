#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
using namespace std;

int n, m;
int arr[51][51];
int visit[51][51];
int blc;
int ans = 987654321;
vector<pair<int, int>>virus;
vector<pair<int, int>>rv;
deque<pair<int, int>>q;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int bfs()
{
	int cnt = 0;
	if (blc == cnt) return 0;
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < n&&yy >= 0 && yy < n)
			{
				if (arr[xx][yy] != 1)
				{
					if (visit[xx][yy]==-1)
					{
						visit[xx][yy] = visit[nx][ny] + 1;
						q.push_back(make_pair(xx,yy));
						if(arr[xx][yy]==0)
						cnt++;
						if (blc == cnt) return visit[xx][yy];
					}
				}
			}
		}
	}
	return 987654321;
}
void makewall(int num,int cnt)
{
	if (cnt >= m)
	{
		for (int i = 0; i < rv.size(); i++)
		{
			visit[rv[i].first][rv[i].second]++;
			q.push_back(make_pair(rv[i].first, rv[i].second));
		}
		ans = min(ans, bfs());
		q.clear();
		memset(visit, -1, sizeof(visit));
		return;
	}

	if (num >= virus.size()) return;
	else {
		rv.push_back(make_pair(virus[num].first, virus[num].second));
		makewall(num + 1,cnt+1);
		rv.pop_back();
		makewall(num + 1, cnt);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0) { 
				blc++; 
			}
			if (arr[i][j] == 2) virus.push_back(make_pair(i,j));
		}
	}
	memset(visit, -1, sizeof(visit));
	makewall(0,0);
	if (ans == 987654321) cout << "-1" << endl;
	else cout << ans << endl;

}