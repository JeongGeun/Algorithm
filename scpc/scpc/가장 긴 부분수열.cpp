#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int arr[1001];
int n;
int ans;
int dp[1001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ma = 0;
	for (int i = 0; i < n; i++)
	{
		int mi = 0;
		for (int j = i; j >= 0; j--)
		{
			if (arr[i] > arr[j])
			{
				if (dp[j] > mi)
					mi = dp[j];
			}
		}
		dp[i] = mi + 1;
		if (ma < dp[i])
			ma = dp[i];
	}
	cout << ma << endl;
}