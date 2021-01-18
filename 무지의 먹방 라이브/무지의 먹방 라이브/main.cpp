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

int solution(vector<int> food_times,long long k)
{
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
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //long long k = 1833;
    //vector<int> food_times = {946, 314, 757, 322, 559, 647, 983, 482, 145};
    
    long long k = 15;
    vector<int> food_times = {8,6,4};
    
    cout << solution(food_times,k) << '\n';
    return 0;
}
