#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

#define IS_SPECIAL(x) (x == 'A' || x == 'C' || x == 'D' || x == 'F' || x == 'G')

using namespace std;

static inline void ltrim(string& s)
{
    s.erase(s.begin(),std::find_if(s.begin(), s.end(), [](int ch)
    {
        return !std::isspace(ch);
    }));
}

vector<string> split(string input,char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss,temp,delimiter))
    {
        ltrim(temp);
        answer.push_back(temp);
    }
    
    return answer;
}

string convert_score(string score)
{
    string ret = "";
    
    for(int i = 0; i < score.length(); i++)
    {
        if(IS_SPECIAL(score[i]))
        {
            if(i+1 < score.length() && score[i+1] == '#')
            {
                ret += (score[i] + 7);
                i++;
            }
            else if(i+1 >= score.length() || score[i+1] != '#')
                ret += score[i];
        }
        else
            ret += score[i];
        
    }
    
    return ret;
}

bool comp(const pair<string,pair<int,int>>& c1,const pair<string,pair<int,int>>& c2)
{
    if(c1.second.first > c2.second.first)
        return true;
    else if(c1.second.first == c2.second.first)
    {
        if(c1.second.second < c2.second.second)
            return true;
        return false;
    }
    return false;
}

string solution(string m,vector<string> musicinfos)
{
    string answer = "";
    string st,et,title,score;
    vector<pair<string,pair<int,int>>> result; // < 제목 , 실행시간 , 악보 순서 >
    int hour = 0,minute = 0,mlen;
    
    m = convert_score(m);
    mlen = (int)m.length();
    
    for(int i = 0; i < musicinfos.size(); i++)
    {
        string music = musicinfos[i];
        
        vector<string> musicinf = split(music,',');
        vector<string> vst,vet;
                
        st = musicinf[0];
        et = musicinf[1];
        title = musicinf[2];
        score = musicinf[3];
        
        vst = split(st,':'); // vst : 12 , 00
        vet = split(et,':'); // vet : 12 , 14
        
        if(vet[0] != "00")
        {
            if(vet[0] == vst[0])
            {
                hour = 0;
                minute = abs(stoi(vst[1])-stoi(vet[1]));
            }
            else
            {
                hour = stoi(vet[0]) - stoi(vst[0]);
                if(stoi(vst[1]) > stoi(vet[1]))
                {
                    hour--; minute = 60 + stoi(vet[1]);
                    minute -= stoi(vst[1]);
                }
            }
        }
        else // vet[0] == "00"
        {
            if(vst[0] != "00")
            {
                hour = 24 - stoi(vst[0]);
                if(stoi(vst[1]) > stoi(vet[1]))
                {
                    hour--; minute = 60 + stoi(vet[1]);
                    minute -= stoi(vst[1]);
                }
            }
            else // vst[0] == "00"
            {
                hour = 0;
                minute = abs(stoi(vst[1])-stoi(vet[1]));
            }
        }
        
        score = convert_score(score);
        int time = hour * 60 + minute;
        int len = (int)score.length();
        
        if(time >= len) // 악보 반복 재생 -> 악보 이어붙이기
        {
            string temp = "";
            
            for(int j = 0; j < time-len; j++)
            {
                int idx = j % len;
                temp += score[idx];
            }
            score += temp;
            len = (int)score.length();
            
            if(score.find(m) != string::npos)
            {
                result.push_back({title,{time,i}});
            }
            else
            {
                if(mlen > len && len > 0)
                {
                    int idx = 0,diff = mlen - len;
                    for(int j = 0; j < diff; j++)
                    {
                        score += score[idx % len];
                        idx++;
                    }
                    if(score.find(m) != string::npos)
                    {
                        result.push_back({title,{time,i}});
                    }
                }
            }
        }
        else // 시간만큼만 재생
        {
            score = score.substr(0,time);
            len = (int)score.length();
            
            if(score.find(m) != string::npos)
            {
                result.push_back({title,{time,i}});
            }
            else
            {
                if(mlen > len && len > 0)
                {
                    int idx = 0,diff = mlen - len;
                    for(int j = 0; j < diff; j++)
                    {
                        score += score[idx % len];
                        idx++;
                    }
                    if(score.find(m) != string::npos)
                    {
                        result.push_back({title,{time,i}});
                    }
                }
            }
        }
    }
    
    if(result.size() <= 0)
        return "(None)";
    else if(result.size() == 1)
        return result[0].first;
    sort(result.begin(),result.end(),comp);
    return result[0].first;
}

int main(int argc, const char * argv[])
{
    string m,temp = "";
    vector<string> musicinfos;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    m = "ABCDEFG";
    musicinfos = {"12:00,12:14,HELLO,CDEFGAB","13:00,13:05,WORLD,ABCDEF"};
    
    cout << solution(m,musicinfos) << '\n';
    return 0;
}
