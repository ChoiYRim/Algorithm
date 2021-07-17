#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,K;
int result;
vector<int> v,tab;
const int MAX = INT32_MAX;

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int curIdx = 0;
    
    result = 0;
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    tab = vector<int>(N,0);
    while(curIdx < K)
    {
        bool zero = false,empty = false;
        vector<int> dist = vector<int>(N,MAX);
        
        for(int i = 0; i < N && !zero; i++)
        {
            for(int j = curIdx; j < K && !zero; j++)
            {
                if(!tab[i])
                {
                    tab[i] = v[j];
                    empty = true;
                    break;
                }
                if(tab[i] == v[j])
                {
                    dist[i] = min(j-curIdx,dist[i]);
                    if(!dist[i])
                        zero = true;
                    break;
                }
            }
            if(empty)
                break;
        }
        if(empty)
        {
            curIdx++;
            continue;
        }
        if(!zero)
        {
            int pos = 0;
            int* maxIdx = &dist[0];
            for(int i = 1; i < N; i++)
            {
                if(*maxIdx < dist[i])
                {
                    pos = i;
                    maxIdx = &dist[i];
                }
            }
            tab[pos] = v[curIdx];
            result++;
        }
        
        curIdx++;
    }
    
    cout << result << '\n';
    return 0;
}
