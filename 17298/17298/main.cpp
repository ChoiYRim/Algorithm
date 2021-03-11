#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 1000000+1

using namespace std;

int N;
stack<pair<int,int>> st;
vector<pair<int,int>> v;
int result[MAX] = {0,};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back({num,i+1});
    }
    
    st.push(v[0]);
    for(int i = 1; i < N; i++)
    {
        if(st.top() < v[i])
        {
            // pop
            
        }
        else
            st.push(v[i]);
    }
    return 0;
}
