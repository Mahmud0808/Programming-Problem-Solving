#include <iostream>
#include <bitset>
#include <map>
using namespace std;

bitset < 2050 > isPrime;
map < char, int >freq;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < 250; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < 2050; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	sieve();
	int T, cs = 1;
	string str;
	cin >> T;
	while (T--)
	{
		cin >> str;
		bool empty = true;
		int sz = str.size();
		for (int i = 0; i < sz; i++)
			freq[str[i]]++;
		cout << "Case " << cs++ << ": ";
	  for (auto it:freq)
		{
			if (isPrime[it.second])
			{
				cout << it.first;
				empty = false;
			}
		}
		if (empty)
			cout << "empty";
		cout << endl;
		freq.clear();
	}
}
