#include <iostream>
#include <bitset>
using namespace std;

#define maxN 1000001
bitset < maxN > num;

int digSum(int N)
{
	int sum = 0;
	while (N)
	{
		sum += (N % 10);
		N /= 10;
	}
	return sum;
}

void preCalc()
{
	num.set();
	for (int i = 1; i < maxN; i++)
	{
		int tmp = i;
		tmp += digSum(tmp);
		num[tmp] = false;
	}
}

void print()
{
	int idx = 1;
	while (idx < maxN)
	{
		if (num[idx])
			cout << idx << endl;
		idx++;
	}
}

int main()
{
	preCalc();
	print();
}
