#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int L,P,V; // 1 < L < P < V

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int step = 1;
    
    while(1)
    {
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0)
            break;
        
        int A = V / P;
        int B = V % P;
        int answer;
        
        if(B < L)
            answer = A * L + B;
        else
            answer = A * L + L;
        printf("Case %d: %d\n", step++, answer);
    }
    
    return 0;
}
