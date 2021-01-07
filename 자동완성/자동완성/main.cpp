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
    
    sort(words.begin(),words.end(),comp);
    
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
