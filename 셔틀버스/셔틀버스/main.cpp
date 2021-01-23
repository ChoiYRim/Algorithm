#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const string &s1,const string &s2)
{
    string h1,h2,m1,m2;
    h1 = h2 = m1 = m2 = "";
    
    h1 += s1[0]; h1 += s1[1];
    m1 += s1[3]; m1 += s1[4];
    
    h2 += s2[0]; h2 += s2[1];
    m2 += s2[3]; m2 += s2[4];
    
    if(h1 == h2)
        return m1 < m2;
    return h1 < h2;
}

string solution(int n,int t,int m,vector<string> timetable)
{
    string answer = "";
    string sh = "09",sm = "00"; // standard hour , standard minute
    string lh = "",lm = ""; // limit hour , limit minute
    int cnt; // passenger count
    
    sort(timetable.begin(),timetable.end(),comp);
    
    for(int i = 0; i < n; i++)
    {
        int th = stoi(sh);
        int tm = stoi(sm);
        vector<string>::iterator it;
        
        tm += t;
        if(tm >= 60)
        {
            if(th == 23)
                th = 0;
            else
                th++;
            tm -= 60;
        }
        lh = to_string(th);
        lm = to_string(tm);
        cnt = 0;
        
        for(it = timetable.begin(); it != timetable.end(); it++)
        {
            string hour = "",minute = "";
            hour = (it[0]+it[1]);
            minute = (it[3]+it[4]);
            
            if(hour < lh)
            {
                cnt++;
            }
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 1,t = 1,m = 5;
    vector<string> timetable = {"08:03","08:02","08:01","08:00"};
    
    cout << solution(n,t,m,timetable) << '\n';
    return 0;
}
