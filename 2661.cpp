#include <string>
#include <iostream>

using namespace std;

int N;

bool check(string str)
{
    int len = (int)str.length(),last = len;
    
    for(int i = 1; i < len; i++)
    {
        if(last-i >= 0)
        {
            string s1 = str.substr(last-i,i);
            
            if(last-2*i >= 0)
            {
                string s2 = str.substr(last-2*i,i);
                
                if(s1 == s2)
                    return false;
            }
        }
    }
    
    return true;
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string result = "";
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        bool right = false;
        for(int j = 1; j < 4; j++)
        {
            result += to_string(j);
            if(check(result))
            {
                right = true;
                break;
            }
            result.pop_back();
        }
        while(!right)
        {
            int last = result[result.length()-1]-'0';
            result.pop_back();
            i--;
            
            for(int j = last+1; j < 4; j++)
            {
                result += to_string(j);
                if(check(result))
                {
                    right = true;
                    break;
                }
                result.pop_back();
            }
        }
    }
    
    cout << result << '\n';
    //cout << result.length() << '\n';
    return 0;
}
