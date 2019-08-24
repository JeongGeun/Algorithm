#include<iostream>
using namespace std;


int N, M;


int main()
{

	cin >> N >> M;
	int ma = 1001;
	int mi = 1001;
	for (int i = 0; i < M; i++)
	{
		int x = 0;
		int y = 0;
		cin >> x >> y;
		if (ma > x)
		{
			ma = x;
		}
		if (mi > y)
		{
			mi = y;
		}
	}
	if (N < 6)
	{
		if (ma > mi*N)
		{
			cout<< mi * N;
			return 0;
		}
		else
		{
			cout<<ma;
			return 0;
		}
	}
	else
	{
		if (mi * 6 < ma)
		{
			cout<<mi * N;
			return 0;
		}
		else
		{
			int a = N/6;
			int b = N % 6;
			if (a*ma + ma > a*ma + mi * b)
			{
				cout<<a * ma + mi * b;
			}
			else
			{
				cout<<a * ma + ma;
			}
		}

	}





}