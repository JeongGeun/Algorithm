#include<iostream>
#include<vector>
#include<string>
using namespace std;

int arr[] = { 100,10,1 };

struct pic {
	vector<int> num;
	int strike;
	int ball;
};
int main()
{
	int n = 0;
	int ans = 0;
	cin >> n;
	vector<pic>v;
	for (int i = 0; i < n; i++)
	{
		vector<int>tmp;
		int x;
		int y, z;
		cin >> x >> y >> z;
		for (int j = 0; j < 3; j++)
		{
			tmp.push_back(x / arr[j]);
			x %= arr[j];
		}
		v.push_back({tmp,y,z});
	}
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (i == j) continue;
			for (int k = 1; k < 10; k++)
			{
				if (i == k || j == k) continue;
				vector<int> p;
				p.push_back(i);
				p.push_back(j);
				p.push_back(k);
				int cnt = 0;
				for (int a = 0; a < v.size(); a++)
				{
					vector<int> x = v[a].num;
					int str = 0;
					int ball = 0;
					for (int b = 0; b < 3; b++)
					{
						for (int c = 0; c < 3; c++)
						{
							if (p[b] == x[c] && b == c) str++;
							if (p[b] == x[c] && b != c) ball++;
						}
					}
					if (str == v[a].strike&&ball == v[a].ball) cnt++;
					else break;
				}
				if (cnt == v.size())ans++;
			}
		}
	}
	
	cout << ans << endl;

}