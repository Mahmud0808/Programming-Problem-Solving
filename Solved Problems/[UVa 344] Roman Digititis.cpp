#include <iostream>
#include <map>
using namespace std;

map < char, int >counter;

struct roman
{
	int i, v, x, l, c;
} num[101];

void preCalc()
{
	for (int i = 1; i <= 100; i++)
	{
		int n = i;
		while (n)
		{
			if (n == 100)
			{
				n -= 100;
				counter['c']++;
			}
			else if (n >= 90)
			{
				n -= 90;
				counter['x']++;
				counter['c']++;
			}
			else if (n >= 50)
			{
				n -= 50;
				counter['l']++;
			}
			else if (n >= 40)
			{
				n -= 40;
				counter['x']++;
				counter['l']++;
			}
			else if (n >= 10)
			{
				n -= 10;
				counter['x']++;
			}
			else if (n == 9)
			{
				n -= 9;
				counter['i']++;
				counter['x']++;
			}
			else if (n >= 5)
			{
				n -= 5;
				counter['v']++;
			}
			else if (n == 4)
			{
				n -= 4;
				counter['i']++;
				counter['v']++;
			}
			else
			{
				counter['i'] += n;
				n -= n;
			}
		}
		num[i].i = num[i - 1].i + counter['i'], num[i].v = num[i - 1].v + counter['v'], num[i].x =
			num[i - 1].x + counter['x'], num[i].l = num[i - 1].l + counter['l'], num[i].c =
			num[i - 1].c + counter['c'];
		counter.clear();
	}
}

int main()
{
	preCalc();
	int n;
	while (cin >> n && n)
	{
		cout << n << ": " << num[n].i << " i, " << num[n].v << " v, " << num[n].
			x << " x, " << num[n].l << " l, " << num[n].c << " c" << endl;
	}
}
