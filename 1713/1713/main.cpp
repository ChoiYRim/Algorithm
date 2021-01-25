#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,total;
vector<int> student;
map<int,pair<int,int>> m; // 후보들

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    cin >> N;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        int re;
        cin >> re;
        student.push_back(re);
    }
    
    for(int i = 0; i < (int)student.size(); i++)
    {
        int cnt = (int)m.size();
        map<int,pair<int,int>>::iterator it = m.find(student[i]);
        
        for(map<int,pair<int,int>>::iterator iter = m.begin(); iter != m.end(); iter++)
        {
            iter->second.first++; // 시간 증가
        }
        
        if(it == m.end()) // 추천 받은 적 없음
        {
            if(cnt >= N)
            {
                map<int,pair<int,int>>::iterator target = m.begin();

                for(map<int,pair<int,int>>::iterator iter = m.begin(); iter != m.end(); iter++)
                {
                    if(target->second.second > iter->second.second)
                    {
                        target = iter;
                    }
                    else if(target->second.second == iter->second.second)
                    {
                        if(target->second.first < iter->second.first)
                        {
                            target = iter;
                        }
                    }
                }
                m.erase(target);
            }
            m.insert({student[i],{0,1}}); // 학생번호 , [시간 , 추천 수]
        }
        else // 추천 받은 적 있음
        {
            it->second.second++; // 추천 수 증가
        }
    }
    
    priority_queue<int,vector<int>,greater<int>> pq; // Min Heap
    for(map<int,pair<int,int>>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        pq.push(iter->first);
    }
    
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';
    return 0;
}
