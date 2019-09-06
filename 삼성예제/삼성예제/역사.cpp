#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int arr[6] = { 500,100,50,10,5,1 };

int main()
{
	int n = 0;
	cin >> n;
	int ans = 0;
	n = 1000 - n;
	for (int i = 0; i < 6; i++)
	{
		ans+= n/arr[i];
		n %= arr[i];
	}
	cout << ans << endl;
}