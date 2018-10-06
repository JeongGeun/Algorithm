#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;


int H, M, N;
int arr[100][100][100];
int dz[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dx[] = {0,0,0,0,1,-1};
int cnt;
int cnt2;
int ret;
queue<pair<int, pair<int,int> > >Q;

void bfs()
{
	while (!Q.empty())
	{
		int qsize = Q.size();
		for (int k = 0; k < qsize; k++)
		{
			int z = Q.front().first;
			int y = Q.front().second.first;
			int x = Q.front().second.second;
			Q.pop();
			for (int i = 0; i < 6; i++)
			{
				int fx = x + dx[i];
				int fy = y + dy[i];
				int fz = z + dz[i];
				if (fx >= 0 && fx < M && fy >= 0 && fy < N && fz >= 0 && fz < H)
				{
					if (arr[fz][fy][fx] == 0)
					{

						arr[fz][fy][fx] = 1;
						Q.push(make_pair(fz,make_pair(fy,fx)));
					}
				}
			}
		}
		if (!Q.empty())
			ret++;

	}


}





int main()
{
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> arr[i][j][k];
				if (!arr[i][j][k])
					cnt++;
			}
		}
	}
	if (cnt == 0)
	{
		cout << ret << endl;
		return 0;
	}


	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (arr[i][j][k] == 1)
				{
					Q.push(make_pair(i, (make_pair(j, k))));
				}
			}
		}
	}
	bfs();
	bool flag = true;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (arr[i][j][k] == 0)
				{
					flag = false;
					break;
				}
			}
		}
	}
	if (!flag)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << ret << endl;
	}

}