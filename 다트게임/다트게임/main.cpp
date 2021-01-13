#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define ISNUM(x) ('0' <= x && x <= '9')
#define ISSTAR(x) (x == '*')
#define ISHASH(x) (x == '#')

using namespace std;

int solution(string dartResult)
{
    int answer = 0,len,idx = 0;
    string dart = dartResult;
    vector<int> v;
    
    len = (int)dart.length();
    for(int i = 0; i < len; i++)
    {
        if(ISNUM(dart[i]))
        {
            string temp = "";

            if(dart[i] == '1' && i+1 < len && dart[i+1] == '0') // 10
            {
                temp += dart[i];
                temp += dart[i+1];
                i++;
                v.push_back(stoi(temp));
                idx++;
            }
            else
            {
                temp += dart[i];
                v.push_back(stoi(temp));
                idx++;
            }
        }
        else if(ISSTAR(dart[i]))
        {
            if(idx <= 1)
                v[idx-1] *= 2;
            else
            {
                v[idx-1] *= 2;
                v[idx-2] *= 2;
            }
        }
        else if(ISHASH(dart[i]))
        {
            v[idx-1] *= (-1);
        }
        else
        {
            int save = v[idx-1];
            
            if(dart[i] == 'D')
            {
                v[idx-1] *= save;
            }
            else if(dart[i] == 'T')
            {
                v[idx-1] *= save*save;
            }
        }
    }
    
    for(int i = 0; i < idx; i++)
        answer += v[i];
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s = "1D2S#10S";
    
    //cin >> s;
    cout << solution(s) << '\n';
    return 0;
}
