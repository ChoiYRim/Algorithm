#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,result = 0;
vector<string> words;
map<char,int> freq;
vector<pair<char,int>> alpha;

int num[10][8] = {0,};

bool comp(const pair<char,int>& p1,const pair<char,int>& p2)
{
    return p1.second > p2.second;
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<char,int>::iterator it;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        
        words.push_back(str);
        
        int idx = 1;
        for(int j = (int)str.length()-1; j >= 0; j--)
        {
            it = freq.find(str[j]);
            if(it != freq.end())
            {
                it->second += idx;
            }
            else
            {
                freq.insert({str[j],idx});
            }
            idx *= 10;
        }
    }
    
    for(int i = 'A'; i <= 'Z'; i++)
    {
        it = freq.find(i);
        if(it != freq.end())
        {
            alpha.push_back({i,it->second});
        }
    }
    
    int cnt = 9;
    stable_sort(alpha.begin(),alpha.end(),comp);
    for(int i = 0; i < (int)alpha.size(); i++)
    {
        alpha[i].second = cnt--;
    }
    
    for(int i = 0; i < N; i++)
    {
        string str = words[i];
        int sum = 0,idx = 1;
        
        for(int j = (int)str.length()-1; j >= 0; j--)
        {
            for(int k = 0; k < (int)alpha.size(); k++)
            {
                if(str[j] == alpha[k].first)
                {
                    sum += (idx * alpha[k].second);
                    break;
                }
            }
            idx *= 10;
        }
        result += sum;
    }
    
    cout << result << '\n';
    return 0;
}
