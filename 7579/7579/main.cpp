/* 전형적인 Knapsack Problem에서 쪼갤 수 없는 배낭 문제 -> DP */

#include <iostream>
#include <algorithm>

using namespace std;

struct App
{
    int m; // memory
    int c; // cost
};

int N,M,cost = 0;
App app[101];
int DP[10001] = {0,}; // N의 최대값 * Cost의 최대값

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m,c;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> m;
        app[i].m = m;
    }
    for(int i = 0; i < N; i++)
    {
        cin >> c;
        app[i].c = c;
    }
    
    for(int i = 0; i < N; i++)
    {
        int cost = app[i].c;
        for(int j = 10000; j >= cost; j--)
        {
            if(DP[j-cost] < 0)
                continue;
            if(DP[j-cost] + app[i].m > DP[j])
                DP[j] = DP[j-cost] + app[i].m;
        }
    }
    
    for(int i = 0; i < 10001; i++)
    {
        if(DP[i] >= M)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
