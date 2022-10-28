#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct point
{
	int x, y, idx;
};

point p[4];

bool isValid(point p[])
{
	if ((p[0].x * p[1].y + p[1].x * p[2].y + p[2].x * p[3].y + p[3].x * p[0].y) - (p[0].y * p[1].x + p[1].y * p[2].x + p[2].y * p[3].x + p[3].y * p[0].x) <= 0)
		return false;
	else
		return true;
}

void _sort()
{
	while (!isValid(p))
	{
		next_permutation(p, p + 4, [](const auto &l, const auto &r) { return l.idx < r.idx; });
	}
}

int distance(point a, point b)
{
	return pow(b.x - a.x, 2) + pow(b.y - a.y, 2);
}

bool slope(point a, point b, point c, point d)
{
	int numeratorA, denominatorA, numeratorB, denominatorB;
	numeratorA = b.y - a.y;
	denominatorA = b.x - a.x;
	numeratorB = c.y - d.y;
	denominatorB = c.x - d.x;
	if (denominatorA == 0)
		if (denominatorB == 0)
			return true;
		else
			return false;
	else if (denominatorB == 0)
		if (denominatorA == 0)
			return true;
		else
			return false;
	else
	{
		if (numeratorA * denominatorB == numeratorB * denominatorA)
			return true;
		else
			return false;
	}
}

int main()
{
	int T, cs=1;
	cin >> T;
	point a, b, c, d;
	while (T--)
	{
		for (int i = 0; i < 4; i++)
		{
			cin >> p[i].x >> p[i].y;
			p[i].idx = i;
		}
		_sort();
		a = p[0], b = p[1], c = p[2], d = p[3];
		if (distance(a, b) == distance(b, c) && distance(b, c) == distance(c, d) && distance(c, d) == distance(d, a))
		{
			if (distance(a, c) == distance(b, d))
				cout << "Case " << cs++ << ": Square" << endl;
			else
				cout << "Case " << cs++ << ": Rhombus" << endl;
		}
		else if (distance(a, b) == distance(c, d) && distance(b, c) == distance(d, a))
		{
			if (distance(a, c) == distance(b, d))
				cout << "Case " << cs++ << ": Rectangle" << endl;
			else
				cout << "Case " << cs++ << ": Parallelogram" << endl;
		}
		else
		{
			if (slope(a, b, c, d) || slope(b, c, a, d))
				cout << "Case " << cs++ << ": Trapezium" << endl;
			else
				cout << "Case " << cs++ << ": Ordinary Quadrilateral" << endl;
		}
	}
}
