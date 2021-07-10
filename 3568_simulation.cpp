#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string input = "";
vector<string> values;

inline bool is_alpha(char c) { return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')); }

inline bool is_special(char c) { return (c == '[' || c == ']' || c == '&' || c == '*'); }

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ptr = 0,len;
    string common_type = "";
    
    getline(cin,input);
    //input.erase(remove(input.begin(),input.end(),' '),input.end());
    
    len = (int)input.length();
    while(ptr < len && is_alpha(input[ptr]))
    {
        if(input[ptr] == ' ')
        {
            ptr++;
            continue;
        }
        common_type += input[ptr];
        ptr++;
    }
    while(ptr < len && is_special(input[ptr]))
    {
        if(input[ptr] == ' ')
        {
            ptr++;
            continue;
        }
        common_type += input[ptr];
        ptr++;
    }
    
    while(ptr < len && input[ptr] != ';')
    {
        string result = "",value = "",semi_type = "";
        
        while(ptr < len && input[ptr] != ',' && input[ptr] != ';')
        {
            if(is_special(input[ptr]))
                semi_type += input[ptr];
            else if(is_alpha(input[ptr]))
                value += input[ptr];
            ptr++;
        }
        
        reverse(semi_type.begin(),semi_type.end());
        for(int i = 0; i < (int)semi_type.length(); i++)
        {
            if(semi_type[i] == '[')
                semi_type[i] = ']';
            else if(semi_type[i] == ']')
                semi_type[i] = '[';
        }
        
        result = common_type + semi_type + " " + value + ";";
        values.push_back(result);
        ptr++;
    }
    
    for(int i = 0; i < (int)values.size(); i++)
        cout << values[i] << '\n';
    return 0;
}
