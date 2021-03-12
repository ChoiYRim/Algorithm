#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string input = "";
string bomb = "";
string answer = "";

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    cin >> input;
    cin >> bomb;
    for(int i = 0; i < input.length(); i++)
    {
        answer += input[i];

        if(input[i] == bomb[bomb.length()-1])
        {
            int len = (int)answer.length();
            
            if(answer.length() >= bomb.length() && answer.substr(len-bomb.length(),len) == bomb)
            {
                for(int j = 0; j < bomb.length(); j++)
                    answer.pop_back();
            }
        }
    }
    
    if(answer.length() != 0)
        cout << answer << '\n';
    else
        cout << "FRULA" << '\n';
    return 0;
}
