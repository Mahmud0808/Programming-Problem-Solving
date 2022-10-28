#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define ll long long int

int main()
{
	int D, cs = 1;
	while (cin >> D)
	{
		int arr[D];
		for (int i = 0; i < D; i++)
			cin >> arr[i];
		cout << "Case #" << cs++ << ": ";
		for (int i = 0; i < D; i++)
		{
			cout << arr[i];
			if (i + 1 == D)
				cout << endl;
			else
				cout << ' ';
		}
		vector < ll > sum;
		sum.push_back(0);
		map < ll, bool > found;
		bool seq = true;
		for (int i = 0; i < D; i++)
		{
			if (found[arr[i]] || arr[i] < 1 || (i > 0 && arr[i] <= arr[i - 1]))
			{
				seq = false;
				break;
			}
			int sz = sum.size();
			for (int j = 0; j < sz; j++)
			{
				if (!found[sum[j] + arr[i]])
				{
					sum.push_back(sum[j] + arr[i]);
					found[sum[j] + arr[i]] = true;
				}
			}
		}
		if (!seq)
			cout << "This is not an A-sequence." << endl;
		else
			cout << "This is an A-sequence." << endl;
	}
}
