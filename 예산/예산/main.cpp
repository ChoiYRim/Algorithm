#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool comp(const int& i1,const int& i2) { return i1 < i2; }

int solution(vector<int> d,int budget)
{
    int answer = 0,idx = 0;
    
    sort(d.begin(),d.end(),comp);
    
    while(budget - d[idx] >= 0 && idx < (int)d.size())
    {
        budget -= d[idx];
        idx++;
        answer++;
    }
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int budget = 10;
    vector<int> d = {2,2,3,3};
    
    //int budget = 9;
    //vector<int> d = {1,3,2,5,4};
    
    cout << solution(d,budget) << '\n';
    return 0;
}
