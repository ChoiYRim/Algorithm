#include <vector>
#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    int n;
    int maxNum = -INF;
    vector<int> arr;
    vector<int> DP;
    vector<vector<int>> line;
    
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        vector<int> v;
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
        line.push_back(v);
    }
    
    sort(line.begin(),line.end());
    
    for(int i = 0; i < n; ++i)
    {
        DP.push_back(1);
        arr.push_back(line[i][1]);
    }
    
    DP[0] = 1;
    for(int i = 1; i < n; ++i)
    {
        for(int j = i; j >= 0; --j)
            if(arr[i] > arr[j] && DP[i] <= DP[j])
                DP[i] = DP[j] + 1;
    }
     
    for(int i = 0; i < n; ++i)
        maxNum = max(maxNum, DP[i]);
    
    cout << DP.size() - maxNum << endl;
    return 0;
}
