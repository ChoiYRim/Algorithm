#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int TC;
vector<int> v;
int result = 0;
int dp[1010][1010] = {0,};

int recur(int first,int last,int turn)
{
    if(last < first)
        return 0;
    if(dp[first][last])
        return dp[first][last];
    
    if(!(turn % 2)) // A
    {
        return dp[first][last] = max(v[first]+recur(first+1,last,turn+1),v[last]+recur(first,last-1,turn+1));
    }
    
    return dp[first][last] = min(recur(first+1,last,turn+1),recur(first,last-1,turn+1));
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    cin >> TC;
    //getchar();
    while(TC--)
    {
        int N,front,back;
        
        v.clear();

        cin >> N;
        //getchar();
        for(int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            //getchar();
            v.push_back(num);
        }
        
        if(N <= 1)
        {
            cout << v[0] << '\n';
            continue;
        }
        
        memset((int *)dp,0,sizeof(dp));
        cout << recur(0,N-1,0) << '\n';
    }
    
    return 0;
}
