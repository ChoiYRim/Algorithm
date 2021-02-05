#include <iostream>
#include <algorithm>

using namespace std;

int N,m = -1;
int A[1001];
int dp[1001];

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
        dp[i] = A[i];
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(A[i] < A[j] && dp[j] < dp[i] + A[j])
            {
                dp[j] = dp[i]+A[j];
                //m = max(m,dp[j]);
            }
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        m = max(m,dp[i]);
    }
    
    cout << m << '\n';
    return 0;
}
