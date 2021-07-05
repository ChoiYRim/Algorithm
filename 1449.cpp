#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,L;
vector<int> water;

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int result;
    
    cin >> N >> L;
    for(int i = 0; i < N; i++)
    {
        int w;
        cin >> w;
        water.push_back(w);
    }
    
    sort(water.begin(),water.end());
    
    float cur = (float)water[0]-0.5+(float)L;
    result = 1;
    
    for(int i = 1; i < N; i++)
    {
        if(cur <= (float)water[i])
        {
            result++;
            cur = (float)water[i]-0.5+(float)L;
        }
        else
            continue;
    }
    
    cout << result << '\n';
    return 0;
}
