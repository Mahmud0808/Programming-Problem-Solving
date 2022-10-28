#include <iostream>
using namespace std;

// Extended Euclidian GCD

int xGCD(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int X, Y, gcd = xGCD(b, a % b, X, Y);
	x = Y;
	y = X - (a / b) * Y;
	return gcd;
}

int main()
{
	int A, B, X, Y, D;
	while (cin >> A >> B)
	{
		D = xGCD(A, B, X, Y);
		if (A * X + B * Y != D)
			swap(X, Y);
		cout << X << ' ' << Y << ' ' << D << endl;
	}
}