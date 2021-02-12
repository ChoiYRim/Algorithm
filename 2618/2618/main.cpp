#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAX 987654321
#define ABS(x) (x >= 0 ? x : -x)

using namespace std;

int N,W;
pair<int,int> v[1010];
// Dp[X][Y] : [1번 경찰차가 마지막으로 해결한 사건 번호][2번 경찰차가 마지막으로 해결한 사건 번호]
int Dp[1010][1010];

inline int dist(pair<int,int> a,pair<int,int> b)
{
    return ABS((a.first-b.first))+ABS((a.second-b.second));
}

int memoization(int A,int B)
{
    if(A >= W || B >= W)
        return 0;
    
    int next = max(A,B) + 1;
    int dist1,dist2;
    
    int& cache = Dp[A][B];
    if(cache != -1) // already visited
        return Dp[A][B];
    
    if(A == 0)
        dist1 = dist({1,1},v[next]);
    else
        dist1 = dist(v[A],v[next]);
    
    if(B == 0)
        dist2 = dist({N,N},v[next]);
    else
        dist2 = dist(v[B],v[next]);
    
    cache = min(memoization(next,B)+dist1,memoization(A,next)+dist2);
    return cache;
}

void path(int A,int B)
{
    if(A >= W || B >= W)
        return;
    
    int next = max(A,B)+1;
    int dist1,dist2;
    
    if(A == 0)
        dist1 = dist({1,1},v[next]);
    else
        dist1 = dist(v[A],v[next]);
    
    if(B == 0)
        dist2 = dist({N,N},v[next]);
    else
        dist2 = dist(v[B],v[next]);
    
    int result1 = dist1+memoization(next,B);
    int result2 = dist2+memoization(A,next);
    
    if(result1 > result2)
    {
        cout << 2 << '\n';
        path(A,next);
    }
    else
    {
        cout << 1 << '\n';
        path(next,B);
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
            
    cin >> N >> W;
    for(int i = 0; i < W; i++)
    {
        int y,x;
        cin >> y >> x;
        v[i+1] = {y,x};
    }
    
    memset((int *)Dp,-1,sizeof(Dp));
    cout << memoization(0,0) << '\n';
    path(0,0);
    return 0;
}
