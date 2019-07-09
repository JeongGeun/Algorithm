#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] - 'a' == 0 || s[i] - 'a' == 4 || s[i] - 'a' == 8 || s[i] - 'a' == 14 || s[i] - 'a' == 20)
			ans++;
	}
	cout << ans;

}