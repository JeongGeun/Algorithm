#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	long long int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
			ans += arr[j];
	}
	cout << ans;


}