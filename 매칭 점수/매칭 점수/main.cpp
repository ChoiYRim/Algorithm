#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#define ISALPHA(x) (('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z'))

using namespace std;

struct WebPage
{
    string url;
    vector<string> links;
    
    double a; // 이름 짓기 귀찮음
    int ns; // normal score
    int olink; // outside links
    double ls; // link score
    double ms; // matching score
    int index; // page index
};

map<string,int> m;

bool comp(const WebPage& s1,const WebPage& s2)
{
    if(s1.ms == s2.ms)
        return s1.index < s2.index;
    return s1.ms > s2.ms;
}

void split(vector<WebPage> &v,string word,string page,int index)
{
    int idx,pos = 0;
    int ns,olink,ls,ms;
    WebPage wp;
    string tempPage = page,tempWord = word;
    
    std::transform(tempPage.begin(),tempPage.end(),tempPage.begin(),::tolower);
    std::transform(tempWord.begin(),tempWord.end(),tempWord.begin(),::tolower);
    
    ns = olink = ls = ms = 0;
    while((idx = (int)tempPage.find(tempWord,pos)) != string::npos)
    {
        int temp = idx + (int)tempWord.length();
        if(temp < (int)page.length() && !ISALPHA(page[temp]))
        {
            if(idx-1 >= 0 && !ISALPHA(page[idx-1]))
                ns++;
        }
        pos = temp;
    }
    wp.ns = ns;
    
    pos = 0;
    while((idx = (int)page.find("<meta property=\"og:url\"",pos)) != string::npos)
    {
        int cnt = 0;
        string temp = "";
        
        for(int i = idx; i < (int)page.length() && cnt < 3; i++)
        {
            if(page[i] == '"')
                cnt++;
            idx++;
        }
        for(int i = idx; i < (int)page.length() && (page[i] != '>' && page[i] != '"'); i++)
            temp += page[i];
        wp.url = temp;
        break;
    }
    
    pos = 0;
    while((idx = (int)page.find("<a href",pos)) != string::npos)
    {
        string temp = "";
        for(int i = idx; i < (int)page.length() && (page[i] != '>' && page[i] != '"'); i++)
            idx++;
        for(int i = idx+1; i < (int)page.length() && (page[i] != '>' && page[i] != '"'); i++)
        {
            temp += page[i];
            idx = i;
        }
        if(wp.url != temp)
        {
            wp.links.push_back(temp);
            olink++;
        }
        pos = idx;
    }
    wp.ls = 0;
    wp.olink = olink;
    wp.ms = 0;
    wp.index = index;
    if(wp.links.size() > 0)
        wp.a = ((double)ns / wp.links.size());
    else
        wp.a = 0;
    m.insert(make_pair(wp.url,index));
    v.push_back(wp);
}

int solution(string word,vector<string> pages)
{
    int len = 0,answer = 0;
    vector<WebPage> v;
    
    len = (int)pages.size();
    for(int i = 0; i < len; i++)
        split(v,word,pages[i],i);
    
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < (int)v[i].links.size(); j++)
        {
            std::map<string,int>::iterator iter;
            iter = m.find(v[i].links[j]);
            if(iter != m.end())
            {
                int idx = iter->second;
                v[idx].ls += v[i].a;
            }
        }
    }
    for(int i = 0; i < len; i++)
    {
        v[i].ms = v[i].ls + v[i].ns;
    }
    
    sort(v.begin(),v.end(),comp);
    answer = v[0].index;
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string word = "Muzi";
    vector<string> pages = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"};
    
    cout << solution(word,pages) << '\n';
    return 0;
}
