#include <iostream>
#include <map>
using namespace std;

int main()
{
	int T, n, m, K, p, tmp, cs=1;
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> K;
		int arr[n][K];
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<K; j++)
			{
				cin >> arr[i][j];
			}
		}
		map <int, bool> myMap;
		cin >> p;
		while (p--)
		{
			cin >> tmp;
			myMap[tmp]=true;
		}
		bool res=false;
		for (int i=0; i<n; i++)
		{
			res=false;
			for (int j=0; j<K; j++)
			{
				if ((arr[i][j]>0 && myMap[arr[i][j]]) || (arr[i][j]<0 && !myMap[-arr[i][j]]))
				{
					res=true;
				}
			}
			if (!res)
				break;
		}
		if (res)
			cout << "Case " << cs++ << ": Yes" << endl;
		else
			cout << "Case " << cs++ << ": No" << endl;
		myMap.clear();
	}
}