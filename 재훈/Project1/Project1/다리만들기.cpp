#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<string.h>
using namespace std;

int N;
int arr[101][101];
int cnt = 1;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int m = 987654321;
int ret;
queue < pair<int, int>>Q;
bool visited[101][101] = {false,};



void makesome(int x,int y)
{
	int num = cnt;
	arr[x][y] += num;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < N&&ny < N&&nx >= 0 && ny >= 0)
		{
			if (arr[nx][ny] == 1)
			{
				//arr[nx][ny] += num;
				makesome(nx, ny);
			}
		}
	}

};

void bfs(int num)
{
	ret = 0;
	while (!Q.empty())
	{
		int qsize = Q.size();
		for (int j = 0; j < qsize; j++)
		{
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < N&&ny < N&&nx >= 0 && ny >= 0)
				{
					if (arr[nx][ny] == 0)
					{
						if(!visited[nx][ny])
						{
							visited[nx][ny] = true;
							Q.push(make_pair(nx, ny));
						}
					}
					else if (arr[nx][ny] != num)
					{
						while (!Q.empty())
							Q.pop();
						return;
					}
				}
			}
			
		}
		if (!Q.empty())
			ret++;
		if (ret >= m)
		{
			while (!Q.empty())
				Q.pop();
			return;
		}
	}
	ret = 987654321;
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1)
			{
				makesome(i, j);
				cnt++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != 0)
			{
				int num = arr[i][j];
				Q.push(make_pair(i,j));
				bfs(num);
				memset(visited, false, sizeof(visited));
				m = min(ret, m);
			}
		}
	}
	cout << m << endl;

}