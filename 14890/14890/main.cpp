#include <algorithm>
#include <iostream>
#include <cstring>

#define ABS(x) (x > 0 ? x : -x)

using namespace std;

int n,l;
int map[111][111];
bool isRoad[111][111];
int result = 0;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    bool check;
    int now;
    
    memset((int *)map,0,sizeof(map));
    cin >> n >> l;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
        
    // check rows
    memset((bool *)isRoad,0,sizeof(isRoad));
    for(int i = 1; i <= n; i++)
    {
        check = true;
        now = map[i][1];
        for(int j = 2; j <= n; j++)
        {
            if(ABS((now-map[i][j])) > 1)
            {
                check = false;
                break;
            }
            if(ABS((now-map[i][j])) == 1)
            {
                if(now > map[i][j])
                {
                    for(int k = j; k <= j+l-1; k++)
                    {
                        if(isRoad[i][k] || map[i][j] != map[i][k])
                        {
                            check = false;
                            break;
                        }
                        isRoad[i][k] = true;
                    }
                    if(!check)
                        break;
                }
                else
                {
                    for(int k = j-1; k >= j-l; k--)
                    {
                        if(isRoad[i][k] || now != map[i][k])
                        {
                            check = false;
                            break;
                        }
                        isRoad[i][k] = true;
                    }
                    if(!check)
                        break;
                }
            }
            now = map[i][j];
        }
        if(check)
            result++;
    }

    // check columns
    memset((bool *)isRoad,0,sizeof(isRoad));
    for(int i = 1; i <= n; i++)
    {
        check = true;
        now = map[1][i];
        
        for(int j = 2; j <= n; j++)
        {
            if(ABS((now-map[j][i])) > 1)
            {
                check = false;
                break;
            }
            if(ABS((now-map[j][i])) == 1)
            {
                if(now > map[j][i])
                {
                    for(int k = j; k <= j+l-1; k++)
                    {
                        if(isRoad[k][i] || map[j][i] != map[k][i])
                        {
                            check = false;
                            break;
                        }
                        isRoad[k][i] = true;
                    }
                    if(!check)
                        break;
                }
                else
                {
                    for(int k = j-1; k >= j-l; k--)
                    {
                        if(isRoad[k][i] || now != map[k][i])
                        {
                            check = false;
                            break;
                        }
                        isRoad[k][i] = true;
                    }
                    if(!check)
                        break;
                }
            }
            now = map[j][i];
        }
        if(check)
            result++;
    }
    
    cout << result << '\n';
    return 0;
}
