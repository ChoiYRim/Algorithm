#include <iostream>
#include <algorithm>

using namespace std;

int N,m;
int A[1001] = {0,};
int dp[1001] = {0,};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    m = -1;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
        dp[i] = 1;
    }
    
    for(int i = 1; i < N; i++)
    {
        int pivot = A[i];
        for(int j = i-1; j >= 0; j--)
        {
            if(pivot < A[j] && dp[i] < dp[j]+1)
                dp[i] = dp[j]+1;
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        if(m < dp[i])
            m = dp[i];
    }
    cout << m << '\n';
    return 0;
}

