#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,P,S;
vector<pair<int,int>> scores;

inline bool comp(pair<int,int>& p1,pair<int,int>& p2) { return p1.second < p2.second; }

inline bool revComp(pair<int,int>& p1,pair<int,int>& p2) { return p1.second > p2.second; }

int getResult(void)
{
    int rank = 0,idx = 0,cnt = 0,i;
    bool equal = false;
    
    for(i = 0; i < (int)scores.size(); i++)
    {
        int score = scores[i].second;
        
        idx = i;
        if(S == score)
        {
            equal = true;
            break;
        }
        else if(S < score)
            break;
    }
    
    if(!equal)
    {
        while(i < (int)scores.size() && scores[idx].second == scores[i].second)
        {
            cnt++;
            i++;
        }
        rank = scores[idx].first+cnt;
        if(rank > P)
            return -1;
    }
    else
    {
        while(i < (int)scores.size() && S == scores[i].second)
        {
            cnt++;
            i++;
        }
        rank = scores[idx].first;
        if(rank+cnt > P)
            return -1;
    }
    
    return rank;
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int prev,cnt;
        
    cin >> N >> S >> P;
    for(int i = 0; i < N; i++)
    {
        int score;
        cin >> score;
        scores.push_back({0,score});
    }
    if(!N)
    {
        cout << 1 << '\n';
        return 0;
    }
    
    sort(scores.begin(),scores.end(),revComp);
    cnt = 1;
    scores[0].first = 1;
    prev = scores[0].second;
    for(int i = 1; i < N; i++)
    {
        if(prev > scores[i].second)
        {
            scores[i].first = scores[i-1].first+cnt;
            prev = scores[i].second;
            cnt = 1;
        }
        else if(prev == scores[i].second)
        {
            cnt++;
            scores[i].first = scores[i-1].first;
        }
    }
    sort(scores.begin(),scores.end(),comp);
    
    int rank = getResult();
    cout << rank << '\n';
    return 0;
}
