#include <iostream>
using namespace std;

long int card[500005];

void preCalc()
{
	card[1] = 1;
	long int res = 2;
	for (int i = 2; i <= 500000; i++)
	{
		if (i < res)
			res = 2;
		card[i] = res;
		res += 2;
	}
}

int main()
{
	preCalc();
	int n;
	while (cin >> n && n)
	{
		cout << card[n] << endl;
	}
}
