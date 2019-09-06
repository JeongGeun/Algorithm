#include<iostream>
#include<algorithm>
using namespace std;

int l, a, b, c, d;

int main()
{
	cin >> l >> a >> b >> c >> d;
	int r = a / c;
	if (a%c != 0)r++;
	int k = b / d;
	if (b%d != 0)k++;
	int ans = max(r, k);
	cout << l - ans << endl;



}