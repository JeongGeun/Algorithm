#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
set<string>s;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s1;
		cin >> s1;
		s.insert(s1);
	}
	set<string>v;
	for (int i = 0; i < M; i++)
	{
		string s1;
		cin >> s1;
		if (s.count(s1) > 0)
		{
			v.insert(s1);
		}
	}
	cout << v.size() << '\n';
	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << "\n";
	}

}