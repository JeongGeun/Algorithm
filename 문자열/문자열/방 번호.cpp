#include<iostream>
#include<string>
using namespace std;

int arr[10];


int main()
{
	string s;
	cin >> s;
	int count=0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] - '0' == 9)
		{
			arr[6]++;
			continue;
		}
		arr[s[i] - '0']++;
	}
	arr[6] = arr[6] / 2 + arr[6] % 2;
	
	int m = -1;
	for (int i= 0; i < 9; i++)
	{
		if (m < arr[i])
			m = arr[i];
	}
	cout << m << "\n";



}