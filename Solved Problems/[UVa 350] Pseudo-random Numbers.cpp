#include <iostream>
#include <map>
using namespace std;

#define ll long long int

int main()
{
	ll Z, I, M, L, count, cs=1;
	while (cin >> Z >> I >> M >> L && Z+I+M+L)
	{
		map <ll, bool> used;
		count=0;
		while (!used[(Z*L+I)%M])
		{
			used[(Z*L+I)%M]=true;
			count++;
			L=(Z*L+I)%M;
		}
		cout << "Case " << cs++ << ": " << count << endl;
	}
}
