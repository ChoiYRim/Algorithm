#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int team1[15] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int team2[15] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};

int input[4][6][3];
int result[6][3];
int ans[4];

void dfs(int depth)
{
    // 모든 경기를 마쳤다면
    if(depth == 15)
    {
        for(int t = 0; t < 4; t++)
        {
            // 이미 존재하는 경우로 판별됐다면
            if(ans[t]==1)
                continue;
            
            bool flag = true;
            for(int i = 0; i < 6; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(input[t][i][j] != result[i][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(flag)
            {
                ans[t] = 1;
                return;
            }
        }
        return;
    }
    
    int t1 = team1[depth];
    int t2 = team2[depth];
    
    // t1 win, t2 lose
    result[t1][0]++;
    result[t2][2]++;
    dfs(depth+1);
    result[t1][0]--;
    result[t2][2]--;
    
    // t1 draw, t2 draw
    result[t1][1]++;
    result[t2][1]++;
    dfs(depth+1);
    result[t1][1]--;
    result[t2][1]--;
    
    // t1 lose, t2 win
    result[t1][2]++;
    result[t2][0]++;
    dfs(depth+1);
    result[t1][2]--;
    result[t2][0]--;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int tc = 0; tc < 4; tc++)
    {
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cin >> input[tc][i][j];
            }
        }
    }
    
    dfs(0);
    
    for(int i = 0; i < 4; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
