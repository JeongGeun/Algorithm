#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

int T, N, W, H;
int arr[20][20];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int visit[20][20];
int ans = 987654321;

void bfs(int cnt,int map[][20])
{
	if (cnt == N) {
		int bcnt = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (map[i][j]) bcnt++;
			}
		}
		ans = min(ans, bcnt);
		return;
	}
	int temp[20][20];
	
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			temp[i][j] = map[i][j];
	}

	for(int i=0;i<W;i++)
	{ 
		for (int j = H - 2; j >= 0; j--)
		{
			int y = j;
			if (temp[j][i])
			{
				while (1)
				{
					if (temp[y + 1][i] == 0)
					{
						if (y + 1 == H - 1)
						{
							int tmp = temp[j][i];
							temp[j][i] = 0;
							temp[y + 1][i] = tmp;
							break;
						}
						y++;
					}
					else if (temp[y + 1][i])
					{
						int tmp = temp[j][i];
						temp[j][i] = 0;
						temp[y][i] = tmp;
						break;
					}
				}
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			int ctemp[20][20];
			for (int i = 0; i < H; i++)
			{
				for (int j = 0; j < W; j++)
				{
					ctemp[i][j] = temp[i][j];
				}
			}
			if (i == 0 && ctemp[i][j])
			{
				flag = true;
				deque<pair<int, int>>q;
				q.push_back(make_pair(i, j));
				memset(visit, 0, sizeof(visit));
				visit[i][j]++;
				while (!q.empty())
				{
					int nx = q.front().first;
					int ny = q.front().second;
					q.pop_front();
					int k = ctemp[nx][ny];
					ctemp[nx][ny] = 0;
					for (int i = 1; i < k; i++)
					{
						for (int d = 0; d < 4; d++)
						{
							int xx = nx + dx[d] * i;
							int yy = ny + dy[d] * i;
							if (xx >= 0 && xx < H&&yy >= 0 && yy < W)
							{
								if (ctemp[xx][yy])
								{
									if (!visit[xx][yy])
									{
										visit[xx][yy]++;
										q.push_back(make_pair(xx, yy));
									}
								}
							}
						}
					}
				}
				bfs(cnt + 1, ctemp);
			}
			else if (ctemp[i][j] != 0 && ctemp[i - 1][j] == 0)
			{
				flag = true;
				deque<pair<int, int>>q;
				q.push_back(make_pair(i, j));
				memset(visit, 0, sizeof(visit));
				visit[i][j]++;
				while (!q.empty())
				{
					int nx = q.front().first;
					int ny = q.front().second;
					q.pop_front();
					int k = ctemp[nx][ny];
					ctemp[nx][ny] = 0;
					for (int i = 1; i < k; i++)
					{
						for (int d = 0; d < 4; d++)
						{
							int xx = nx + dx[d] * i;
							int yy = ny + dy[d] * i;
							if (xx >= 0 && xx < H&&yy >= 0 && yy < W)
							{
								if (ctemp[xx][yy])
								{
									if (!visit[xx][yy])
									{
										visit[xx][yy]++;
										q.push_back(make_pair(xx, yy));
									}
								}
							}
						}
					}
				}
				bfs(cnt + 1, ctemp);
			}
		}
	}
	if (!flag)
	{
		int bcnt = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (map[i][j]) bcnt++;
			}
		}
		ans = min(ans, bcnt);
		return;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		ans = 987654321;
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> arr[i][j];
			}
		}
		bfs(0,arr);
		cout << "#" << t << " "<<ans<<endl;
	}


}