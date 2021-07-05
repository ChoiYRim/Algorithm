#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
vector<string> nh,ns,common;

inline bool comp(string& s1,string& s2) { return s1 < s2; }

string bin_search(string target)
{
    int left = 0,right = (int)ns.size()-1,mid;
    
    while(left <= right)
    {
        mid = (left+right)/2;
        
        if(target > ns[mid])
            left = mid+1;
        else if(target < ns[mid])
            right = mid-1;
        else
            return target;
        
    }
    
    return "";
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        string person;
        cin >> person;
        nh.push_back(person);
    }
    for(int i = 0; i < M; i++)
    {
        string person;
        cin >> person;
        ns.push_back(person);
    }
    
    sort(nh.begin(),nh.end());
    sort(ns.begin(),ns.end());
    
    for(int i = 0; i < (int)nh.size(); i++)
    {
        string result = bin_search(nh[i]);
        
        if(result.length() > 0)
            common.push_back(result);
    }
    
    cout << common.size() << '\n';
    for(int i = 0; i < common.size(); i++)
        cout << common[i] << '\n';
    
    return 0;
}
