#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
    string s1,s2;
    int answer = 1111;
    vector<string> result;
        
    for(int i = 1; i <= s.size(); i++) // 길이가 1인 문자열부터 시작
    {
        int same = 0;
        int j = 0,idx = 0;
        
        while(j < s.size() && idx < s.size())
        {
            s1 = s.substr(j,i);
            s2 = s.substr(idx,i);
            
            if(s1 == s2)
            {
                same++;
                idx += i;
            }
            else
            {
                j += i;
                if(same > 0)
                {
                    if(same > 1)
                    {
                        string temp = to_string(same);
                        result.push_back(temp);
                    }
                    result.push_back(s1);
                    same = 0;
                }
            }
        }
        
        if(same > 0)
        {
            if(same > 1)
            {
                string temp = to_string(same);
                result.push_back(temp);
            }
            result.push_back(s1);
            same = 0;
        }
      
        if(result.size() > 0)
        {
            int sum = 0;
            for(int k = 0; k < result.size(); k++)
            {
                sum += result[k].size();
            }
            
            if(sum < answer)
                answer = sum;
        }
        result.clear();
    }
    
    return answer;
}

int main(void)
{
    string s = "xababcdcdababcdcd";

    cout << solution(s) << endl;

    return 0;
}
