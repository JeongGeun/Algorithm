#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

int map[11][11];
vector<int>arr[11][11];
int N, M, K;
int a[11][11];
struct  tree
{
	int x;
	int y;
	int age;
};
vector<tree>v;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		tree t;
		cin >> t.x >> t.y >> t.age;
		v.push_back(t);
		arr[t.x][t.y].push_back(t.age);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j] = 5;
		}
	}
	for (int b = 0; b < K; b++)
	{
		int temp[11][11];
		memset(temp, 0, sizeof(temp));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (!arr[i][j].empty())
				{
					sort(arr[i][j].begin(), arr[i][j].end());
					int cnt = 0;
					for (int m = 0; m < arr[i][j].size(); m++)
					{
						if (map[i][j] >=arr[i][j][m])
						{
							map[i][j] -= arr[i][j][m];
							arr[i][j][m]++;
						}
						else
						{
							temp[i][j] += arr[i][j][m]/2;
							cnt++;
						}
					}

					for (int m = 0; m < cnt; m++) arr[i][j].pop_back();
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				map[i][j] += temp[i][j];
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (!arr[i][j].empty())
				{
					for (int k = 0; k < arr[i][j].size(); k++)
					{
						if (arr[i][j][k] % 5 == 0)
						{
							for (int d = 0; d < 8; d++)
							{
								int nx = i + dx[d];
								int ny = j + dy[d];
								if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
								{
									arr[nx][ny].push_back(1);
								}
							}
						}
					}
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				map[i][j] += a[i][j];
			}
		}

	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!arr[i][j].empty())
			{
				ans += arr[i][j].size();
			}
		}
	}
	cout << ans << endl;
}