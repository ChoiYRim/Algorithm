#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
string str = "";
vector<string> v;
int dp[100][100] = {0,};

void DFS(int curIdx)
{
    if(curIdx >= (int)str.length())
    {
        cout << 1 << '\n';
        exit(0);
    }
    
    for(int i = 0; i < N; i++)
    {
        if(str[curIdx] == v[i][0])
        {
            string sub = str.substr(curIdx,v[i].length());
            if(sub == v[i] && !dp[curIdx][i])
            {
                dp[curIdx][i] = 1;
                DFS(curIdx+(int)v[i].length());
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    cin >> str;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string temp = "";
        cin >> temp;
        v.push_back(temp);
    }
    
    DFS(0);
    cout << 0 << '\n';
    return 0;
}
