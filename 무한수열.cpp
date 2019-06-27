#include<iostream>
#include<map>
using namespace std;

long long int n, p, q;
map <long long,long long> m;

long long func(long long k)
{
	if (m.count(k) != 0)
		return m[k];
	else
		return m[k]=func(k / p) + func(k / q);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> p >> q;
	m[0] = 1;
	cout << func(n) << '\n';

}