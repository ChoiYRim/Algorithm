#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int cacheSize,vector<string> cities)
{
    int time = 0;
    int answer = 0,len;
    map<string,int> m; // [Key, 사용된 시간]
    
    len = (int)cities.size();
    for(int i = 0; i < len; i++)
    {
        string search = cities[i];
        std::transform(search.begin(), search.end(), search.begin(), ::tolower);
        map<string,int>::iterator it = m.find(search),del;
        
        if(it == m.end()) // does not exist : miss
        {
            if((int)m.size() >= cacheSize)
            {
                int min = 0x7fffffff;

                for(it = m.begin(); it != m.end(); it++)
                {
                    if(it->second < min)
                    {
                        min = it->second;
                        del = it;
                    }
                }
                if(cacheSize != 0)
                    m.erase(del);
            }
            if(cacheSize > 0)
                m.insert({search,time});
            answer += 5;
        }
        else // exists : hits
        {
            it->second = time;
            answer += 1;
        }
        time++;
    }
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    
    cout << solution(cacheSize,cities) << '\n';
    return 0;
}
