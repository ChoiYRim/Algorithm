#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define ISIT(x) (x == 'a' || x == 'c' || x == 't' || x == 'i' || x == 'n')

using namespace std;

int N,K;
int answer = 0;
bool alphabet[27];
vector<string> words;

inline bool comp(const vector<char> &s1,const vector<char> &s2)
{
    return s1.size() > s2.size();
}

string splitMiddle(string str)
{
    string result = "";
    int len = (int)str.length();
    
    for(int i = 4; i < len-4; i++)
        result += str[i];
    
    return result;
}

void DFS(int depth,int cur)
{
    if(depth == K-5)
    {
        int cnt = 0;
        
        for(int i = 0; i < (int)words.size(); i++)
        {
            bool check = true;

            for(int j = 0; j < (int)words[i].length(); j++)
            {
                if(!alphabet[words[i][j]-'a'])
                {
                    check = false;
                    break;
                }
            }
            if(check)
                cnt++;
        }
        
        answer = max(answer,cnt);
        return;
    }
    
    for(int a = cur; a < 26; a++)
    {
        if(!alphabet[a])
        {
            alphabet[a] = true;
            DFS(depth+1,a);
            alphabet[a] = false;
        }
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i < 26; i++)
    {
        if(ISIT(i+'a'))
            alphabet[i] = true;
        else
            alphabet[i] = false;
    }
    
    vector<string> v;
    
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    
    // a , c , t , i , n 공통 5개 필수
    if(K < 5)
    {
        cout << 0 << '\n';
        return 0;
    }
    else if(K >= 26)
    {
        cout << N << '\n';
        return 0;
    }
    
    for(int i = 0; i < (int)v.size(); i++)
        words.push_back(splitMiddle(v[i]));
    
    DFS(0,0);
    cout << answer << '\n';
    return 0;
}
