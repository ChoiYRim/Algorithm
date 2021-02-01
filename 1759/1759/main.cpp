#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define ISVOWEL(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')

using namespace std;

int L,C;
vector<char> alpha;
set<string> result;
bool visit[15] = {0,};

inline bool comp(const char& c1,const char& c2) { return c1 < c2; }

void DFS(int depth,string str)
{
    if(depth == L && str.length() == L)
    {
        int vowel = 0,consonant = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(ISVOWEL(str[i]))
                vowel++;
            else
                consonant++;
        }
        
        if(vowel < 1 || consonant < 2)
            return;
        
        result.insert(str);
        return;
    }
    
    int len = (int)str.length();
    
    for(int i = depth; i < alpha.size(); i++)
    {
        if(i+L-len > C)
            continue;
        
        if(!visit[i] && str[len-1] < alpha[i])
        {
            visit[i] = true;
            str += alpha[i];
            DFS(depth+1,str);
            str.pop_back();
            visit[i] = false;
        }
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int vowel = 0,consonant = 0;
    
    cin >> L >> C;
    for(int i = 0; i < C; i++)
    {
        char ch;
        cin >> ch;
        if(ISVOWEL(ch))
            vowel++;
        else
            consonant++;
        alpha.push_back(ch);
    }
    
    sort(alpha.begin(),alpha.end(),comp); // 사전 순 정렬
    
    if(L < 3 || vowel < 1 || consonant < 2) // 실행 불가
        return 0;
    
    DFS(0,"");
    
    for(set<string>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it << '\n';
    }
    return 0;
}
