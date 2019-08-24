#include<iostream>
using namespace std;

int n;
long long int dp[100001];
int main()
{
	cin >> n;
	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i-2]*3+(dp[i-1]-dp[i-2])*2)%9901;
	}
	cout << dp[n] << endl;
}