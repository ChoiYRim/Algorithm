#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    map<string,bool> m;
    vector<int> answer;
    vector<int> order(n+1,0);
    string prev = "";
    
    for(int i = 0; i < words.size(); i++)
    {
        map<string,bool>::iterator it = m.find(words[i]);
        if(it != m.end() || (i > 0 && prev[prev.length()-1] != words[i][0]))
        {
            answer.push_back((i%n)+1);
            answer.push_back(order[i%n]+1);
            return answer;
        }
        m.insert({words[i],true});
        order[i%n]++;
        prev = words[i];
    }
    
    return {0,0};
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 2;
    vector<string> words = {"hello","one","even","never","now","world","draw"};
    vector<int> answer = solution(n,words);
    
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';
    return 0;
}
