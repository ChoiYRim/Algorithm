#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M,weight[32];
int dp[32][30*500+1]; // [추의 개수] [추를 사용해 만들어 낼 수 있는 무게값]
int bead[8];

void DFS(int depth,int sum)
{
    if(depth > N)
        return;
    if(dp[depth][sum] != -1)
        return;
    dp[depth][sum] = 1;
    
    // 구슬이 없는 저울에 추를 추가
    DFS(depth+1,sum+weight[depth]);
    // 저울에 추를 추가하지 않음
    DFS(depth+1,sum);
    // 구슬이 있는 저울에 추를 추가
    DFS(depth+1,abs(sum-weight[depth]));
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> weight[i];
    cin >> M;
    for(int i = 0; i < M; i++)
        cin >> bead[i];
    memset((int *)dp,-1,sizeof(dp));
    DFS(0,0);
    
    for(int i = 0; i < M; i++)
    {
        if(bead[i] > 30*500)
            cout << "N" << ' ';
        else if(dp[N][bead[i]] != -1)
            cout << "Y" << ' ';
        else
            cout << "N" << ' ';
    }
    cout << '\n';
    return 0;
}
