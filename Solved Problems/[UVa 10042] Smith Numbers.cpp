#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define ll long long int
#define maxN 32000

bitset < maxN > isPrime;
vector < int >prime, num;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i < maxN; i += 2)
		isPrime[i] = false;
	for (int i = 3; i * i < maxN; i += 2)
		if (isPrime[i])
			for (int j = i * i; j < maxN; j += i * 2)
				isPrime[j] = false;
	prime.push_back(2);
	for (int i = 3; i < maxN; i += 2)
		if (isPrime[i])
			prime.push_back(i);
}

bool primeCheck(ll N)
{
	if (N < 32000)
		return isPrime[N];
	int sz = prime.size();
	for (int i = 0; i < sz && prime[i] <= N; i++)
	{
		if (N % prime[i] == 0)
			return false;
	}
	return true;
}

int sumNum1(int N)
{
	int sum = 0;
	while (N)
	{
		sum += (N % 10);
		N /= 10;
	}
	return sum;
}

int sumNum2(ll N)
{
	int sz = prime.size();
	num.clear();
	for (int i = 0; i < sz && prime[i] <= N; i++)
	{
		if (N % prime[i] == 0)
		{
			while (N % prime[i] == 0)
			{
				N /= prime[i];
				num.push_back(prime[i]);
			}
		}
	}
	if (N != 1)
		num.push_back(N);
	int sum = 0;
	for (int i = 0; i < num.size(); i++)
	{
		sum += sumNum1(num[i]);
	}
	return sum;
}

int main()
{
	sieve();
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int sum = sumNum1(n);
		ll m = n + 1;
		while (primeCheck(m))
		{
			m++;
		}
		while (sumNum1(m) != sumNum2(m))
		{
			m++;
			while (primeCheck(m))
			{
				m++;
			}
		}
		cout << m << endl;
	}
}
