#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int N;
vector<int> dp[1000002];

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    dp[1].push_back(1);
    dp[2].push_back(2); dp[2].push_back(1);
    dp[3].push_back(3); dp[3].push_back(1);
    
    for(int i = 4; i <= N; i++)
    {
        int cur = i;
        size_t case1,case2,case3;
        
        case1 = case2 = case3 = INF;
        
        dp[i].push_back(cur);
        if(cur%3 == 0)
            case3 = dp[cur/3].size();
        if(cur%2 == 0)
            case2 = dp[cur/2].size();
        case1 = dp[cur-1].size();
        
        if(case1 <= case2)
        {
            if(case1 <= case3)
            {
                dp[i].insert(dp[i].end(),dp[cur-1].begin(),dp[cur-1].end());
            }
            else
            {
                dp[i].insert(dp[i].end(),dp[cur/3].begin(),dp[cur/3].end());
            }
        }
        else
        {
            if(case2 <= case3)
            {
                dp[i].insert(dp[i].end(),dp[cur/2].begin(),dp[cur/2].end());
            }
            else
            {
                dp[i].insert(dp[i].end(),dp[cur/3].begin(),dp[cur/3].end());
            }
        }
    }
    
    cout << dp[N].size()-1 << '\n';
    for(int i = 0; i < dp[N].size(); i++)
        cout << dp[N][i] << " ";
    cout << '\n';
    return 0;
}
