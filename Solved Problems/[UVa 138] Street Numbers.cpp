#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define ll long long int

int main()
{
	ll count = 0, num2 = 8;
	long double num1;
	while (count != 10)
	{
		num1 = sqrt((pow(num2, 2) + num2) / 2);
		if (num1 == (ll) num1)
		{
			cout << fixed << setprecision(0) << setw(10) << num1 << setw(10) << num2 << endl;
			count++;
		}
		num2++;
	}
}

// Solution: Sum of 1...N-1 = Sum of N+1...X
// Sum of 1 to N-1 = ((N-1)*N)/2
// Sum of N to X = (X*(X+1))/2-(N*(N+1))/2

// The Equation We Get:

// (N*(N-1))/2 = (X*(X+1))/2-(N*(N+1))/2
// (N*(N-1)/2+(N*(N+1))/2 = (X*(X+1))/2
// (N²-N)/2+(N²+N)/2 = (X²+X)/2
// ((N²-N)+(N²+N))/2 = (X²+X)/2
// (N²-N+N²+N)/2 = (X²+X)/2
// 2N²/2 = (X²+X)/2
// N² = (X²+X)/2
// N = √((X²+X)/2)
