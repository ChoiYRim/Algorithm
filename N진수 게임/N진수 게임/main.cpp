#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N,T,M,P; // n진법 , 미리 구할 숫자의 개수 t, 게임에 참가하는 인원 m, 나의 순서 p
vector<string> numbers;
map<int,string> conv;

string convert_antilogarithm(int n,int num)
{
    int remainder;
    string result = "";

    if(num == 0)
        result = "0";
    while(num > 0)
    {
        remainder = num % n;
        if(n > 10)
        {
            if(remainder > 9)
            {
                map<int,string>::iterator iter = conv.find(remainder);
                
                result += iter->second;
                num /= n;
                continue;
            }
        }
        result += to_string(remainder);
        num /= n;
    }
    
    reverse(result.begin(),result.end());
    return result;
}

string solution(int n,int t,int m,int p)
{
    int cnt = 0,idx;
    string answer = "";
    
    conv.insert({10,"A"});
    conv.insert({11,"B"});
    conv.insert({12,"C"});
    conv.insert({13,"D"});
    conv.insert({14,"E"});
    conv.insert({15,"F"});
    
    for(int i = 0; i < 30000; i++) // 10진수 숫자를 n진수로 변환해 그냥 나열
    {
        int j,len;
        string temp = convert_antilogarithm(n, i);
        
        j = 0;
        len = (int)temp.length();
        while(j < len)
        {
            numbers.push_back(temp.substr(j,1));
            j++;
        }
    }
    
    idx = p-1;
    
    for(int i = 0; cnt < t && i < numbers.size(); i++)
    {
        if(i == idx)
        {
            answer += numbers[idx];
            idx += m;
            cnt++;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> T >> M >> P;
    string result = solution(N,T,M,P);
        
    cout << result << '\n';
    return 0;
}
