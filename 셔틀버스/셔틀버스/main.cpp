// 수정중

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const string &s1,const string &s2)
{
    int hour1,hour2,minute1,minute2;
    string h1,h2,m1,m2;
    h1 = h2 = m1 = m2 = "";
    
    h1 += s1[0]; h1 += s1[1];
    m1 += s1[3]; m1 += s1[4];
    hour1 = stoi(h1);
    minute1 = stoi(m1);
    
    h2 += s2[0]; h2 += s2[1];
    m2 += s2[3]; m2 += s2[4];
    hour2 = stoi(h2);
    minute2 = stoi(m2);
    
    if(hour1 == hour2)
        return minute1 < minute2;
    return hour1 < hour2;
}

string solution(int n,int t,int m,vector<string> timetable)
{
    string answer = "";
    string sh = "09",sm = "00"; // standard hour , standard minute
    int cnt = 0;
    vector<string> result;
    
    sort(timetable.begin(),timetable.end(),comp);
    
    for(int i = 0; i < (int)timetable.size(); i++)
    {
        int j,shi = stoi(sh);
        int smi = stoi(sm);
        cnt = 0;
        result.clear();
        
        for(j = i; j < (int)timetable.size(); j++)
        {
            int hi,mi;
            string h = "",minute = "";
            
            h += timetable[j][0];
            h += timetable[j][1];
            minute += timetable[j][3];
            minute += timetable[j][4];
            
            hi = stoi(h); mi = stoi(minute);
            if(cnt < m)
            {
                if(hi < shi)
                {
                    cnt++;
                    result.push_back(timetable[j]);
                }
                else if(hi == shi)
                {
                    if(mi <= smi)
                    {
                        cnt++;
                        result.push_back(timetable[j]);
                    }
                    else
                    {
                        i = j-1;
                        break;
                    }
                }
                else
                {
                    i = j-1;
                    break;
                }
            }
            else
            {
                i = j-1;
                break;
            }
        }
        if(j >= (int)timetable.size())
        {
            break;
        }
                   
        smi += t;
        if(smi >= 60)
        {
            if(shi == 23)
            {
                shi = 0;
                sh = "00";
            }
            else
            {
                shi++;
                sh = to_string(shi);
            }
            smi -= 60;
        }
        else
        {
            sh = to_string(shi);
            sm = to_string(smi);
        }
    }
    
    if(cnt >= m)
    {
        if((int)result.size() > 0)
        {
            int last = (int)result.size()-1;
            sh = ""; sm = "";
            sh += result[last][0]; sh += result[last][1];
            sm += result[last][3]; sm += result[last][4];
            
            int shi = stoi(sh);
            int smi = stoi(sm);
            
            smi--;
            sm = ""; sh = "";

            if(smi < 0)
            {
                smi = 59;
                if(shi == 0)
                    shi = 23;
            }
            if(smi < 10)
            {
                sm += "0";
                if(shi < 10)
                {
                    sh += "0";
                }
            }
            sm += to_string(smi);
            sh += to_string(shi);
        }
    }
    answer += sh;
    answer += ":";
    answer += sm;
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 2,t = 10,m = 2;
    vector<string> timetable = {"09:10", "09:09", "08:00"};
    
    cout << solution(n,t,m,timetable) << '\n';
    return 0;
}
