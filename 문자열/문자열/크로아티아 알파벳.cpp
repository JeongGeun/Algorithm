#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s[] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
	
	string alpha;
	cin >> alpha;
	int ans = 0;
	for (int i = 0; i < alpha.size(); i++)
	{
		for (int m = 0; m < 8; m++)
		{
			int l = 0;
			int j = 0;
			bool flag = false;
			for (j=i;  j < s[m].size() + i; j++)
			{
				if (j >= alpha.size())
				{
					flag = true;
					break;
				}
				if (alpha[j] != s[m][l++])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				i = i+s[m].size()-1;
				break;
			}
		}
		ans++;
	}
	cout << ans << "\n";



}