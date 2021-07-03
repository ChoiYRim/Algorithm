//#include <iostream>
//#include <algorithm>
//
//#define COIN 100005
//#define INF 987654321
//
//using namespace std;
//
//int N,K;
//int dp[COIN];
//
//int main(int argc, const char * argv[])
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    fill(dp,dp+COIN,INF);
//
//    cin >> N >> K;
//    for(int i = 0; i < N; i++)
//    {
//        int coin;
//        cin >> coin;
//        dp[coin] = 1;
//    }
//
//    // i원을 만들기 위한 방법의 수
//    for(int i = 1; i <= K; i++)
//    {
//        for(int j = 1; j < i; j++)
//        {
//            dp[i] = min(dp[i],dp[j] + dp[i-j]);
//        }
//    }
//
//    if(dp[K] >= INF)
//        cout << -1 << '\n';
//    else
//        cout << dp[K] << '\n';
//    return 0;
//}

#include <vector>
#include <iostream>
#include <algorithm>

#define COIN 10001
#define INF 987654321

using namespace std;

int N,K;
vector<int> v;
int dp[COIN];

int main(int argc,const char* argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    fill(dp,dp+COIN,INF);
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        int coin;
        cin >> coin;
        v.push_back(coin);
    }
    sort(v.begin(),v.end());
    
    dp[0] = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = v[i]; j <= K; j++)
            dp[j] = min(dp[j],dp[j-v[i]]+1);
    }
    
    if(dp[K] >= INF)
        cout << -1 << '\n';
    else
        cout << dp[K] << '\n';
    return 0;
}
