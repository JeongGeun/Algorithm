#include<iostream>
#include<string>
using namespace std;

string s="123";
string a;
string ans = "1";
int n;

void dfs(int num, string temp)
{
	if (num > n) {
		cout <<temp << endl;
		exit(0);
	}
	for (int i = 0; i < 3; i++)
	{
		string a = temp;
		temp += s[i];
		int fl2 = 0;
		for (int j = 1; j<= num / 2; j++)
		{
			int fl = 0;
			for (int m = temp.size() - 1; m >= temp.size() - j; m--)
			{
				if (temp[m] == temp[m - j])
				{
					fl++;
				}
			}
			if (fl==j) {
				fl2 = 1;
				break;
			}
		}
		if(!fl2) dfs(num + 1, temp);
		temp = a;
	}
	
}


int main()
{
	cin >> n;
	dfs(2,ans);
}