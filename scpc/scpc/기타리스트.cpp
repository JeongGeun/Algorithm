#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


int arr[1001];
int dp[101][1001];
int n, s, m;

int main()
{
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[0][s]++;

	for (int i = 1; i <= n; i++)
	{
		for (int v = 0; v <= m; v++)
		{
			if (!dp[i-1][v])
				continue;
			if (v + arr[i] <= m)
				dp[i][v + arr[i]]++;
			if (v - arr[i] >= 0)
				dp[i][v - arr[i]]++;
		}
	}
	int ans = -1;
	for (int i = m; i >= 0; i--)
	{
		if (dp[n][i])
		{
			ans = i;
			break;
		}
	}
	cout << ans;
}