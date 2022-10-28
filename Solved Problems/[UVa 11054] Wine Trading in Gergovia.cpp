#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        long long int a[n];
        for (int i=0; i<n; i++)
            cin >> a[i];
        long long int sum=abs(a[0]);
        for (int i=1; i<n; i++)
        {
            a[i]+=a[i-1];
            sum+=abs(a[i]);
        }
        cout << sum << endl;
    }
}
