#include<string>
#include<iostream>
#include<cmath>
using namespace std;

string A;
string B;
int maxA, maxB;
int minA, minB;
int main()
{
	cin >> A >> B;
	string s1;
	string s2;
	s1 = A;
	s2 = B;
	
	for (int i = 0; i < A.size(); i++)
	{
		if (s1[i] == '6')
			s1[i] = '5';
		minA += (s1[i] - '0')*pow(10, A.size() - 1 - i);
	}
	for (int i = 0; i < B.size(); i++)
	{
		if (s2[i] == '6')
			s2[i] = '5';
		minB += (s2[i] - '0')*pow(10, B.size() - 1 - i);
	}
	cout << minA + minB<< " ";
	for (int i = 0; i < A.size(); i++)
	{
		if (s1[i] == '5')
			s1[i] = '6';
		maxA += (s1[i] - '0')*pow(10, A.size() - 1 - i);
	}
	for (int i = 0; i < B.size(); i++)
	{
		if (s2[i] == '5')
			s2[i] = '6';
		maxB += (s2[i] - '0')*pow(10, B.size() - 1 - i);
	}
	cout << maxA + maxB;

}