#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string getBinaryString(int num,int n)
{
    string result = "";
    
    while(num > 0)
    {
        int remainder = num % 2;
        result += to_string(remainder);
        num /= 2;
    }
    
    if((int)result.length() <= n)
    {
        while((int)result.length() < n)
            result += '0';
    }
    reverse(result.begin(),result.end());
    return result;
}

string getResult(string s1,string s2)
{
    string result = "";
    
    for(int i = 0; i < (int)s1.length(); i++)
    {
        if(s1[i] == '0' && s1[i] == s2[i])
            result += ' ';
        else
            result += '#';
    }
    
    return result;
}

vector<string> solution(int n,vector<int> arr1,vector<int> arr2)
{
    vector<string> answer;
    string s1,s2;
    
    for(int i = 0; i < (int)arr1.size(); i++)
    {
        s1 = getBinaryString(arr1[i],n);
        s2 = getBinaryString(arr2[i],n);
        answer.push_back(getResult(s1,s2));
    }
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 5;
    vector<int> arr1 = {9,20,28,18,11};
    vector<int> arr2 = {30,1,21,17,28};
    vector<string> result = solution(n,arr1,arr2);
    
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}
