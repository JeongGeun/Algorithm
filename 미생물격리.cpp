#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

struct Mi {
	int x;
	int y;
	int cnt;
	int dir;

};
int T, N, M, K,ans;
int x, y, cnt, dir;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<Mi> arr[1001][1001];
vector<Mi> info;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			Mi mi;
			cin >> mi.x >> mi.y >> mi.cnt >> mi.dir;
			mi.dir--;
			info.push_back(mi);
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < K; j++)
			{
				if (info[j].cnt != 0)
				{
					info[j].x += dx[info[j].dir];
					info[j].y += dy[info[j].dir];
					if (info[j].x == 0 || info[j].y == 0 || info[j].x == N - 1 || info[j].y == N - 1)
					{
						info[j].cnt /= 2;
						if (info[j].dir == 0)
							info[j].dir = 1;
						else if (info[j].dir == 1)
							info[j].dir = 0;
						else if (info[j].dir == 2)
							info[j].dir = 3;
						else if (info[j].dir == 3)
							info[j].dir = 2;
					}
				}

				if (info[j].cnt != 0)
					arr[info[j].x][info[j].y].push_back(info[j]);
			}

			for (int j = 0; j < K; j++)
			{
				if (arr[info[j].x][info[j].y].size() > 1)
				{
					int s = 0;
					int m = 0;
					int idx = 0;
					for (int a = 0; a < arr[info[j].x][info[j].y].size(); a++)
					{
						s += arr[info[j].x][info[j].y][a].cnt;
						if (arr[info[j].x][info[j].y][a].cnt > m)
						{
							m = arr[info[j].x][info[j].y][a].cnt;
						}
					}

					if (info[j].cnt != m)
					{
						info[j].cnt = 0;
					}
					else
					{
						info[j].cnt = s;
					}

				}
			}
			
			for (int a = 0; a < K; a++)
			{
				arr[info[a].x][info[a].y].clear();
			}

		}
		for (int i = 0; i < K; i++)
		{
			ans += info[i].cnt;
		}


		cout << "#" << t << " " << ans << "\n";
		ans = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				arr[i][j].clear();
		}
		info.clear();
	}







}