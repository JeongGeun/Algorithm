#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;

char s[21];
int visit[30];
int N;
long long int ans = -1e10;
vector<int>anum;
vector<char>os;

void p()
{
	long long int ret = anum[0];
	for (int i = 0; i < anum.size()-1; i++)
	{
		int k = 0;
		if (visit[i + 1])
		{
			if (os[i + 1] == '+')
			{
				k = anum[i + 1] + anum[i + 2];
			}
			if (os[i + 1] == '-')
			{
				k = anum[i + 1] - anum[i + 2];
			}
			if (os[i + 1] == '*')
			{
				k = anum[i + 1] * anum[i + 2];
			}
			if (os[i] == '+')
			{
				ret += k;
			}
			if (os[i] == '-')
			{
				ret -= k;
			}
			if (os[i] == '*')
			{
				ret *= k;
			}
			i += 1;
		}
		else
		{
			if (os[i] == '+')
			{
				ret += anum[i + 1];
			}
			if (os[i] == '-')
			{
				ret -= anum[i + 1];
			}
			if (os[i] == '*')
			{
				ret *= anum[i + 1];
			}
		}
	}
	ans = max(ans, ret);
}

void func(int num, int cnt,int rcnt)
{
	if (cnt == rcnt)
	{
		p();
		return;
	}
	if (num < anum.size()-1)
	{
		int left = num - 1;
		int right = num + 1;
		if (num == 0&&!visit[right]&&!visit[num]) {
			visit[num]++;
			func(num + 1, cnt + 1, rcnt);
			visit[num]--;
			func(num + 1, cnt, rcnt);
		}
		else if (num == anum.size() - 2 && !visit[left] && !visit[num])
		{
			visit[num]++;
			func(num + 1, cnt + 1, rcnt);
			visit[num]--;
			func(num + 1, cnt, rcnt);
		}
		else if(!visit[right] && !visit[left] && !visit[num]){
			visit[num]++;
			func(num + 1, cnt + 1, rcnt);
			visit[num]--;
			func(num + 1, cnt, rcnt);
		}
		func(num + 1, cnt, rcnt);
	}
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		if (i % 2 == 0)
		{
			anum.push_back(s[i] - '0');
		}
		else {
			os.push_back(s[i]);
		}
	}
	for (int i = 0; i <=anum.size() / 2; i++)
	{
		func(0, 0, i);
	}
	cout << ans << endl;
}