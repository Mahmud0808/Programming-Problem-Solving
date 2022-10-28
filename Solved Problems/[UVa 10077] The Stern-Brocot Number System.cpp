#include <iostream>
using namespace std;

struct SternBrocot
{
	double m, n;
};

int main()
{
	double m, n, mn, l, r;
	string str;
	SternBrocot left, right, mid;
	while (cin >> m >> n && (m!=1 || n!=1))
	{
		mn=m/n;
		left.m=0, left.n=1, right.m=1, right.n=0;
		mid.m=1, mid.n=1;
		while (mid.m!=m || mid.n!=n)
		{
			mid.m=left.m+right.m, mid.n=left.n+right.n;
			if (mid.m==m && mid.n==n)
				break;
			if ((double)(mid.m/mid.n)<mn)
				left=mid, str+='R';
			else
				right=mid, str+='L';
		}
		cout << str << endl;
		str.clear();
	}
}
