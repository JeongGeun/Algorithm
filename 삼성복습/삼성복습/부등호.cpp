#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;

vector<char> v;
vector<int>arr;
vector<int>temp;
vector<string>s;
int n;

void run()
{
	do {
		bool flag = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == '<')
			{
				if (temp[i] < temp[i + 1])
				{
					continue;
				}
				else
				{
					flag = true;
					break;
				}

			}
			else {
				if (temp[i] > temp[i + 1])
				{
					continue;
				}
				else
				{
					flag = true;
					break;
				}
			}

		}
		if (!flag)
		{
			string ans;
			for (int i = 0; i < temp.size(); i++)
				ans += temp[i]+'0';
			s.push_back(ans);
		}

	} while (next_permutation(temp.begin(), temp.end()));
}

void choice(int num,int cnt)
{
	if (cnt == n+1)
	{
		run();
		return;
	}
	if (num < arr.size())
	{
		temp.push_back(arr[num]);
		choice(num + 1, cnt + 1);
		temp.pop_back();
		choice(num + 1, cnt);
	}

}

int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char tmp[2];
		cin >> tmp[0];
		v.push_back(tmp[0]);
	}
	
	for (int i = 0; i < 10; i++)
		arr.push_back(i);
	choice(0, 0);
	sort(s.begin(), s.end());
	cout << s[s.size() - 1] << endl;
	cout << s[0] << endl;
}