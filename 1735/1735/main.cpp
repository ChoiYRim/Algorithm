#include <iostream>
#include <algorithm>

using namespace std;

int S1,P1;
int S2,P2;

int gcd(int a,int b)
{
    if(b != 0)
        return gcd(b,a%b);
    return a;
}

int lcm(int a,int b)
{
    return a * b / gcd(a,b);
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> S1 >> P1;
    cin >> S2 >> P2;
    
    int LCM = lcm(P1,P2);
    S1 = LCM / P1 * S1;
    S2 = LCM / P2 * S2;
    
    int S3 = S1+S2;
    int GCD = gcd(S3,LCM);
    while(GCD > 1)
    {
        S3 /= GCD;
        LCM /= GCD;
        GCD = gcd(S3,LCM);
    }
    
    cout << S3 << " " << LCM << '\n';
    return 0;
}
