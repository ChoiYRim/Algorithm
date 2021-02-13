#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M,result = 0;
vector<int> v;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    for(int i = 0; i < N; i++)
    {
        int sum = 0;
        for(int j = i; j < N; j++)
        {
            if(sum+v[j] < M)
                sum += v[j];
            else if(sum+v[j] == M)
            {
                result++;
                break;
            }
            else
                break;
        }
    }
    
    cout << result << '\n';
    return 0;
}
