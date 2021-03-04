#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string input = "";

bool checkString(string str)
{
    int len = (int)str.length(),i = 0;

    while(i < len)
    {
        if(str[i] == '0') // 01
        {
            if(i+1 < len && str[i+1] == '1')
                i += 2;
            else
                return false;
        }
        else // 100~1~
        {
            if(i+3 >= len) // 최소 1001은 만족시켜야함
                return false;
            if(str[i+1] != '0' || str[i+2] != '0')
                return false;
            i++;
            while(str[i] == '0')
                i++;
            if(i >= len)
                return false;
            i++;
            while(i < len && str[i] == '1')
            {
                if(i+2 < len && str[i+1] == '0' && str[i+2] == '0')
                    break;
                i++;
            }
        }
    }

    return true;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> input;
    if((int)input.length() > 150)
    {
        cout << "NOISE" << '\n';
        return 0;
    }

    if(checkString(input))
        cout << "SUBMARINE" << '\n';
    else
        cout << "NOISE" << '\n';
    return 0;
}

//#include <iostream>
//#include <regex>
//#include <string>
//
//using namespace std;
//
//int main(int argc,char *argv[])
//{
//    string input;
//    cin >> input;
//    cout << (std::regex_match(input,regex("(100+1+|01)+")) ? "SUMARINE" : "NOISE" ) << '\n';
//    return 0;
//}
