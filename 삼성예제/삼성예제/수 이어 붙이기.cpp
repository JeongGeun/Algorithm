#include<iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int k = 9;
	int ans = 0;
	int cnt = 1;
	while (1)
	{
		if (n - k <= 0)
		{
			ans += n * cnt;
			break;
		}
		else {
			n -= k;
			ans += k * cnt;
			cnt++;
			k *= 10;
		}
	}
	cout << ans << endl;
}