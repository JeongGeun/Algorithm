#include<iostream>
#include<queue>
using namespace std;

deque<int>q;
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		q.push_back(i);
	}
	while (q.size() != 1)
	{
		q.pop_front();
		int a = q.front();
		q.pop_front();
		q.push_back(a);
	}
	cout << q[0] << endl;
}