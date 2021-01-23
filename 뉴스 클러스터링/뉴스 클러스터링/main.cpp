#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define ISALPHA(x) (('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z'))

using namespace std;

inline bool comp(const string &s1,const string &s2) { return s1 < s2; }

string getNormalString(string str)
{
    string result = "";
    int len = (int)str.length();
    
    for(int i = 0; i < len; i++)
    {
        if(ISALPHA(str[i]))
        {
            if('a' <= str[i] && str[i] <= 'z')
                result += str[i];
            else
                result += tolower(str[i]);
        }
        else
            result += str[i];
    }
    
    return result;
}

vector<pair<string,int>> getSet(string str)
{
    vector<string> v;
    vector<pair<string,int>> result;
    vector<string>::iterator it,start;
    int len = (int)str.length();
    
    for(int i = 0; i < len-1; i++)
    {
        string temp = "";
        
        if(ISALPHA(str[i]) && ISALPHA(str[i+1]))
        {
            temp += str[i];
            temp += str[i+1];
            v.push_back(temp);
        }
    }
    
    sort(v.begin(),v.end(),comp);
    for(it = v.begin();it != v.end(); )
    {
        int cnt = 1;
        string temp = *it;
        for(start = it+1; start != v.end() && *start == temp; start++)
            cnt++;
        result.push_back({temp,cnt});
        if(start == v.end())
            break;
        it = start;
    }
    
    return result;
}

int solution(string str1,string str2)
{
    double answer = 0,r1 = 0,r2 = 0;
    string t1 = getNormalString(str1);
    string t2 = getNormalString(str2);
    vector<pair<string,int>> setA,setB;
    vector<pair<string,int>> a,b; // 교집합 합집합
    
    setA = getSet(t1);
    setB = getSet(t2);
    
    for(int i = 0; i < (int)setA.size(); i++)
    {
        string astr = setA[i].first;
        int acnt = setA[i].second;
        vector<pair<string,int>>::iterator it = setB.end();
        
        for(int j = 0; j < (int)setB.size(); j++)
        {
            if(astr == setB[j].first)
            {
                it = (setB.begin()+j);
                break;
            }
        }
        if(it != setB.end())
        {
            int newcnt = min(acnt,it->second);
            a.push_back({astr,newcnt});
            newcnt = max(acnt,it->second);
            b.push_back({astr,newcnt});
        }
        else
            b.push_back({astr,acnt});
    }
    
    for(int i = 0; i < (int)setB.size(); i++)
    {
        string bstr = setB[i].first;
        int bcnt = setB[i].second;
        vector<pair<string,int>>::iterator it = setA.end();
        
        for(int j = 0; j < (int)setA.size(); j++)
        {
            if(bstr == setA[j].first)
            {
                it = (setA.begin()+j);
                break;
            }
        }
        if(it == setA.end())
        {
            b.push_back({bstr,bcnt});
        }
    }
    
    for(int i = 0; i < (int)a.size(); i++)
        r1 += a[i].second;
    for(int i = 0; i < (int)b.size(); i++)
        r2 += b[i].second;
    
    if(r2 == 0)
        answer = 65536;
    else
    {
        answer = r1 / r2;
        answer *= 65536;
    }
    return (int)answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";
    
    cout << solution(str1,str2) << '\n';
    return 0;
}
