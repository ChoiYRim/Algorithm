#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>

#define IS_ALPHA(x) (('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z') || x == '-' || x == ' ' || x == '.')
#define IS_NUMBER(x) ('0' <= x && x <= '9')

using namespace std;

typedef struct _file
{
    string head;
    string number;
}FileName;

int n;

void getElements(string str,FileName* ret)
{
    string element = str;
    int cur = 0,cnt = 0;
        
    string head = "",number = "";
    
    while(cur < element.length() && IS_ALPHA(element[cur]))
    {
        head += element[cur];
        cur++;
    }
    
    while(cnt < 5 && cur < element.length() && IS_NUMBER(element[cur]))
    {
        number += element[cur];
        cur++; cnt++;
    }
    
    ret->head = head;
    ret->number = number;
}

bool compareByRules(const string& fn1,const string& fn2)
{
    FileName ret1,ret2;
    
    getElements(fn1,&ret1);
    getElements(fn2,&ret2);
    
    string c1 = "",c2 = "";
    int n1,n2;
    
    c1 = ret1.head;
    c2 = ret2.head;
    
    for(int i = 0; i < c1.length(); i++)
    {
        c1[i] = tolower(c1[i]);
    }
    for(int i = 0; i < c2.length(); i++)
    {
        c2[i] = tolower(c2[i]);
    }
    
    if(c1 == c2)
    {
        //cout << ret1.number << " ";
        //cout << ret2.number << endl;;
        n1 = stoi(ret1.number);
        n2 = stoi(ret2.number);
        
        return (n1 < n2);
    }
    else if(c1 > c2)
        return false;
    return true;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    
    stable_sort(files.begin(),files.end(),compareByRules);
    answer = files;
        
    return answer;
}

int main(int argc, const char * argv[])
{
    vector<string> files,answer;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++)
    {
        string str;
        getline(cin,str);
        files.push_back(str);
    }
    
    answer = solution(files);
    
    cout << endl << "Answer" << endl;
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    
    return 0;
}
