#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
vector<int> v;
int result = 0;

inline bool comp(int& i1,int& i2) { return i1 > i2; }

long long getSum(int lim)
{
    long long sum = 0;
    
    for(int i = 0; i < N; i++)
        if(v[i] > lim)
            sum += (v[i]-lim);
    
    return sum;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long sum = 0;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        int tree;
        cin >> tree;
        v.push_back(tree);
    }
        
    sort(v.begin(),v.end());

    int left = 0,right = v[N-1],mid = (left+right)/2;
    while(left <= right)
    {
        sum = getSum(mid);
        
        if(sum < M) // 더 많은 나무를 벨 수 있게 기준점을 낮춰야함
            right = mid-1;
        else if(sum >= M) // 해를 찾음
        {
            left = mid+1;
            result = max(result,mid);
        }
        
        mid = (left+right)/2;
    }
        
    cout << result << '\n';
    return 0;
}
