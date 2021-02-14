#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> v,result;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    // Brute Force
    for(int i = 0; i < N; i++)
    {
        int order = 0;
        for(int j = i; j >= 0; j--)
        {
            if(v[i] < v[j])
                order++;
        }
        result.push_back(order+1);
    }
    
    for(int i = 0; i < N; i++)
        cout << result[i] << '\n';
    return 0;
}
