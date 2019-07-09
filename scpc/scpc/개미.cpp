#include<iostream>
#include<algorithm>
using namespace std;


int T, n, l;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> l >>n;
		int Maxi = 0;
		int Mini = 0;
		for (int i = 0; i < n; i++)
		{
			int m = 0;
			cin >> m;
			Maxi = max({ Maxi,l - m,m });
			Mini = max(Mini, min(l - m, m));
			
			
		}
		cout << Mini << " " << Maxi << "\n";
	}




}