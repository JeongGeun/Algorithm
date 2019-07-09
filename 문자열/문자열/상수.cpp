#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	
	for (int i = 0; i<=2 ; i++)
	{
		if (s1[i] - '0' > s2[i] - '0')
		{
			cout << s1 << "\n";
			break;
		}
		else if (s1[i] - '0' < s2[i] - '0')
		{
			cout << s2 << "\n";
			break;
		}
	}



}