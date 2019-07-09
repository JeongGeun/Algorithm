#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<string>v;
	int ssize = s.size();
	for (int i = 0; i < ssize; i++)
	{
		v.push_back(s);
		s.erase(s.begin());
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";



}