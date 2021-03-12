#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 1000000+2

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
        v.push_back({num,i});
    }
    
    st.push(v[0]);
    for(int i = 1; i < N; i++)
    {
        int top = MAX;
        
        if(!st.empty())
            top = st.top().first;
        if(top < v[i].first)
        {
            // flush
            while(!st.empty() && v[i].first > top)
            {
                pair<int,int> element = st.top();
                result[element.second] = v[i].first;
                st.pop();
                if(!st.empty())
                    top = st.top().first;
            }
            st.push(v[i]);
        }
        else
        {
            st.push(v[i]);
        }
    }
    while(!st.empty())
    {
        pair<int,int> element = st.top();
        result[element.second] = -1;
        st.pop();
    }
    
    for(int i = 0; i < N; i++)
        cout << result[i] << ' ';
    cout << '\n';
    return 0;
}
