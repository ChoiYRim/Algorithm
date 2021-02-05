#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> dp;
int N,result = 0;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    dp.push_back(-1);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if(num > dp.back())
        {
            dp.push_back(num);
            result++;
        }
        else
        {
            vector<int>::iterator it = lower_bound(dp.begin(),dp.end(),num);
            *it = num;
        }
    }
    
    cout << result << '\n';
    return 0;
}
