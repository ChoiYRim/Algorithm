#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
vector<int> n,m;

inline bool comp(const int& i1,const int& i2) { return i1 < i2; }

int binarySearch(int element,int size)
{
    int left = 0,right = size-1;
    int middle = size / 2;
    
    while(left <= right)
    {
        if(element < n[middle])
        {
            // left는 그대로
            right = middle-1;
            middle = (left + right) / 2;
        }
        else if(element > n[middle])
        {
            // right는 그대로
            left = middle+1;
            middle = (left + right) / 2;
        }
        else // find
            return 1;
    }
    
    return 0;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        n.push_back(temp);
    }
    
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        m.push_back(temp);
    }
    
    sort(n.begin(),n.end(),comp); // 이진탐색 전 정렬
    
    for(int i = 0; i < (int)m.size(); i++)
    {
        bool check = binarySearch(m[i],(int)n.size());
        if(check)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}
