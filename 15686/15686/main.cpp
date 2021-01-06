/*
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int n,m; // 도시의 크기 , 치킨집의 개수
int dis[51][51];
int map[51][51];
int result = INT_MAX;
bool pick[15]; // 고른 치킨집의 좌표
vector<pair<int,int>> p; // 고른 치킨집 좌표
vector<pair<int,int>> c; // 전체 치킨집의 좌표
vector<pair<int,int>> home; // 전체 집들의 좌표

int ABS(int a)
{
    return a < 0 ? -a : a;
}

int distance(pair<int,int> a,pair<int,int> b)
{
    int ret = 0;
    
    ret = ABS(a.first-b.first) + ABS(a.second-b.second);
    
    return ret;
}

int get_result(int size)
{
    int mi,sum = 0;
    
    for(int i = 0; i < home.size(); i++)
    {
        mi = INT_MAX;
        
        for(int j = 0; j <= size; j++)
            mi = min(mi,distance(home[i],p[j]));
        
        dis[home[i].first][home[i].second] = mi;
        sum += mi;
    }
    
    return sum;
}

void dfs(int depth)
{
    if(depth == m)
    {
        result = min(result,get_result(depth-1));
        return;
    }
    
    for(int i = 0; i < c.size(); i++)
    {
        if(pick[i])
            continue;
        pick[i] = true;
        p.push_back(c[i]);
        dfs(depth+1);
        p.pop_back();
        pick[i] = false;
    }
}

int main(int argc, const char * argv[])
{
    memset((int *)dis,0,sizeof(dis));
    memset((bool *)pick,0,sizeof(pick));
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2)
                c.push_back({i,j});
            if(map[i][j] == 1)
                home.push_back({i,j});
        }
    }
    
    dfs(0);
    cout << result << '\n';
    return 0;
}
*/

#include<iostream>
#include<vector>
#include<cmath>
 
#define endl "\n"
#define MAX 50
using namespace std;
 
int N, M, Chicken_Num, Answer;
int MAP[MAX][MAX];
bool Select[13];
 
vector<pair<int, int>> House, Chicken, V;
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Input()
{
    Answer = 99999999;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1) House.push_back(make_pair(i, j));
            if (MAP[i][j] == 2) Chicken.push_back(make_pair(i, j));
        }
    }
    Chicken_Num = Chicken.size();
}
 
int Calculate_Distance()
{
    int Sum = 0;
    for (int i = 0; i < House.size(); i++)
    {
        int x = House[i].first;
        int y = House[i].second;
        int d = 99999999;
 
        for (int j = 0; j < V.size(); j++)
        {
            int xx = V[j].first;
            int yy = V[j].second;
            int Dist = abs(xx - x) + abs(yy - y);
 
            d = Min(d, Dist);
        }
        Sum = Sum + d;
    }
    return Sum;
}
 
void Select_Chicken(int Idx, int Cnt)
{
    if (Cnt == M)
    {
        Answer = Min(Answer, Calculate_Distance());
        return;
    }
 
    for (int i = Idx; i < Chicken_Num; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        V.push_back(Chicken[i]);
        Select_Chicken(i, Cnt + 1);
        Select[i] = false;
        V.pop_back();
    }
}
 
void Solution()
{
    Select_Chicken(0, 0);
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
