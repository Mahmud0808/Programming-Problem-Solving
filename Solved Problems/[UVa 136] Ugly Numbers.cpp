#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long int

set < ll > ugly;
int prime[3] = { 2, 3, 5 };

void calculate()
{
	ugly.insert(1);
	set < ll >::iterator it = ugly.begin();
	while (true)
	{
		for (int i = 0; i < 3; i++)
			ugly.insert(*it * prime[i]);
		if (ugly.size() > 2500)
			break;
		it++;
	}
}

int main()
{
	calculate();
	vector < ll > uglyNum(ugly.begin(), ugly.end());
	cout << "The 1500'th ugly number is " << uglyNum[1499] << '.' << endl;
}
