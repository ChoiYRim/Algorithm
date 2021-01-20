#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N; // the number of stages

inline bool ascending_comp(const int &n1,const int &n2) { return n1 < n2; }

inline bool descending_comp(const pair<double,int> &n1,const pair<double,int> &n2)
{ return n1.first > n2.first; }

vector<int> solution(int N,vector<int> stages)
{
    int step = 1,len;
    vector<int> answer;
    vector<int>::iterator it;
    vector<pair<double,int>> result;
    
    sort(stages.begin(),stages.end(),ascending_comp); // 오름차순 정렬
    
    while((int)result.size() < N)
    {
        int cnt = 0;
        len = (int)stages.size();
        for(it = stages.begin(); it != stages.end() && *it == step; it++)
            cnt++;
        step++;
        stages.erase(stages.begin(),stages.begin()+cnt);
        double temp = cnt / (double)len;
        result.push_back({temp,step-1});
    }
    stable_sort(result.begin(),result.end(),descending_comp);
    for(int i = 0; i < (int)result.size(); i++)
        answer.push_back(result[i].second);
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //N = 5;
    //vector<int> stages = {2,1,2,6,2,4,3,3};
    
    N = 4;
    vector<int> stages = {4,4,4,4};
    vector<int> result = solution(N,stages);
    
    return 0;
}
