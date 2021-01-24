#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const string &s1,const string &s2)
{
    string h1 = "",h2 = "";
    string m1 = "",m2 = "";
    int hour1,hour2,min1,min2;
    
    h1 += s1[0]; h1 += s1[1];
    m1 += s1[3]; m1 += s1[4];
    hour1 = stoi(h1);
    min1 = stoi(m1);
    
    h2 += s2[0]; h2 += s2[1];
    m2 += s2[3]; m2 += s2[4];
    hour2 = stoi(h2);
    min2 = stoi(m2);
    
    if(hour1 == hour2)
        return min1 < min2;
    return hour1 < hour2;
}

string solution(int n,int t,int m,vector<string> timetable)
{
    string answer = "";
    int hour = 9,minute = 0,idx; // 기준시
    queue<string> q;
    vector<string> v[10];
    
    sort(timetable.begin(),timetable.end(),comp);
    for(int i = 0; i < (int)timetable.size(); i++)
        q.push(timetable[i]);
    
    for(int shuttle = 0; shuttle < n; shuttle++)
    {
        idx = 0;
        
        while(!q.empty() && idx < m)
        {
            string time = q.front();
            string tempH = "",tempM = "";
            int curH,curM;
            
            tempH += time[0]; tempH += time[1];
            tempM += time[3]; tempM += time[4];
            curH = stoi(tempH);
            curM = stoi(tempM);
            
            if(hour < curH)
                break;
            else
            {
                if(hour == curH)
                {
                    if(minute >= curM)
                    {
                        idx++;
                        v[shuttle].push_back(time);
                        q.pop();
                    }
                    else
                        break;
                }
                else
                {
                    idx++;
                    v[shuttle].push_back(time);
                    q.pop();
                }
            }
        }
        minute += t;
        if(minute >= 60)
        {
            minute -= 60;
            hour++;
            if(hour >= 24)
                hour -= 24;
        }
    }
    if(v[n-1].size() < m) // m명의 승객이 꽉 차지않은 상태로 끝났음
    {
        minute-=t;
        if(minute < 0)
        {
            minute += 60;
            hour--;
            if(hour < 0)
                hour += 24;
        }
    }
    else // m명의 승객이 꽉 찼다 -> 최종시간 - 1
    {
        string time = v[n-1][m-1];
        string tempH = "",tempM = "";
        
        tempH += time[0]; tempH += time[1];
        tempM += time[3]; tempM += time[4];
        hour = stoi(tempH);
        minute = stoi(tempM);
        
        minute--;
        if(minute < 0)
        {
            minute += 60;
            hour--;
            if(hour < 0)
                hour += 24;
        }
    }
    
    if(hour < 10)
        answer += "0";
    answer += to_string(hour);
    answer += ":";
    if(minute < 10)
        answer += "0";
    answer += to_string(minute);
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 10,t = 60,m = 45;
    vector<string> timetable = {"23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};
    
    cout << solution(n,t,m,timetable) << '\n';
    return 0;
}
