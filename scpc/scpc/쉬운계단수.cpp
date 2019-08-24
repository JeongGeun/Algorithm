#include<iostream>
#include<string>
using namespace std;

int dp[101][10];
int n;
int md = 1000000000;

int main()
{
	cin >> n;
	for (int i = 0; i < 10; i++)
		dp[1][i]++;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) dp[i][j] = dp[i-1][j + 1]%md;
			else if (j == 9) dp[i][j] = dp[i-1][j - 1]%md;
			else dp[i][j] = (dp[i-1][j - 1] + dp[i-1][j + 1])%md;
		}
	}
	int sum = 0;
	for (int i = 1; i < 10; i++)
		sum = (sum+dp[n][i]) % md;
	cout << sum%md << endl;
}