#include <iostream>
#include <vector>
using namespace std;

#define ll long int
#define maxN 4294967296

vector < ll > bees;

void preCalc()
{
	bees.push_back(0);
	bees.push_back(1);
	int idx = 2;
	while (true)
	{
		if (bees[idx - 1] + bees[idx - 2] + 1 > maxN)
			break;
		bees.push_back(bees[idx - 1] + bees[idx - 2] + 1);
		idx++;
	}
}

int main()
{
	preCalc();
	ll N;
	while (cin >> N && N >= 0)
	{
		cout << bees[N] << ' ' << bees[N + 1] << endl;
	}
}
