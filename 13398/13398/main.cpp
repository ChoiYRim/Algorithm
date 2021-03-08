#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int N,result;
vector<int> v;
int dp1[MAX] = {0,}; // 한개도 제거하지 않았을 때
int dp2[MAX] = {0,}; // 한개 뺐을 때 최대값

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    dp1[0] = v[0];
    dp2[0] = v[0];
    result = max(dp1[0],dp2[0]);
    for(int i = 1; i < N; i++)
    {
        dp1[i] = max(dp1[i-1]+v[i],v[i]);
        dp2[i] = max(dp2[i-1]+v[i],dp1[i-1]);
        result = max(dp1[i],max(result,dp2[i]));
    }
    
    cout << result << '\n';
    return 0;
}
