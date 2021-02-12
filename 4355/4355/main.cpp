#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;

int gcd(int a,int b)
{
    return b == 0 ? a : gcd(b,a%b);
}

int EulerPhi(int N)
{
    int result = 1;
    vector<int> temp1;
    vector<pair<int,int>> temp2;
    
    while(N > 1)
    {
        for(int i = 2; i <= N; i++)
        {
            if(!(N%i))
            {
                N /= i;
                temp1.push_back(i);
                break;
            }
        }
    }
    
    sort(temp1.begin(),temp1.end());
    for(int i = 0; i < temp1.size(); i++)
    {
        int first = temp1[i],sum = 1;
        for(int j = i+1; j < temp1.size() && temp1[j] == first; j++)
        {
            sum++;
            i = j;
        }
        temp2.push_back({first,sum});
    }
    
    for(int i = 0; i < temp2.size(); i++)
    {
        result *= ((int)pow((double)temp2[i].first,(double)temp2[i].second)-
                   (int)pow((double)temp2[i].first,(double)temp2[i].second-1));
    }
    
    return result;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N = -1;
    while(1)
    {
        cin >> N;
        if(N == 0)
            break;
        v.push_back(N);
    }
    
    for(int i = 0; i < v.size(); i++)
    {
        cout << EulerPhi(v[i]) << '\n';
    }
    return 0;
}
