#include <iostream>
#include <map>
using namespace std;

#define ll long long unsigned int

int main()
{
	int N, m, cs=1;
	string s;
	cin >> N;
	while (N--)
	{
		cin >> m >> s;
		map <int, int> power;
		int n=s.size();
		for (int i=m; i>=2; i-=n)
		{
			int tmp=i;
			for (int i=2; i<=tmp; i++)
			{
				if (tmp%i==0)
				{
					while (tmp%i==0)
					{
						tmp/=i;
						power[i]++;
					}
				}
			}
			if (tmp!=1)
				power[tmp]++;
		}
		bool inf=false;
		ll result=1;
		for (auto it: power)
		{
			result *= (it.second+1);
			if (result > 1e18)
			{
				inf=true;
				break;
			}
		}
		if (inf)
			cout << "Case " << cs++ << ": Infinity" << endl;
		else
			cout << "Case " << cs++ << ": " << result << endl;
	}
}
