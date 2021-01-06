#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m; // height, width
int cmd; // the number of commands
vector<vector<int> > map;
/*
    0 : north
    1 : left
    2 : up
    3 : right
    4 : south
    5 : bottom
*/

int dice[6] = {0,}; // dice

/*
    동 : 1
    서 : 2
    북 : 3
    남 : 4
*/

int vect_y[5] = {0,1,-1,0,0}; // width
int vect_x[5] = {0,0,0,-1,1}; // height

pair<int,int> pos; // position of dice
vector<int> commands;
vector<int> result;

void print_dice(void)
{
    for(int i = 0; i < 6; i++)
        cout << dice[i] << " ";
    cout << '\n';
}

void fling(int d)
{
    int temp[6];
    
    copy(dice,dice+6,temp);
    
    if(d == 1) // East
    {
        dice[1] = temp[2];
        dice[2] = temp[3];
        dice[3] = temp[5];
        dice[5] = temp[1];
    }
    else if(d == 2) // West
    {
        dice[1] = temp[5];
        dice[2] = temp[1];
        dice[3] = temp[2];
        dice[5] = temp[3];
    }
    else if(d == 3) // North
    {
        dice[0] = temp[2];
        dice[2] = temp[4];
        dice[4] = temp[5];
        dice[5] = temp[0];
    }
    else // South
    {
        dice[0] = temp[5];
        dice[2] = temp[0];
        dice[4] = temp[2];
        dice[5] = temp[4];
    }
}

int main(int argc, const char * argv[])
{
    int x,y;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> x >> y >> cmd;
    pos = {x,y}; // {height,width}
    
    for(int i = 0; i < n; i++)
    {
        vector<int> vec;
        
        for(int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        map.push_back(vec);
    }
    
    for(int i = 0; i < cmd; i++)
    {
        int temp;
        cin >> temp;
        
        commands.push_back(temp);
    }
    
    for(int i = 0; i < cmd; i++)
    {
        int next_x = pos.first + vect_x[commands[i]];
        int next_y = pos.second + vect_y[commands[i]];
                
        if(((0 <= next_x) && (next_x < n)) && ((0 <= next_y) && (next_y < m)))
        {
            fling(commands[i]);

            if(map[next_x][next_y] == 0)
            {
                map[next_x][next_y] = dice[5];
            }
            else
            {
                dice[5] = map[next_x][next_y];
                map[next_x][next_y] = 0;
            }
            
            pos = {next_x,next_y};
            result.push_back(dice[2]);
        }
    }
    
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}
