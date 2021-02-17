#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

using namespace std;

#define MAX 500001

long long *segTree;
vector<long long> v;

void runTime(struct timeval& begin,struct timeval& end)
{
    auto secondToMicro = 1000000;
    
    end.tv_sec -= begin.tv_sec;
    if(begin.tv_usec > end.tv_usec)
    {
        end.tv_sec--;
        end.tv_usec += secondToMicro;
    }
    end.tv_usec -= begin.tv_usec;
    cout << "RunTime : [" << end.tv_sec << "." << end.tv_usec << " sec]" << endl;
}

long long linear(vector<long long> v)
{
    long long sum = 0;
    
    for(int i = 0; i < (int)v.size(); i++)
        sum += v[i];
    
    return sum;
}

long long treeInit(int idx,int start,int end)
{
    int child = idx*2;
    int left = child+1,right = child+2;
    
    if(start == end)
        segTree[idx] = v[start];
    else
        segTree[idx] = treeInit(left,start,(start+end)/2) + treeInit(right,(start+end)/2+1,end);
    
    return segTree[idx];
}

// v[idx]번값을 value값으로 바꿀 경우 -> [start,end] 범위에서 탐색
void treeUpdate(int idx,long long diff,int cur,int start,int end)
{
    if(idx < start || idx > end)
        return;
    
    segTree[cur] += diff;
    
    if(start != end)
    {
        int mid = (start+end)/2;
        
        treeUpdate(idx,diff,cur*2+1,start,mid);
        treeUpdate(idx,diff,cur*2+2,mid+1,end);
    }
}

int main(int argc, const char * argv[])
{
    struct timeval begin,end;
    long long height,treeSize;
    
    srand((unsigned int)time(NULL));
    for(int i = 1; i <= MAX; i++)
        v.push_back(rand()%MAX);
    
    height = ceil(log2(v.size()));
    treeSize = 1 << (height+1);
    segTree = new long long[treeSize];
    
    gettimeofday(&begin,NULL);
    cout << "선형 합 : " << linear(v) << '\n';
    gettimeofday(&end,NULL);
    runTime(begin,end);
    
    gettimeofday(&begin,NULL);
    treeInit(0,0,(int)v.size()-1);
    cout << "세그먼트 트리 합 : " << segTree[0] << '\n';
    gettimeofday(&end,NULL);
    runTime(begin,end);
    
    gettimeofday(&begin,NULL);
    long long diff = 28-v[10000];
    v[10000] = 28;
    cout << "선형 합 : " << linear(v) << '\n';
    gettimeofday(&end,NULL);
    runTime(begin,end);
    
    gettimeofday(&begin,NULL);
    treeUpdate(10000,diff,0,0,(int)v.size()-1);
    cout << "세그먼트 트리 합 : " << segTree[0] << '\n';
    gettimeofday(&end,NULL);
    runTime(begin,end);
    
    delete segTree;
    return 0;
}
