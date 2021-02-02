#include <iostream>
#include <algorithm>

#define MAX 1000000000

using namespace std;

int main(void)
{
    long long X, Y, Z, left, right, mid, newZ;
    
    cin >> X >> Y;
    
    Z = 100 * Y / X;
    
    if(Z >= 99)
    {
        cout << -1;
        return 0;
        
    }
    
    left = 0;
    right = MAX;
    
    while(left <= right)
    {
        mid = (left + right) / 2;
        newZ = 100 * (Y + mid) / (X + mid);
        
        if(Z < newZ)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        
    }
    
    cout << left << '\n';
    return 0;
}
