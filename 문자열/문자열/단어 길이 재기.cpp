#include<iostream>
#include<string>
using namespace std;

int arr[26];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			cout << s[i];
		}
	}
	
}