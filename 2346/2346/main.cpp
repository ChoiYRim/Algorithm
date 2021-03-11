#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> v;
vector<int> result;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int cur,next = 0;
        
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back({num,i+1});
    }
    
    while(v.size() > 0)
    {
        cur = next;
        result.push_back(v[cur].second); // 터뜨릴 풍선 pick
        
        int pick = v[cur].first;
        if(pick < 0)
        {
            while(pick++ < 0)
            {
                next--;
                if(next < 0)
                    next = (int)v.size()-1;
                if((int)v.size() > 1 && next == cur)
                    pick--;
            }
        }
        else
        {
            while(pick-- > 0)
            {
                next++;
                if(next >= (int)v.size())
                    next = 0;
                if((int)v.size() > 1 && next == cur)
                    pick++;
            }
        }
        
        if(cur < next)
        {
            next--;
            if(next < 0)
                next = (int)v.size()-2;
        }
        
        v.erase(v.begin()+cur);
    }
    
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
    cout << '\n';
    return 0;
}
