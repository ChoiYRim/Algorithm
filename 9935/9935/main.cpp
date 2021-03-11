#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string input = "";
string bomb = "";

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    std::string::size_type s;
    
    cin >> input;
    cin >> bomb;
    while((s = input.find(bomb)) != std::string::npos)
    {
        // start : 찾은 폭발 문자열의 시작 인덱스
        // end   : 폭발 문자열이 아닌 문자열의 시작 인덱스
        int start = (int)s;
        int end = start+(int)bomb.length();
        
        for(; end < input.length(); end++)
        {
            input[start] = input[end];
            start++;
        }
        
        input.erase(input.length()-bomb.length(),input.length());
    }
    
    if(input.length() > 0)
        cout << input << '\n';
    else
        cout << "FRULA" << '\n';
    return 0;
}
