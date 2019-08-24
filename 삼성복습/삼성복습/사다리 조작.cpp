#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

int N,H,M;
int link[40][40];
int ret=-1;
int a, b;
void check(int garo)
{
	int cnt = 0;
	for (int j = 1; j <= N; j++)
	{
		int x = j;
		for (int i = 1; i <= H; i++)
		{
			if (link[i][x])
			{
				x++;
			}
			else if (link[i][x-1])
			{
				x--;
			}
		}
		if (x == j) continue;
		else return;
	}
	ret = garo;
}


void go(int num,int cnt,int garo)
{
	if (ret > -1) return;
	if (cnt == garo)
	{
		check(garo);
		return;
	}

	for (int i = num; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (link[i][j - 1] || link[i][j] || link[i][j + 1]) continue;
				
			link[i][j]++;
			go(i, cnt + 1, garo);
			link[i][j]--;
				
		}
	}
	
}

int main()
{
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		link[a][b]++;
	}
	for (int i = 0; i < 4; i++)
	{
		go(1,0,i);
		if (ret > -1)
		{
			cout << ret << endl;
			return 0;
		}
	}
	cout << ret<< endl;
}