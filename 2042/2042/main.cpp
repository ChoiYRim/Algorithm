#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Set
{
    long long a; long long b; long long c;
};

int N,M,K;
long long* tree;
vector<long long> v;
vector<Set> cmd;

long long init(int idx,int start,int end)
{
    int child = idx*2;
    int left = child+1,right = child+2,mid = (start+end)/2;
    
    if(start == end)
        tree[idx] = v[start];
    else
        tree[idx] = init(left,start,mid)+init(right,mid+1,end);
    
    return tree[idx];
}

void update(int idx,long long diff,int cur,int start,int end)
{
    if(idx < start || idx > end)
        return;
    
    tree[cur] += diff;
    
    if(start != end)
    {
        int mid = (start+end)/2;
        
        update(idx,diff,cur*2+1,start,mid);
        update(idx,diff,cur*2+2,mid+1,end);
    }
}

// tree의 index == idx
long long getSum(int idx,int start,int end,int left,int right)
{
    if(right < start || end < left) // 1 or 5
        return 0;
    else if(left <= start && end <= right)
        return tree[idx];
    
    int mid = (start+end)/2;
    
    return getSum(idx*2+1,start,mid,left,right)+getSum(idx*2+2,mid+1,end,left,right);
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
    }
    
    for(int i = 0; i < M+K; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        cmd.push_back({a,b,c});
    }
    
    int height = ceil(log2((int)v.size()));
    int treeSize = 1 << (height+1);
    
    tree = new long long[treeSize];
    init(0,0,(int)v.size()-1);
    
    for(int i = 0; i < (int)cmd.size(); i++)
    {
        Set s = cmd[i];
        
        if(s.a == 1) // update
        {
            s.b--;
            long long diff = s.c-v[s.b];
            v[s.b] = s.c;
            update((int)s.b,diff,0,0,(int)v.size()-1);
        }
        else if(s.a == 2)
        {
            s.b--; s.c--;
            cout << getSum(0,0,(int)v.size()-1,(int)s.b,(int)s.c) << '\n';
        }
    }
    
    delete tree;
    return 0;
}
