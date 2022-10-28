#include <iostream>
using namespace std;

int main()
{
    long long unsigned int fibo[51];
    fibo[0]=0, fibo[1]=2, fibo[2]=3;
    for (int i=3; i<=50; i++)
        fibo[i]=fibo[i-1]+fibo[i-2];
    int t, n, cs=1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << "Scenario #" << cs++ << ':' << endl << fibo[n] << endl << endl;
    }
}
