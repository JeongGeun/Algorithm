#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;

typedef pair<int, int> pic;
int N, M,K;
int visit[1001][1001][11];
int map[1001][1001];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int bfs()
{
	visit[1][1][0]++;
	deque<pair<pair<int,int>,int> >q;
	q.push_back(make_pair(make_pair(1,1),0));
	while (!q.empty())
	{
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int block = q.front().second;
		q.pop_front();
		if (nx == N && ny == M)return visit[nx][ny][block];
		for (int d = 0; d < 4; d++)
		{
			int xx = nx + dx[d];
			int yy = ny + dy[d];
			if (xx <= N && xx > 0 && yy <= M && yy > 0)
			{
				if (map[xx][yy] == 1 && block <K)
				{
					if (visit[xx][yy][block + 1]) continue;
					visit[xx][yy][block+1] = visit[nx][ny][block] + 1;
					q.push_back(make_pair(make_pair(xx, yy), block+1));
				}
				else if (map[xx][yy] == 0 && !visit[xx][yy][block])
				{
					visit[xx][yy][block] = visit[nx][ny][block] + 1;
					q.push_back(make_pair(make_pair(xx, yy), block));
				}
			}

		}
	}
	return -1;
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <=M; j++)
		{
			map[i][j] = s[j-1] - '0';
		}
	}
	cout << bfs() << endl;


}