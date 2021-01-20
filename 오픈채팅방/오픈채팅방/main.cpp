#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void split(map<string,string> &m,vector<pair<string,string>> &v,string str)
{
    int idx = 0;
    int len = (int)str.length();
    string status = "";
    string id = "",alias = "";
    
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
        {
            idx = i+1;
            break;
        }
        status += str[i];
    }
    for(int i = idx; i < len && str[i] != ' '; i++)
    {
        id += str[i];
        idx = i;
    }
    
    if(status == "Enter")
    {
        for(int i = idx+2; i < len; i++)
            alias += str[i];
    
        map<string,string>::iterator it = m.find(id);
        if(it == m.end())
        {
            m.insert({id,alias});
        }
        else
        {
            it->second = alias;
        }
        
        v.push_back({"Enter",id});
    }
    else if(status == "Change")
    {
        map<string,string>::iterator it = m.find(id);
        for(int i = idx+2; i < len; i++)
            alias += str[i];
        it->second = alias;
        v.push_back({"Change",""});
    }
    else // Leave
    {
        v.push_back({"Leave",id});
    }
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    map<string,string> m; // ID , Alias
    vector<pair<string,string>> v;
    
    for(int i = 0; i < (int)record.size(); i++)
        split(m,v,record[i]);
    
    for(int i = 0; i < (int)v.size(); i++)
    {
        if(v[i].first == "Change")
            continue;
        else
        {
            string str = "";
            map<string,string>::iterator it = m.find(v[i].second);
            
            if(it != m.end())
            {
                if(v[i].first == "Enter")
                {
                    str += it->second;
                    str += "님이 들어왔습니다.";
                }
                else
                {
                    str += it->second;
                    str += "님이 나갔습니다.";
                }
                answer.push_back(str);
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
    
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> result = solution(record);
    
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i] << " ";
    cout << '\n';
    return 0;
}
