#include <iostream>
using namespace std;

int mod(string & num, int m)
{
	int mod = 0;
	for (int i = 0; i < num.size(); i++)
	{
		mod = (mod * 10 + (num[i] - 48)) % m;
	}
	return mod;
}

int main()
{
	int t, N;
	string P;
	cin >> t;
	while (t--)
	{
		cin >> N >> P;
		cout << mod(P, N) << endl;
	}
}
