#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int n,ma,mi;
vector<int> num;
vector<int> ops;

int calculate(int a,int b,char op)
{
    switch(op)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            int temp;
            
            if(a < 0 && b > 0)
            {
                a = -a;
                temp = -(a/b);
            }
            else
                temp = a/b;
            return temp;
    }
    return 0;
}

int all_cal(char o[101])
{
    int result = num[0];
    
    for(int i = 1; o[i-1] != 0 && i < 101; i++)
    {
        result = calculate(result,num[i],o[i-1]);
    }
    return result;
}

char what_op(int i)
{
    if(i == 0)
        return '+';
    else if(i == 1)
        return '-';
    else if(i == 2)
        return '*';
    else
        return '/';
}

void dfs(int idx,char o[101],vector<int> nop)
{
    char new_o[101];
    vector<int> new_nop;
    
    if(idx == num.size())
    {
        int temp = all_cal(o);
        ma = max(ma,temp);
        mi = min(mi,temp);
        return;
    }
    
    memset((char *)new_o,0,sizeof(new_o));
    memcpy((char *)new_o,(char *)o,sizeof(char)*101);
    
    for(int i = 0; i < nop.size(); i++)
        new_nop.push_back(nop[i]);
    
    for(int i = 0; i < 4; i++)
    {
        if(nop[i] > 0)
        {
            new_nop[i]--;
            new_o[idx-1] = what_op(i);
            dfs(idx+1,new_o,new_nop);
            new_nop[i]++;
        }
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    vector<int> nop;
    ma = INT32_MIN;
    mi = INT32_MAX;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    
    for(int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        ops.push_back(temp);
        nop.push_back(temp);
    }
    
    char o[101];
    memset((char *)o,0,sizeof(o));
    
    dfs(1,o,nop);
    cout << ma << '\n';
    cout << mi << '\n';
    return 0;
}
