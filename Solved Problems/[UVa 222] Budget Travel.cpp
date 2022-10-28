#include <iostream>
#include <iomanip>
using namespace std;

int n;
double tdist, capacity, mpg, cost, dist[52], price[52];

double solve(double distance, int station)
{
	if (distance + capacity * mpg >= tdist || station == n)
		return 0;
	double best = 1e6;
	for (int i = station; i < n; i++)
	{
		double consumed = (dist[i] - distance) / mpg;
		if (capacity - consumed < 0)
			break;
		if (capacity - consumed <= capacity / 2.0)
		{
			best = min(best, 200.0 + (consumed * price[i]) + solve(dist[i], i + 1));
		}
		else if (capacity - consumed > capacity / 2.0 && dist[i] > distance + (capacity - consumed) * mpg)
		{
			return 200.0 + (consumed * price[i]) + solve(dist[i], i + 1);
		}
	}
	return best;
}

int main()
{
	int cs = 1;
	while (cin >> tdist && tdist >= 0)
	{
		cin >> capacity >> mpg >> cost >> n;
		for (int i = 0; i < n; i++)
			cin >> dist[i] >> price[i];
		double total = (solve(0, 0) / 100.0) + cost;
		cout << "Data Set #" << cs++ << endl << "minimum cost = $" << fixed << setprecision(2) << total << endl;
	}
}
