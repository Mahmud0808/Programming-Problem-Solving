#include <iostream>
using namespace std;

#define ll long long int

int main()
{
    string s;
    int zero, next_zero, total;
    while (cin >> s)
    {
        total=s.size();
        zero=0, next_zero=0;
        for (int i=0; i<total; i++)
        {
            if (s[i]=='0')
            {
                zero++;
                if (s[(i+1)%total]=='0')
                    next_zero++;
            }
        }
        int rotate = zero * zero, shoot = next_zero * total;
        if (rotate == shoot)
            cout << "EQUAL" << endl;
        else if (rotate > shoot)
            cout << "ROTATE" << endl;
        else
            cout << "SHOOT" << endl;
    }
}
