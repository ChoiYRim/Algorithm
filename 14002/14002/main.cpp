#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
vector<vector<int>> Set;

inline bool comp(const vector<int>& v1,const vector<int>& v2) { return v1.size() > v2.size(); }

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num;
        vector<int> temp;
        cin >> num;
        v.push_back(num);
        temp.push_back(num);
        Set.push_back(temp);
    }
    
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(v[i] > v[j] && Set[j].size()+1 > Set[i].size())
            {
                Set[i].clear();
                Set[i].push_back(v[i]);
                Set[i].insert(Set[i].end(),Set[j].begin(),Set[j].end());
            }
        }
    }
    
    stable_sort(Set.begin(),Set.end(),comp);
    
    cout << Set[0].size() << '\n';
    for(int i = (int)Set[0].size()-1; i >= 0; i--)
    {
        cout << Set[0][i] << " ";
    }
    cout << '\n';
    return 0;
}
