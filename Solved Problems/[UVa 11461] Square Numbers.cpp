#include <iostream>
#include <cmath>
using namespace std;

int ans[100005];

void preCalc()
{
	int tmp;
	ans[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		tmp = sqrt(i);
		if (tmp * tmp == i)
			ans[i]++;
		ans[i] += ans[i - 1];
	}
}

int main()
{
	preCalc();
	int a, b;
	while (cin >> a >> b && a && b)
	{
		cout << ans[b] - ans[a - 1] << endl;
	}
}
