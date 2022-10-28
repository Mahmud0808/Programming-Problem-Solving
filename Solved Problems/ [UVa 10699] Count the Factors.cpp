#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector < int >prime;

void sieve()
{
	bitset < 37000 > bs;
	bs.set();
	for (int i = 2; i < 37000; i++)
	{
		if (bs[i])
		{
			for (int j = i * i; j < 37000; j += i)
			{
				bs[j] = false;
			}
			prime.push_back(i);
		}
	}
}

int main()
{
	sieve();
	int N;
	while (cin >> N && N)
	{
		int count = 0, tmp = N;
		for (int i = 0; i < prime.size(); i++)
		{
			if (tmp % prime[i] == 0)
			{
				while (tmp % prime[i] == 0)
				{
					tmp /= prime[i];
				}
				count++;
			}
		}
		if (tmp != 1)
			count++;
		cout << N << " : " << count << endl;
	}
}
