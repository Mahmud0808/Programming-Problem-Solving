#include <iostream>
#include <cmath>
using namespace std;

#define ll long long int

int main()
{
	int T, cs = 1;
	ll n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		ll total = n - (int)sqrt(n) - (int)sqrt(n / 2.0);
		cout << "Case " << cs++ << ": " << total << endl;
	}
}

/*

## Explanation ##

Odd SOD means even power of prime factors except for prime number 2.

Example:
σ(3²) = 3² + 3¹ + 3⁰ = 13

Even SOD means odd power of prime factors except for prime nunber 2.

Example:
σ(3³) = 3³ + 3² + 3¹ + 3⁰ = 40

Prime number 2 has always odd SOD.

Example:
σ(2²) = 2² + 2¹ + 2⁰ = 7
σ(2³) = 2³ + 2² + 2¹ + 2⁰ = 15

So we can make an equation from here.
We should keep even powers of all prime numbers (except 2) to get odd SOD. Because odd*odd is equal to odd.

For N which has even power of 2, we can write:
2^(2n)*X^(2n) = N
=> 2^n*X^n = √N

For N which has odd power of 2, we can write:
2^(2n+1)*X^(2n) = N
=> 2^(2n)*X^(2n) = N/2
=> 2^n*X^n = √(N/2)

Where X is other prime numbers.

So we can just subtract these odd SOD numbers to get even SOD number:
Total = N - √N - √(N/2)

*/