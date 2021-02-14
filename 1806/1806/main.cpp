#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> dp;
int N,S,result = 100001;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int sum = 0,cur;
    vector<int>::iterator it;
    
    cin >> N >> S;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        
        sum += num;
        dp.push_back(sum); // 각 시점에서의 합을 저장
    }
    
    it = lower_bound(dp.begin(),dp.end(),S);
    if(it == dp.end()) // 처음부터 끝까지 다 더했는데 S값보다 작게 나온다면 불가능
    {
        cout << 0 << '\n';
        return 0;
    }
    result = (int)(it-dp.begin())+1; // 불가능하지 않다면 길이 측정 후 result 초기값에 반영
    
    // N * logN
    sum = 0;
    for(int i = 1; i < N; i++) // 0번 인덱스부터 계산하는건 앞에서 계산했으므로 Pass
    {
        int prev = dp[i-1]; // 바로 이전까지의 합을 미리 저장
        
        it = lower_bound(dp.begin(),dp.end(),S+prev); // S+이전값 이상인 첫 인덱스 가져오기
        if(it == dp.end()) // 없네?
            continue; // Pass
        cur = (int)(it-dp.begin()-i)+1; // 길이 계산
        result = min(result,cur);
    }
    
    cout << result << '\n';
    return 0;
}
