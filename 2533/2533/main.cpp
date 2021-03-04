#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;

int N;
bool visited[MAX] = {0,};
vector<int> Tree[MAX];
int dp[MAX][2] = {0,}; // MAX번째 사람이 얼리어답터가 아님 / 맞음

void recursive(int num)
{
    visited[num] = true;
    dp[num][0] = 0;
    dp[num][1] = 1;
    for(int i = 0; i < Tree[num].size(); i++)
    {
        if(visited[Tree[num][i]]) // already visited
            continue;
        recursive(Tree[num][i]);
        dp[num][0] += dp[Tree[num][i]][1];
        dp[num][1] += min(dp[Tree[num][i]][0],dp[Tree[num][i]][1]);
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N-1; i++)
    {
        int A,B;
        cin >> A >> B;
        Tree[A].push_back(B);
        Tree[B].push_back(A); // 방향성이 없는 경로이므로
    }
    
    recursive(1);
    cout << min(dp[1][0],dp[1][1]) << '\n';
    return 0;
}
