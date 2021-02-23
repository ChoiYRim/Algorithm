#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

vector<int> v;
int result = INF,N;
int dp[5][5][100001];

int power(int curPos,int nextPos)
{
    if(curPos == 0 || nextPos == 0)
        return 2;
    else if(abs(curPos-nextPos) == 1 || abs(curPos-nextPos) == 3)
        return 3;
    else if(abs(curPos-nextPos) == 2)
        return 4;
    return 1;
}

int DFS(pair<int,int> pos,int idx)
{
    if(idx >= N) // N-1까지임
        return 0;
    if(dp[pos.first][pos.second][idx] != -1)
        return dp[pos.first][pos.second][idx];
    
    int cur = v[idx],first = power(pos.first,cur),second = power(cur,pos.second);
    pair<int,int> fpos = {cur,pos.second};
    pair<int,int> spos = {pos.first,cur};
    
    return dp[pos.first][pos.second][idx] = min(DFS(fpos,idx+1)+first,DFS(spos,idx+1)+second);
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int num = -1;
    pair<int,int> pos = {0,0};
    
    while(1)
    {
        cin >> num;
        if(num != 0)
            v.push_back(num);
        else
            break;
    }
    
    N = (int)v.size();
    memset((int *)dp,-1,sizeof(dp));
    DFS(pos,0); // {0,0}에서 시작
    
    cout << dp[0][0][0] << '\n';
    return 0;
}
