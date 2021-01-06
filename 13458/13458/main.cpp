#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n,b,c;
vector<int> room;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long result = 0;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        
        room.push_back(temp);
    }
    cin >> b >> c;
    
    for(int i = 0; i < n; i++)
    {
        int temp;
        
        result += 1;
        if(room[i] > b)
            room[i] -= b;
        else
            continue;
        //cout << room[i] / c << " " << room[i] % c << endl;
        temp = (room[i] / c);
        if(room[i]%c > 0)
            temp++;
        result += temp;
    }
    
    cout << result << '\n';
    return 0;
}
