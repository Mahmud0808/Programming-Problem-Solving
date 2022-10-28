#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

#define ll long long int
#define maxN 100000

ll squareSum(ll N)
{
	ll result = 0;
	while (N)
	{
		result += pow((N % 10), 2);
		N /= 10;
	}
	return result;
}

vector <int> Happy;
map <int, int> step;

void preCalc()
{
	Happy.push_back(1);
	step[1]=1;
	for (int i=2; i<maxN; i++)
	{
		map < ll, bool > used;
		int N = i, count = 1;
		bool happy = false;
		while (!used[N])
		{
			used[N] = true;
			N = squareSum(N);
			count++;
			if (N == 1)
			{
				happy = true;
				break;
			}
		}
		if (happy)
		{
			step[i]=count;
			Happy.push_back(i);
		}
	}
}

int main()
{
	preCalc();
	int L, H;
	bool newl=false;
	while (cin >> L >> H)
	{
		if (newl)
			cout << endl;
		else
			newl=true;
		int left=lower_bound(Happy.begin(), Happy.end(), L)-Happy.begin();
		int right=lower_bound(Happy.begin(), Happy.end(), H)-Happy.begin();
		if (right>0 && Happy[right]>H)
			right--;
		for (int i=left; i<=right; i++)
			if (Happy[i])
				cout << Happy[i] << ' ' << step[Happy[i]] << endl;
	}
}
