#include<iostream>
#include<string>
using namespace std;

int arr[26];


int main()
{
	string s1;
	cin >> s1;
	int ans = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= 65 && s1[i] <= 67)
		{
			arr[2]++;
		}
		if (s1[i] >= 68 && s1[i] <= 70)
		{
			arr[3]++;
		}
		if (s1[i] >= 71 && s1[i] <= 73)
		{
			arr[4]++;
		}
		if (s1[i] >= 74 && s1[i] <= 76)
		{
			arr[5]++;
		}
		if (s1[i] >= 77 && s1[i] <= 79)
		{
			arr[6]++;
		}
		if (s1[i] >= 80 && s1[i] <= 83)
		{
			arr[7]++;
		}
		if (s1[i] >= 84 && s1[i] <= 86)
		{
			arr[8]++;
		}
		if (s1[i] >= 87 && s1[i] <= 90)
		{
			arr[9]++;
		}
	}
	for (int i = 2; i <= 9; i++)
	{
		if(arr[i])
		ans += (i*arr[i] + arr[i]);
	}
	
	cout << ans<< "\n";



}