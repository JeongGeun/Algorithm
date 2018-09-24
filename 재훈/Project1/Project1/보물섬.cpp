#include<iostream>
#include<string.h>
#include<queue>
#include<utility>
using namespace std;

int M, N;
char arr[50][50];
int ret, cnt;
bool visited[50][50];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
queue<pair<int, int>>Q;


void bfs()
{

	while (!Q.empty())
	{
		int qsize = Q.size();
		for (int k = 0; k < qsize; k++)
		{
			int row = Q.front().first;
			int col = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int x = row + dx[i];
				int y = col + dy[i];
				if (x >= 0 && x < M&&y >= 0 && y < N)
				{
					if (arr[x][y] == 'L')
					{
						if (!visited[x][y])
						{
							visited[x][y] = true;
							Q.push(make_pair(x, y));
						}
					}
				}
			}
		}
		if (!Q.empty())
			cnt++;
	}
	if (ret < cnt)
		ret = cnt;
	cnt = 0;
}



int main()
{
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}

	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 'L')
			{
				visited[i][j] = true;
				Q.push(make_pair(i, j));
				bfs();
				memset(visited, false, sizeof(visited));
			}
		
		}
	}
	cout << ret << endl;


}