#include <iostream>
#include <cmath>
using namespace std;

#define g 9.81

int main()
{
    double k, l, s, w;
    while (cin >> k >> l >> s >> w && k+l+s+w)
    {
        if (s<=l)
        {
            // v²=u²+2as ; where u=0
            double v=sqrt(2.0*g*s);
            if (v>10.0)
                cout << "Killed by the impact." << endl;
            else
                cout << "James Bond survives." << endl;
        }
        else
        {
            // Ei (Energy initial) = Ef (Energy Final)
            // mgh = (1/2)kx²
            // x = stretched length of rope
            double left=(w*g*s), right=(0.5*k*pow((s-l), 2));
            if (left<right)
                cout << "Stuck in the air." << endl;
            else
            {
                double E=left-right;
                // E = (1/2)mv²
                // v² = E/((1/2)m)
                // v² = 2E/m
                // v = √(2E/m)
                double v=sqrt((2.0*E)/w);
                if (v>10.0)
                    cout << "Killed by the impact." << endl;
                else
                    cout << "James Bond survives." << endl;
            }
        }
    }
}
