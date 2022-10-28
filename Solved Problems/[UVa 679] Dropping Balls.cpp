#include <iostream>
#include <cmath>
using namespace std;

int maxNode;

int binarySearch(int currentNode, int balls)
{
	int leftNode = (2 * currentNode), rightNode = (2 * currentNode) + 1;
	if (leftNode >= maxNode || balls == 0)
		return currentNode;
	if (balls % 2 == 0)
		return binarySearch(rightNode, (balls / 2));
	else
		return binarySearch(leftNode, (balls / 2) + 1);
}

int main()
{
	int l, D, I;
	while (cin >> l && l != -1)
	{
		while (l--)
		{
			cin >> D >> I;
			maxNode = pow(2, D);
			cout << binarySearch(1, I) << endl;
		}
	}
}
