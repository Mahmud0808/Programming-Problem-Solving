#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string S;
	while (cin >> S)
	{
		if (S[0] == '-')
			return 0;
		int N = atoi(S.c_str());
		if (S.size()>1 && S[1] == 'x')
		{
			stringstream(S) >> hex >> N;
			cout << dec << N << uppercase << endl;
		}
		else
			cout << hex << "0x" << N << uppercase << endl;
	}
}
