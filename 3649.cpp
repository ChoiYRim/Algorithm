#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int X,N;

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while(cin >> X)
    {
        int left,right;
        bool check = false;
        vector<int> lego;
        
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            lego.push_back(temp);
        }
        
        X *= 10000000;
        sort(lego.begin(),lego.end());
        
        left = 0;
        right = N-1;
        while(left < right)
        {
            int sum = lego[left]+lego[right];
            
            if(sum == X)
            {
                check = true;
                cout << "yes " << lego[left] << " " << lego[right] << "\n";
                break;
            }
            else if(sum < X)
                left++;
            else
                right--;
        }
        if(!check)
            cout << "danger\n";
    }
    
    return 0;
}
