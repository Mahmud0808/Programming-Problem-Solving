#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Array
{
	string name;
	int B, CD, D;
	struct LU
	{
		int L, U;
	} bound[11];
};

int main()
{
	int N, R;
	cin >> N >> R;
	Array A[N];
	map < string, int >arr;
	for (int n = 0; n < N; n++)
	{
		cin >> A[n].name >> A[n].B >> A[n].CD >> A[n].D;
		arr[A[n].name] = n;
		for (int a = 1; a <= A[n].D; a++)
		{
			cin >> A[n].bound[a].L >> A[n].bound[a].U;
		}
	}
	string ArrRef;
	int i[11];
	while (R--)
	{
		cin >> ArrRef;
		for (int x = 1; x <= A[arr[ArrRef]].D; x++)
		{
			cin >> i[x];
		}
		int C[A[arr[ArrRef]].D + 1];
		C[A[arr[ArrRef]].D] = A[arr[ArrRef]].CD;
		for (int j = A[arr[ArrRef]].D - 1; j >= 1; j--)
		{
			C[j] = C[j + 1] * (A[arr[ArrRef]].bound[j + 1].U - A[arr[ArrRef]].bound[j + 1].L + 1);
		}
		C[0] = A[arr[ArrRef]].B;
		for (int j = 1; j <= A[arr[ArrRef]].D; j++)
		{
			C[0] -= C[j] * A[arr[ArrRef]].bound[j].L;
		}
		int address = C[0];
		for (int j = 1; j <= A[arr[ArrRef]].D; j++)
		{
			address += C[j] * i[j];
		}
		cout << ArrRef << '[';
		for (int j = 1; j <= A[arr[ArrRef]].D; j++)
		{
			if (j != 1)
				cout << ", ";
			cout << i[j];
		}
		cout << "] = " << address << endl;
	}
}
