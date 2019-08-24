#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<string.h>
using namespace std;

int dx[] = { 2,2,-2,-2,1,1,-1,-1 };
int dy[] = { 1,-1,1,-1,2,-2,2,-2 };

int arr[301][301];
int n,testCase;
deque<pair<int, int>>q;
int rx, ry;
int ma = 0;

void bfs()
{
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop_front();
		for (int i = 0; i < 8; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < n&&yy < n&&yy >= 0)
			{
				if (!arr[xx][yy])
				{
					q.push_back(make_pair(xx, yy));
					arr[xx][yy] = arr[nx][ny] + 1;
					ma = max(ma, arr[xx][yy]);
				}
				if (xx == rx && yy == ry)
				{
					cout << ma << endl;
					return;
				}
			}

		}


	}
}

int main()
{
	cin >> testCase;
	for (int t = 0; t < testCase; t++)
	{
		cin >> n;
		int x = 0;
		int y = 0;
		cin >> x>>y;
		q.push_back(make_pair(x, y));
		cin >> rx >> ry;
		if (x == rx && ry == y)
		{
			cout << "0" << endl;
		}
		else bfs();
		ma = 0;
		q.clear();
		memset(arr, 0, sizeof(arr));
	}

}