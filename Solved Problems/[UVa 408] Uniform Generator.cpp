#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

#define ll long long int

int main()
{
	ll step, mod, seed, count, cs=1;
	while (cin >> step >> mod)
	{
		map <ll, bool> used;
		bool uniform=false;
		seed=0, count=0;
		while (!used[(seed+step)%mod])
		{
			used[(seed+step)%mod]=true;
			count++;
			seed=(seed+step)%mod;
		}
		if (count==mod)
			uniform=true;
		if (uniform)
			cout << setw(10) << step << setw(10) << mod << "    " << "Good Choice" << endl << endl;
		else
			cout << setw(10) << step << setw(10) << mod << "    " << "Bad Choice" << endl << endl;
	}
}
