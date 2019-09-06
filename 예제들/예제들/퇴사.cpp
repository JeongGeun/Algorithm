#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

int n;
int t[17];
int p[17];
int ans;
void dfs(int num, int cnt)
{
	
	if (num<n+2)
	{
		if(num+t[num]<n+2&&p[num]) dfs(num + t[num], cnt + p[num]);
		else ans = max(ans, cnt);
		dfs(num + 1, cnt);
	}
	
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}
	dfs(1, 0);
	cout << ans << endl;
}