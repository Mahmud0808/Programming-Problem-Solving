#include <iostream>
#include <bitset>
#include <cctype>
using namespace std;

#define maxN 1100

bitset < maxN > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = false;
	isPrime[1] = true;
	for (int i = 2; i < maxN; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < maxN; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	sieve();
	string str;
	while (cin >> str)
	{
		int sum = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (islower(str[i]))
				sum += (str[i] - 96);
			else
				sum += (str[i] - 38);
		}
		if (isPrime[sum])
			cout << "It is a prime word." << endl;
		else
			cout << "It is not a prime word." << endl;
	}
}
