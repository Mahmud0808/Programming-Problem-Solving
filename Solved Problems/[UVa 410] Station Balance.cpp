#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int C, S, cs = 1;
	while (cin >> C >> S)
	{
		int speci[2 * C];
		memset(speci, 0, sizeof(speci));
		double imbalance = 0.0, CM, AM = 0.0;
		for (int i = 0; i < S; i++)
		{
			cin >> speci[i];
			AM += speci[i];
		}
		AM /= C;
		sort(speci, speci + 2 * C);
		cout << "Set #" << cs++ << endl;
		for (int i = 0; i < C; i++)
		{
			cout << ' ' << i << ':';
			if (speci[i])
				cout << ' ' << speci[i];
			if (speci[2 * C - 1 - i])
				cout << ' ' << speci[2 * C - 1 - i];
			CM = speci[i] + speci[2 * C - 1 - i];
			imbalance += abs(CM - AM);
			cout << endl;
		}
		cout << "IMBALANCE = " << fixed << setprecision(5) << imbalance << endl << endl;
	}
}
