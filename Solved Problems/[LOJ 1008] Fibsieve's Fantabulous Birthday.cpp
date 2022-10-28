#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long unsigned int T, S, x, y, row, col, corner, cs=1;
	cin >> T;
	while (T--)
	{
		cin >> S;
		x=ceil(sqrt(S));
		y=x-1;
		corner=(pow(x, 2)+pow(y, 2)+1)/2;
		if (pow(x, 2)==S)
		{
			if (S%2==0)
			{
				row=1;
				col=x;
				cout << "Case " << cs++ << ": " << col << ' ' << row << endl;
			}
			else
			{
				row=x;
				col=1;
				cout << "Case " << cs++ << ": " << col << ' ' << row << endl;
			}
		}
		else if (corner==S)
		{
			row=(pow(x, 2)-pow(y, 2)+1)/2;
			col=row;
			cout << "Case " << cs++ << ": " << col << ' ' << row << endl;
		}
		else
		{
			if (pow(x, 2)>S && corner<S)
			{
				row=x;
				col=pow(x, 2)-S+1;
				if ((x*x)%2==0)
					swap(col, row);
				cout << "Case " << cs++ << ": " << col << ' ' << row << endl;
			}
			else if (pow(y, 2)<S && corner>S)
			{
				row=x;
				col=x-(corner-S);
				if ((y*y)%2==0)
					swap(col, row);
				cout << "Case " << cs++ << ": " << col << ' ' << row << endl;
			}
		}
	}
}