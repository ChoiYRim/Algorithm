#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int zero = 0;
int n,k,cur = 0;
vector<pair<int,bool>> belt;

void print_belt(void)
{
    cout << "Belt" << '\n';
    for(int i = 1; i <= n; i++)
        cout << "[ " << belt[i].first << " , " << belt[i].second << " ] ";
    cout << '\n';
}

void rotate_belt(void)
{
    for(int i = n+1; i <= 2*n; i++)
        if(belt[i].second)
            belt[i].second = false;
    
    pair<int,bool> end = belt[2*n];

    for(int i = 2*n; i-1 > 0; i--)
        belt[i] = belt[i-1];
    belt[1] = end;
}

void rotate_robot(void)
{
    if(belt[n].second)
        belt[n].second = false;
    
    for(int i = n-1; i-1 > 0; i--)
    {
        if(belt[i].second)
        {
            if(!belt[i+1].second)
            {
                if(belt[i+1].first > 0)
                {
                    belt[i+1].second = true;
                    belt[i+1].first--;
                    if(belt[i+1].first == 0)
                        zero++;
                    belt[i].second = false;
                }
            }
        }
    }
    
    /*
    for(int i = n; i-1 > 0; i--)
    {
        if(!belt[i].second && belt[i-1].second)
        {
            if(belt[i].first > 0)
            {
                belt[i].first -= 1;
                if(belt[i].first == 0)
                    zero++;
                belt[i].second = true;
                belt[i-1].second = false;
            }
        }
    }
    */
}

int main(int argc, const char * argv[])
{
    int step = 0;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    belt.push_back({0,0});
    
    for(int i = 1; i <= 2*n; i++)
    {
        int temp;
        cin >> temp;
        belt.push_back({temp,false});
    }
    
    while(zero < k)
    {
        rotate_belt();
        rotate_robot();
                
        if(!belt[1].second) // 올라가는 위치에 로봇이 없다면
        {
            if(belt[1].first > 0)
            {
                belt[1].second = true;
                belt[1].first--;
                if(!belt[1].first)
                    zero++;
            }
        }
        step++;
    }
     
    cout << step << '\n';
    return 0;
}
