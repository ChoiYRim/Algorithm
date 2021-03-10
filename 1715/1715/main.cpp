#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int N,result = 0;
priority_queue<int> pq;

inline bool comp(int& i1,int& i2) { return i1 < i2; }

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
        pq.push(-num);
    }
    
    while(pq.size() > 1)
    {
        int ft = pq.top();
        pq.pop();
        int st = pq.top();
        pq.pop();
        pq.push(ft+st);
        result += (ft+st);
    }
    
    cout << -result << '\n';
    return 0;
}
