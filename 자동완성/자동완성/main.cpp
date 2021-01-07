#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N,L;

bool comp(const string& s1,const string& s2)
{
    if(s1 < s2)
        return true;
    return false;
}

int solution(vector<string> words)
{
    int answer = 0;
    int idx = 0,len = (int)words.size();
    
    while(idx < len)
    {
        string sub = "";
        string word = words[idx];
        
        for(int i = 0; i < word.length(); i++)
        {
            vector<string> search;
            sub += word[i];
            
            for(string& str : words)
            {
                if(str != word && str.find(sub) != string::npos)
                    search.push_back(str);
                if(search.size() > 1 && sub.length() != word.length()) // 최소가 아닌 경우
                    break;
            }
            
            // 두 가지 경우 존재
            // 1. word와 word 전체를 부분 문자열로 갖는 다른 문자열
            // 2. word의 부분 문자열을 갖는 다른 문자열이 없는 경우
            if(search.size() <= 0)
            {
                answer += sub.length();
                break;
            }
            else // search.size() > 0
            {
                if(sub.length() == word.length())
                {
                    answer += word.length();
                    break;
                }
            }
        }
        idx++;
    }
    
    return answer;
}

int main(int argc, const char * argv[])
{
    vector<string> words;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> L;
    for(int i = 0; i < N; i++)
    {
        string temp;
        
        cin >> temp;
        words.push_back(temp);
    }
    
    cout << solution(words) << '\n';
    return 0;
}
