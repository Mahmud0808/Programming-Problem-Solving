#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI acos(-1)

int main()
{
	int a, b, v, A, s;
	while (cin >> a >> b >> v >> A >> s && (a || b || v || A || s))
	{
		double len = (double)(v * s) / 2;
		double horizontal = len * cos(A * (PI / 180.0)), vertical = len * sin(A * (PI / 180.0));
		cout << fixed << setprecision(0) << horizontal / a << ' ' << fixed << setprecision(0) << vertical / b << endl;
	}
}
