#include <iostream>
using namespace std;

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int round=0;
        n--, m--;
        while (n>0)
        {
            round++;
            n-=m;
        }
        if (n==0)
            cout << round << endl;
        else
            cout << "cannot do this" << endl;
    }
}
