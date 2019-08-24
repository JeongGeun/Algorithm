#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

int N,x,y,d,g;
int arr[101][101];
int dx[] = {0,-1,0,1};
int dy[] = { 1,0,-1,0 };

int main()
{
	cin >> N;
	for (int t = 0; t < N; t++)
	{
		cin >> y >> x >> d >> g;
		vector<int>v;
		v.push_back(d);
		arr[x][y]++;
		for (int m = 0; m < g; m++)
		{
			int vsize = v.size();
			for (int i = vsize-1; i >=0; i--)
			{
				v.push_back((v[i] + 1) % 4);
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			int nx = x + dx[v[i]];
			int ny = y + dy[v[i]];
			if (nx >= 0 && nx <= 100 && ny >= 0 && ny <= 100)
			{
				arr[nx][ny]++;
				x = nx;
				y = ny;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1])
			{
				ans++;
			}
		}
	}
	cout << ans << endl;


}