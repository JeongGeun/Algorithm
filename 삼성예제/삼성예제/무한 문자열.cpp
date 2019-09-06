#include<iostream>
#include<string>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main()
{
	string s,t;
	cin >> s >> t;
	int sidx = 0;
	int tidx = 0;
	int flag = 1;
	for (int i = 0; i < lcm(s.size(), t.size()); i++)
	{
		if (sidx >= s.size())sidx = 0;
		if (tidx >= t.size())tidx = 0;
		if (s[sidx++] != t[tidx++]) {
			flag = 0;
			break;
		}
	}
	cout << flag << endl;
}