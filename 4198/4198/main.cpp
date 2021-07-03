#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> train;
vector<int> mTrain;

int longest_increasing(int idx,vector<int> T)
{
    int i;
    vector<int> v;
    v.push_back(T[idx]);
    
    for(i = idx+1; i < N; i++)
    {
        if(v.front() > T[i])
            continue;
        if(v.back() < T[i])
            v.push_back(T[i]);
        else
        {
            auto it = lower_bound(v.begin(),v.end(),T[i])-v.begin();
            v[it] = T[i];
        }
    }
    
    return (int)v.size();
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int result = 0;

    cin >> N;
    if(N <= 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    train = vector<int>(N,0);
    mTrain = vector<int>(N,0);
    for(int i = 0; i < N; i++)
    {
        cin >> train[i];
        mTrain[i] = -train[i];
    }
    
    for(int i = 0; i < N; i++)
    {
        int lis = longest_increasing(i,train);
        int lds = longest_increasing(i,mTrain);
        
        result = max(result,lis+lds-1);
    }
    
    cout << result << '\n';
    return 0;
}
