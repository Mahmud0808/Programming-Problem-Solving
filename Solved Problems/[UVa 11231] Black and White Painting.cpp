#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, m, c;
    while (cin >> n >> m >> c && (n || m || c))
    {
        int board=(((n-7)*(m-7))+c)/2;
        cout << board << endl;
    }
}
