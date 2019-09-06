#include<iostream>
#include<queue>
using namespace std;



int main()
{
	int n;
	cin >> n;
	deque<int>q;
	for (int i = 1; i <= n; i++)
	{
		q.push_back(i);
	}
	while (q.size() != 1)
	{
		int x = q.front();
		cout << x << endl;
		q.pop_front();
		int y = q.front();
		q.push_back(y);
		q.pop_front();
	}
	cout << q[0] << endl;


}