#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Pos
{
    int y;
    int x;
    int dir; // 북 동 남 서 -> 0 , 1 , 2 , 3
};

int TC;
Pos leftUp,rightDown;

void posExchange(Pos cur)
{
    leftUp = {max(cur.y,leftUp.y),min(cur.x,leftUp.x),0};
    rightDown = {min(cur.y,rightDown.y),max(cur.x,rightDown.x),0};
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    
    vector<int> result;
    
    cin >> TC;
    while(TC--)
    {
        int extent = 0;
        string str = "";
        Pos pos = {0,0,0};
        leftUp = {0,0,0};
        rightDown = {0,0,0};
        
        cin >> str;
        for(int i = 0; i < (int)str.length(); i++)
        {
            char cmd = str[i];
            int dir = pos.dir;
            int y = pos.y,x = pos.x;
            
            if(cmd == 'F')
            {
                if(dir == 0)
                    y += 1;
                else if(dir == 1)
                    x += 1;
                else if(dir == 2)
                    y -= 1;
                else
                    x -= 1;
            }
            else if(cmd == 'B')
            {
                if(dir == 0)
                    y -= 1;
                else if(dir == 1)
                    x -= 1;
                else if(dir == 2)
                    y += 1;
                else
                    x += 1;
            }
            else if(cmd == 'L')
            {
                if(dir-1 < 0)
                    dir = 3;
                else
                    dir--;
                dir %= 4;
            }
            else if(cmd == 'R')
            {
                if(dir+1 > 3)
                    dir = 0;
                else
                    dir++;
                dir %= 4;
            }
            
            pos = {y,x,dir};
            posExchange(pos);
        }
        extent = (leftUp.y-rightDown.y) * (rightDown.x-leftUp.x);
        result.push_back(extent);
    }
    
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}
