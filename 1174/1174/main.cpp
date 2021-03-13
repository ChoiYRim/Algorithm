#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int n;
    cin >> n;

    vector<long long> ans;
    for(int i = 1; i < (1 << 10); i++)
    {
        long long sum = 0;
        for(int j = 0; j < 10; j++)
        {
            if (i & (1 << j))
                sum = sum * 10 + v[j];
        }
        ans.push_back(sum);
    }
    
    sort(ans.begin(), ans.end());
    if(n > ans.size())
        cout << -1 << '\n';
    else
        cout << ans[n - 1] << '\n';
    return 0;
}
