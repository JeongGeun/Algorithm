#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[26];
int arr2[26];

int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			arr[s[i] - 'A']++;
		}
		else
		{
			arr2[s[i] - 'a']++;
		}
	}
	int m = -1;
	int idx = 0;
	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		arr[i] += arr2[i];
		if (m < arr[i])
		{
			m = arr[i];
			idx = i;
		}
	}
	sort(arr, arr + 26, greater<int>());
	if (arr[0] == arr[1])
	{
		cout << "?" << "\n";
		return 0;
	}
	char answer;
	answer = idx + 'A';
	cout<<answer<<"\n";


}