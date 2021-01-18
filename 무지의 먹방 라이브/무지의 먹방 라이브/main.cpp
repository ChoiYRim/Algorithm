#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _rotate
{
    int index;
    int food;
}Rotate;

struct comp
{
    bool operator()(const Rotate &r1,const Rotate &r2)
    {
        return r1.food > r2.food;
    }
};

inline bool lastComp(const Rotate &r1,const Rotate &r2) { return r1.index < r2.index; }

int solution(vector<int> food_times,long long k)
{
    /* 정확성 통과 ,but 효율성 실패
     
    int answer = 0,idx = 0;
    long long time = 0;
    vector<Rotate> v;
    bool check;
    
    for(int i = 0; i < (int)food_times.size(); i++)
        v.push_back({i+1,food_times[i]});
    
    while(time < k)
    {
        v[idx].food--;
        check = true;
        while(idx < (int)v.size() && v[idx].food == 0)
        {
            check = false;
            v.erase(v.begin()+idx);
        }
        if((int)v.size() <= 0)
        {
            return -1;
        }
        if(idx == (int)v.size())
            idx = 0;
        if(check)
            idx = (idx+1)%(int)v.size();
        
        time++;
    }
    answer = v[idx].index;
    */
    
    // 참조 : https://mungto.tistory.com/9
    
    int answer = 0;
    long long prev = 0,sum = 0;
    priority_queue<Rotate,vector<Rotate>,comp> pq;
    
    for(int i = 0; i < (int)food_times.size(); i++)
    {
        sum += food_times[i];
        pq.push({i+1,food_times[i]});
    }
    
    if(sum <= k)
        return -1;
    
    while((pq.top().food - prev) * pq.size() <= k)
    {
        k -= (pq.top().food - prev) * pq.size();
        prev = pq.top().food;
        pq.pop();
    }
    
    vector<Rotate> foods;
    while(!pq.empty())
    {
        Rotate element = pq.top();
        pq.pop();
        foods.push_back({element.index,element.food});
    }
    
    sort(foods.begin(),foods.end(),lastComp);
    answer = foods[k % (int)foods.size()].index;
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //long long k = 1833;
    //vector<int> food_times = {946, 314, 757, 322, 559, 647, 983, 482, 145};
    
    long long k = 5;
    vector<int> food_times = {3,1,2};
    
    cout << solution(food_times,k) << '\n';
    return 0;
}
