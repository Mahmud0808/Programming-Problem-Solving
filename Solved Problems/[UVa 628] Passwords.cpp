#include <iostream>
using namespace std;

int n, m;
string pass[101], rule, password[1001], num= {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void passwords(int x)
{
    if (x==rule.size())
    {
        for (int i=0; i<x; i++)
        {
            cout << password[i];
        }
        cout << endl;
    }
    else
    {
        if (rule[x]=='#')
        {
            for (int i=0; i<n; i++)
            {
                password[x]=pass[i];
                passwords(x+1);
            }
        }
        else
        {
            for (int i=0; i<10; i++)
            {
                password[x]=num[i];
                passwords(x+1);
            }
        }
    }
}

int main()
{
    while (cin >> n)
    {
        for (int i=0; i<n; i++)
            cin >> pass[i];
        cin >> m;
        cout << "--" << endl;
        for (int i=0; i<m; i++)
        {
            cin >> rule;
            passwords(0);
        }
    }
}
