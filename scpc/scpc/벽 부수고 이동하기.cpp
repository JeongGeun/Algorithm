#include<iostream>
#include<queue>
#include<utility>
#include<string.h>
#include<string>
using namespace std;


int arr[1002][1002];
int visit[1002][1002][2];
int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs()
{
	deque<pair<pair<int, int>,int >>q;
	q.push_back(make_pair(make_pair(1, 1), 1));
	visit[1][1][1]++;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop_front();

		if (x == N && y == M)
			return visit[x][y][block];
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
			{
				if (arr[nx][ny] == 1 && block)
				{
					visit[nx][ny][block - 1] = visit[x][y][block] + 1;
					q.push_back(make_pair(make_pair(nx, ny), block-1));
				}
				else if (arr[nx][ny] == 0 && visit[nx][ny][block]==0)
				{
					visit[nx][ny][block] = visit[x][y][block] + 1;
					q.push_back(make_pair(make_pair(nx, ny), block));
				}

			}
		}
	}
	
	return -1;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
	{
		string m;
		cin >> m;
		for (int j = M; j >= 1; j--)
		{
			arr[i][j] =m[j-1]-'0' ;
		}
		
	}

	cout << bfs() << "\n";
}