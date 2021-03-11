#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define IS_NUM(x) ('0' <= x && x <= '9')

using namespace std;

int TC;
vector<string> result;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> TC;
    while(TC--)
    {
        int N;
        string cmd,arr,temp = "";
        vector<int> v;
        
        cin >> cmd;
        cin >> N;
        cin >> arr;
        for(int i = 0; i < (int)arr.length(); i++)
        {
            if(IS_NUM(arr[i]))
                temp += arr[i];
            else
            {
                if(temp == "")
                    continue;
                else
                {
                    int num = stoi(temp);
                    v.push_back(num);
                    temp.clear();
                }
            }
        }
        
        int R = 0;
        bool error = false;
        vector<int> rDelete;
        rDelete.push_back(0);
        
        for(int i = 0; i < (int)cmd.length(); i++)
        {
            if(cmd[i] == 'R')
            {
                R++;
                rDelete.push_back(0);
            }
            else
                rDelete[R]++;
        }
        
        for(int i = 0; i < rDelete.size(); i++)
        {
            int D = rDelete[i];
            if(!D)
                continue;
            if(i % 2)
            {
                if(v.size() >= D)
                    v.erase(v.end()-D,v.end());
                else
                {
                    result.push_back("error");
                    error = true;
                    break;
                }
            }
            else
            {
                if(v.size() >= D)
                    v.erase(v.begin(),v.begin()+D);
                else
                {
                    result.push_back("error");
                    error = true;
                    break;
                }
            }
        }
        if(!error)
        {
            if(v.size() == 0)
            {
                result.push_back("[]");
                continue;
            }
            
            if(R % 2)
                reverse(v.begin(),v.end());
            string r = "[";
            for(int i = 0; i < v.size(); i++)
            {
                r += to_string(v[i]);
                if(i == v.size()-1)
                    r += "]";
                else
                    r += ",";
            }
            result.push_back(r);
        }
    }
    
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}
