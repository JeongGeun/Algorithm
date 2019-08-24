#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int ans = 987654321;
int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;

	for (int m = 0; m < s2.length(); m++)
	{
		int cnt = 0;
		if (m + s1.length() > s2.length()) { 
			cnt = 987654321;
			continue; 
		}
		for (int i = 0; i < s1.length(); i++)
		{
			
			if (s2[m+i] != s1[i]) cnt++;
		}
		ans = min(ans,cnt);
	}
	cout << ans << endl;

}