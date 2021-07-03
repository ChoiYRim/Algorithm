#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

bool is_palindrome(string str)
{
    int mid = (int)str.length() / 2;
    string s1 = "",s2 = "";
    
    if(str.length() % 2) // odd
    {
        s1 = str.substr(0,mid);
        s2 = str.substr(mid+1,mid);
    }
    else
    {
        s1 = str.substr(0,mid);
        s2 = str.substr(mid,mid);
    }
    
    reverse(s2.begin(),s2.end());
    
    if(s1 == s2)
        return true;
    return false;
}

bool is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int get_palindrome(int n)
{
    string target = "";
    
    for(int i = n; ; i++)
    {
        target = to_string(i);
        if(!is_palindrome(target))
            continue;
        else
        {
            if(is_prime(i))
                break;
        }
    }
    
    return stoi(target);
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    cin >> N;
    if(N == 1)
    {
        cout << 2 << '\n';
        return 0;
    }
    cout << get_palindrome(N) << '\n';
    return 0;
}
