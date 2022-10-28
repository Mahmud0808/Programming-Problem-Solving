#include <iostream>
using namespace std;

int main()
{
	int N;
	while (cin >> N && N)
	{
		if (N % 5 == 0)
			cout << "0.00" << endl;
		else if (N % 5 == 1 || N % 5 == 4)
			cout << "0.40" << endl;
		else
			cout << "0.20" << endl;
	}
}
