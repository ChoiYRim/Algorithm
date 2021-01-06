#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[101][101]; // 좌표 [y][x]

int get_result(void)
{
    int result = 0;
    
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= 100; j++)
        {
            if(map[i-1][j-1] == 1)
            {
                if(map[i-1][j] == map[i-1][j-1])
                {
                    if(map[i][j-1] == map[i-1][j])
                    {
                        map[i][j-1] == map[i][j] ? result++ : result;
                    }
                }
            }
        }
    }
    
    return result;
}

void rotate_90()
{
}

// x : column , y : row , d : direction , g : generation
void make_dc(int x,int y,int d,int g)
{
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
    }
    return 0;
}
