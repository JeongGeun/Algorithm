#include<iostream>
#include<vector>
#include<string.h>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;


int link[100][100];
int n, h, m;
int ans = 10;

bool check() 
{
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		for (int j = 1; j <= h; j++)
		{
			if (link[j][k-1]) k--;
			else if (link[j][k])k++;
		}
			
		if (i == k) continue;
		else return false;
	}
	return true;

}


void go(int num,int cnt,int lcnt)
{
	if (ans < 10) return;
	if (cnt == lcnt)
	{
		if (check())
		{
			ans = lcnt;
		}
		return;
	}
	for (int i = num; i <=h; i++)
	{
		for (int j = 1; j <n; j++)
		{
			if (link[i][j] || link[i][j+1] || link[i][j-1]) continue;

			link[i][j]++;
			go(i, cnt + 1, lcnt);
			link[i][j]--;
		}
	}
}


int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		link[a][b]++;
	}
	
	for (int i = 0; i <= 3; i++)
	{
		go(1,0,i);
		if (ans < 10) {
			cout << ans << endl;
			return 0;
		}
	}
	ans = -1;
	cout << ans << endl;
}