#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,result = -1;
vector<int> v;

int gcd(int a,int b)
{
    if(b != 0)
        return gcd(b,a%b);
    return a;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    cout << result << '\n';
    return 0;
}
