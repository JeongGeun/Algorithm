#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int  N,M, k,arr[10];
int num[7] = { -1, };


int main()
{
	cin >>N>>M;
	for (int i = 0; i < M; i++)
	{
		cin >> k;
		arr[k] = 1;
	}
	int m = abs(N - 100);
	for (int i = 0; i <= 1000000; i++)
	{
		int channel = i;
		int leng = 0;
		bool flag = false;
		while (1)
		{
			if (arr[channel % 10])
				break;
			else
			{
				channel /= 10;
				leng++;
				if (channel == 0)
				{
					flag = true;
					break;
				}
			}

		}
		if (flag)
		{
			int dif = leng + abs(N- i);
			m = min(dif, m);
		}

	}
	cout << m << endl;



}
