#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000005
int ans[MAX];

int factorial(int N)
{
    int count=0;
    for (int i=2; i*i<=N; i++)
    {
        if (N%i==0)
        {
            while (N%i==0)
            {
                count++;
                N/=i;
            }
        }
    }
    if (N!=1)
        count++;
    return count;
}

int main()
{
    int n;
    ans[0]=0, ans[1]=0;
    for (int i=2; i<MAX; i++)
    {
        ans[i]=ans[i-1]+factorial(i);
    }
    while (cin >> n)
    {
        cout << ans[n] << endl;
    }
}
