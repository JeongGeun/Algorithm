#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;


int arr[5][5][5];
int visit[5][5][5];
int ans = 987654321;
deque<pair<pair<int, int>, int>>q;
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int map[5][5][5];

int bfs()
{
	memset(visit, -1, sizeof(visit));
	visit[0][0][0]++;
	q.push_back(make_pair(make_pair(0, 0), 0));
	while (!q.empty())
	{
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int nz = q.front().second;
		q.pop_front();
		if (visit[4][4][4]!=-1) return visit[4][4][4];
		for (int d = 0; d < 6; d++)
		{
			int xx = nx + dx[d];
			int yy = ny + dy[d];
			int zz = nz + dz[d];
			if (xx >= 0 && xx < 5 && yy >= 0 && yy < 5 && zz >= 0 && zz < 5)
			{
				if (map[xx][yy][zz])
				{
					if (visit[xx][yy][zz]==-1)
					{
						visit[xx][yy][zz] = visit[nx][ny][nz]+1;
						q.push_back(make_pair(make_pair(xx, yy), zz));
					}
				}
			}
		}
	}
	return 987654321;


}

void rotate(int num)
{
	int temp[5][5] = {0,};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			temp[j][4-i] = map[num][i][j];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		map[num][i][j]=temp[i][j];
	}

}
void copy(int rnum,int num)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			map[rnum][i][j] = arr[num][i][j];
}

void stk()
{
	vector<int>v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	do {
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 5; i++)
		{
			copy(i,v[i]);
		}
		for (int a = 0; a < 4; a++)
		{
			rotate(0);
			if (!map[0][0][0]) continue;
			for (int b = 0; b < 4; b++)
			{
				rotate(1);
				for (int c = 0; c < 4; c++)
				{
					rotate(2);
					for (int d = 0; d < 4; d++)
					{
						rotate(3);
						for (int e = 0; e < 4; e++)
						{
							rotate(4);
							if (map[4][4][4]) ans= min(ans,bfs());
							if (ans == 12)
							{
								cout << ans << endl;
								exit(0);
							}
							q.clear();
						}
					}
				}
			}
		}
	} while (next_permutation(v.begin(), v.end()));
}


int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int z = 0; z < 5; z++)
				cin >> arr[i][j][z];
	stk();
	if (ans == 987654321) ans=-1;
	cout << ans << endl;
}