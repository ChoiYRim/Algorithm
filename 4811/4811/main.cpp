#include <iostream>
#include <algorithm>

using namespace std;

long long dp[31][31] = {0,};

long long DFS(int W,int H)
{
    if(dp[W][H] != 0)
        return dp[W][H];
    if(W == 0)
        return 1;
    
    dp[W][H] = DFS(W-1,H+1);
    if(H > 0)
        dp[W][H] += DFS(W,H-1);
    
    return dp[W][H];
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    while(1)
    {
        int W;
        cin >> W;
        
        if(W == 0)
            break;
        
        cout << DFS(W,0) << '\n';
    }
    return 0;
}
