#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<long long> v;
map<long long,int> m;

inline bool comp(const pair<long long,int>& p1,const pair<long long,int>& p2)
{
    return p1.second > p2.second;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<long long,int>::iterator it;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        long long ll;
        cin >> ll;
        v.push_back(ll);
        
        it = m.find(ll);
        if(it != m.end())
            it->second++;
        else
            m.insert({ll,1});
    }
    
    vector<pair<long long,int>> answer(m.begin(),m.end());
    stable_sort(answer.begin(),answer.end(),comp);
    
    cout << answer[0].first << '\n';
    return 0;
}
