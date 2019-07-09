#include<iostream>
#include<string>
using namespace std;

string s;
int main()
{
	cin >> s;
	for (int i = 0, j = s.size() - 1; i < s.size(), j >= 0; i++, j--)
	{
		if (s[i] != s[j])
		{
			cout << "0";
			return 0;
		}
	}

	cout << "1";

}
