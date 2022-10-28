#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct segment
{
	double x1, y1, x2, y2, coefficient;
};

bool cmp(segment a, segment b)
{
	return (a.x1 < b.x1);
}

int main()
{
	int t;
	cin >> t;
	bool newl = false;
	while (t--)
	{
		int NP;
		cin >> NP;
		segment P[NP];
		vector < segment > arr;
		vector < double > line;
		double X1, Y1, X2, Y2, coef;
		for (int i = 0; i < NP; i++)
		{
			cin >> X1 >> Y1 >> X2 >> Y2 >> coef;
			if (X1 > X2)
			{
				swap(X1, X2);
				swap(Y1, Y2);
			}
			P[i].x1 = X1, P[i].x2 = X2, P[i].y1 = Y1, P[i].y2 = Y2, P[i].coefficient = coef;
			line.push_back(X1);
			line.push_back(X2);
			arr.push_back(P[i]);
		}
		sort(arr.begin(), arr.end(), cmp);
		sort(line.begin(), line.end());
		if (newl)
			cout << endl;
		if (!newl)
			newl = true;
		int sz = line.size();
		cout << (sz + 1) << endl;
		cout << "-inf " << fixed << setprecision(3) << arr[0].
			x1 << ' ' << fixed << setprecision(3) << 1.0 << endl;
		for (int i = 1; i < sz; i++)
		{
			double light = 1.0;
			for (int j = 0; j < arr.size(); j++)
			{
				if (line[i - 1] >= arr[j].x1 && line[i] <= arr[j].x2)
				{
					light *= arr[j].coefficient;
				}
			}
			cout << fixed << setprecision(3) << line[i - 1] << ' ' << fixed << setprecision(3) << line[i] << ' ' << fixed << setprecision(3) << light << endl;
		}
		cout << fixed << setprecision(3) << line[sz - 1] << " +inf " << fixed << setprecision(3) << 1.0 << endl;
	}
}
