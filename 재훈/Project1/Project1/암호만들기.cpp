#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int L, C;
char arr[16];
vector<char> ret;
vector<char>v;
bool visited[26] = { false, };

void back(int pos, int cnt, int consonant, int collection)
{
	if (pos > C)
		return;
	if (cnt == L)
	{
		if (consonant >= 2 && collection >= 1)
		{
			for (int i = 0; i < ret.size(); i++)
			{
				cout << ret[i];
			}
			cout << endl;
		}
		return;

	}
	if (pos < C)
	{

		int k = arr[pos] - 'a';
		if (!visited[k])
		{
			ret.push_back(arr[pos]);
			visited[k] = true;
			if (k == 0 || k == 4 || k == 8 || k == 14 || k == 20)
				back(pos + 1, cnt + 1, consonant, collection + 1);
			else
				back(pos + 1, cnt + 1, consonant + 1, collection);
			visited[k] = false;
			ret.pop_back();
		}
		back(pos + 1, cnt, consonant, collection);
	}
}


int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + C);
	back(0, 0, 0, 0);
	

}