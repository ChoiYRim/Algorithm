#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,S = 0;
vector<int> A,B;

inline bool comp(int& i1,int& i2) { return i1 > i2; }

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a,b;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        A.push_back(a);
    }
    for(int i = 0; i < N; i++)
    {
        cin >> b;
        B.push_back(b);
    }
    
    sort(A.begin(),A.end(),comp);
    sort(B.begin(),B.end());
    
    for(int i = 0; i < N; i++)
        S += (A[i]*B[i]);
    
    cout << S << '\n';
    return 0;
}
