#include<iostream>
#include<set>
#include<vector>
#include<deque>
#include<string>
#include<cmath>
using namespace std;

int T, N,K;
long long int ans;
deque<char> q;
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> K;
		string s;
		set<string, greater<string>> se;
		cin >> s;
		for (int i = 0; i < N; i++)
		{
			q.push_back(s[i]);
		}
		int rc = N / 4;
		
		for (int m = 0; m < rc; m++)
		{
			int idx = 0;
			for (int j = 0; j < 4; j++)
			{
				string ss;
				for (int i = 0; i < rc; i++)
				{
					ss += q[idx++];
				}
				se.insert(ss);
				ss.clear();
			}
			int num = 0;
			num = q.back();
			q.pop_back();
			q.push_front(num);
		}
		string ret;
		int cnt = 1;
		for (auto i = se.begin(); i != se.end(); i++)
		{
			if (cnt == K)
			{
				ret = *i;
				break;
			}
				cnt++;
		}
		for (int i = 0; i < ret.size(); i++)
		{
			if (ret[i] == 'F')
			{
				ans += 15*(pow(16,ret.size()-i-1));
			}
			else if (ret[i] == 'E')
			{
				ans += 14 * (pow(16, ret.size() - i - 1));
			}
			else if (ret[i] == 'D')
			{
				ans += 13 * (pow(16, ret.size() - i - 1));
			}
			else if (ret[i] == 'C')
			{
				ans += 12 * (pow(16, ret.size() - i - 1));
			}
			else if (ret[i] == 'B')
			{
				ans += 11 * (pow(16, ret.size() - i - 1));
			}
			else if (ret[i] == 'A')
			{
				ans += 10 * (pow(16, ret.size() - i - 1));
			}
			else
			{
				ans += (ret[i] - '0')*(pow(16, ret.size() - i - 1));
			}
			
		}

		cout << "#" << t << " " << ans<<"\n";
		ans = 0;
		q.clear();
		s.clear();
		se.clear();
	}

}