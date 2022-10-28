#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#define ll long long int

vector < ll > factorial;

void preCalc()
{
	ll result = 1;
	for (int i = 1; i <= 10000; i++)
	{
		result *= i;
		while (!(result % 10))
		{
			result /= 10;
		}
		result %= 1000000;
		factorial.push_back(result);
	}
}

int main()
{
	preCalc();
	int N;
	while (cin >> N)
	{
		cout << setw(5) << N << " -> " << factorial[N - 1] % 10 << endl;
	}
}
