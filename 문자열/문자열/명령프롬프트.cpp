#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	string ans;
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (i == 0)
		{
			ans = s;
			continue;
		}
		for (int j = 0; j < s.size(); j++)
		{
			if (ans[j] != s[j])
				ans[j] = '?';
		}
	}
	cout << ans << '\n';
}