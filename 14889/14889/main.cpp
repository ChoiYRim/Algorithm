#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int n,result = INT_MAX;
int s[22][22];
int team1[11];
int team2[11];

void make_team2(void)
{
    int cnt = 0;
    
    for(int i = 1; i <= n; i++)
    {
        int member = 0;
        
        for(int j = 0; team1[j] != 0 && j < n/2; j++)
        {
            if(team1[j] == i)
            {
                member = 0;
                break;
            }
            member = i;
        }
        if(member)
            team2[cnt++] = member;
    }
}

int calculate(int team[11])
{
    int ret = 0;
    
    for(int i = 0; team[i] != 0 && i < n/2; i++)
    {
        for(int j = i+1; team[j] != 0 && j < n/2; j++)
        {
            ret += s[team[i]][team[j]] + s[team[j]][team[i]];
        }
    }
    
    return ret;
}

void dfs(int player,int team_size)
{
    if(!result) // 차이가 0이면 더 이상 할 필요가 없음
        return;
    
    //if(n/2-(team_size+1) > n-player)
    //    return;
    
    team1[team_size] = player;
    
    if(team_size >= n/2-1)
    {
        int sum,sum1,sum2;
        make_team2();
        sum1 = calculate(team1);
        sum2 = calculate(team2);
        
        if(sum1-sum2 < 0)
            sum = -(sum1-sum2);
        else
            sum = sum1-sum2;
        
        result = min(result,sum);
        return;
    }
    
    for(int i = player+1; i <= n; i++)
        dfs(i,team_size+1);
}

int main(int argc, const char * argv[])
{
    memset((int *)team1,0,sizeof(team1));
    memset((int *)team2,0,sizeof(team2));
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> s[i][j];
    }
    
    for(int i = 1; i < n/2; i++)
    {
        dfs(i,0);
    }
    
    cout << result << '\n';
    return 0;
}
