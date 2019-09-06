#include<iostream>
#include<queue>
using namespace std;

struct pic {
	int x;
	int y;
};
int arr[301][301];
int n, m,r;
deque<pic>q;
int dx[] = {1,0,-1,0};
int dy[] = { 0,1,0,-1 };

void rotate()
{
	for (int t = 0; t < r; t++)
	{
		int temp[301][301] = {0,};
		for (int k = 0; k < q.size(); k++)
		{
			if (!temp[q[k].x][q[k].y])
			{
				int x = q[k].x;
				int y = q[k].y;
				for (int i = 0; i < 4; i++)
				{
					while (1)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
						if (temp[nx][ny]) break;
						temp[nx][ny] = arr[x][y];
						x += dx[i];
						y += dy[i];
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = temp[i][j];
			}
		}
	}
}

int main()
{
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (i == j)q.push_back({ i,j });
		}
	}
	rotate();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}