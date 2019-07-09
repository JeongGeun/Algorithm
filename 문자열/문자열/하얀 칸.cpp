#include<iostream>
using namespace std;


char arr[8][8];
int main()
{
	int ans = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'F')
			{
				if ((i + j) % 2 == 0)
				{
					ans++;
				}
			}
		}
	}
	cout << ans << "\n";

}