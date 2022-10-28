#include <iostream>
using namespace std;

#define ll long long int

ll gcd(ll a, ll b)
{
    return (!a) ? b : gcd(b%a, a);
}

int main()
{
    int T, X, N, Y, M, cs=1;
    cin >> T;
    while (T--)
    {
        cin >> X >> N >> Y >> M;
        ll container1=X, container2=0;
        if (!N)
            container1+=Y;
        for (int i=1; i<=N; i++)
        {
            if (container1<container2)
                swap(container1, container2);
            container2+=container1;
            if (i==N)
            {
                if (container1<container2)
                    swap(container1, container2);
                container1+=Y;
            }
        }
        cout << "Case " << cs++ << ": " << gcd(container1, container2) << endl;
    }
}
