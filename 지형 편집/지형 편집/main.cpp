#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// P : 추가 , Q : 삭제 비용
long long solution(vector<vector<int>> land,int P,int Q)
{
    int N = (int)land.size();
    long long answer = INT_MAX;
    vector<pair<int,int>> Set; map<int,int> m;
    
    for(int i = 0; i < (int)land.size(); i++)
    {
        map<int,int>::iterator it;
        for(int j = 0; j < (int)land[i].size(); j++)
        {
            it = m.find(land[i][j]);
            if(it != m.end())
                it->second++;
            else
                m.insert({land[i][j],1});
        }
    }
    
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int P = 5,Q = 3;
    vector<vector<int>> land = {{4, 4, 3},{3, 2, 2},{2, 1, 0}};
    
    cout << solution(land,P,Q) << '\n';
    return 0;
}
