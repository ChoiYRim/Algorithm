#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<long long> v;
long long dp[2010][2010]; // [i][j] : i~j구간 사이에서의 최대값

inline int Front(int idx)
{
    return (idx+1)%N;
}

inline int Back(int idx)
{
    return (idx-1 < 0 ? N-1 : (idx-1)%N);
}

long long DFS(int turn,int left,int right)
{
    int nextLeft = Back(left);
    int nextRight = Front(right);

    if(!(turn % 2))
    {
        if(dp[left][right] != -1)
            return dp[left][right];

        if(nextRight == left)
            return 0;

        return dp[left][right] = max(v[nextLeft]+DFS(turn+1,nextLeft,right),v[nextRight]+DFS(turn+1,left,nextRight));
    }

    if(nextRight == left)
        return 0;

    if(v[nextLeft] < v[nextRight])
        return DFS(turn+1,left,nextRight);
    return DFS(turn+1,nextLeft,right);
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
    }

    long long result = 0;
    memset((long long *)dp,-1,sizeof(dp));
    for(int i = 0; i < N; i++)
    {
        result = max(result,v[i]+DFS(1,i,i));
    }

    cout << result << '\n';
    return 0;
}
