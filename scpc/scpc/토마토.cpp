#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;


int arr[1001][1001];
int m, n;
vector<pair<int,int>>v;
deque<pair<int, int>>q;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int check = 0;
int ma = -1;

void bfs()
{
	
	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int xx = nx + dx[i];
			int yy = ny + dy[i];
			if (xx >= 0 && xx < n&&yy >= 0 && yy < m)
			{
				if (!arr[xx][yy])
				{
					arr[xx][yy] = arr[nx][ny] + 1;
					q.push_back(make_pair(xx, yy));
					check++;
					ma = max(ma, arr[xx][yy]);
				}
			}
		}
	}


}

int main()
{
	cin >> m >> n;
	int blc = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				q.push_back(make_pair(i, j));
			}
			if (arr[i][j]==0)
				blc++;
		}
	}
	bfs();
	if (blc == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	if (check == blc)
		cout << ma-1 << endl;
	else
		cout << "-1" << endl;

}