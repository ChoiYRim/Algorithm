#include <queue>
#include <deque>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

/*
    E : 0
    S : 1
    W : 2
    N : 3
*/

int next_direction(int cur,char turn)
{
    int next;
    
    if(turn == 'L') // left
    {
        if(cur  == 0)
            cur = 4;
        next = (cur - 1) % 4;
    }
    else // right
    {
        if(cur == 3)
            cur = -1;
        next = (cur + 1) % 4;
    }
    
    return next;
}

void print_debug(int dir,int n,int map[101][101])
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(int argc, const char * argv[])
{
    int time = 0;
    int n,k,l,current= 0;
    int map[101][101];
    int vect_x[4] = {1,0,-1,0}; // East South West North
    int vect_y[4] = {0,1,0,-1}; // same with above
    int next_x,next_y;

    deque<pair<int,int> > snake;
    queue<pair<int,char> > direct;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    memset((int *)map,0,sizeof(map));
    
    cin >> n;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int p1,p2; // row , column
        cin >> p1 >> p2;
        map[p1][p2] = 2;
    }
    
    cin >> l;
    for(int i = 0; i < l; i++)
    {
        int sec; char turn;
        cin >> sec >> turn;
        direct.push(make_pair(sec,turn));
    }
    
    snake.push_front({1,1});
    map[1][1] = 1;
    
    while(1) // time loop
    {
        //cout << "\n방향 : " << current << endl;
        //print_debug(current,n,map);
        
        if(!direct.empty() && time == direct.front().first) // change the current direction
        {
            current = next_direction(current,direct.front().second);
            direct.pop();
        }
                
        next_x = snake.front().first + vect_x[current];
        next_y = snake.front().second + vect_y[current];
        snake.push_front({next_x,next_y});
        
        if(((0 < next_x) && (next_x <= n)) && ((0 < next_y) && (next_y <= n)))
        {
            if(map[next_y][next_x] == 2) // an apple exists
            {
                map[next_y][next_x] = 1;
            }
            else if(map[next_y][next_x] == 1) // snake meets itself
            {
                cout << time+1 << '\n';
                return 0;
            }
            else // nothing exists
            {
                map[snake.back().second][snake.back().first] = 0;
                map[next_y][next_x] = 1;
                snake.pop_back();
            }
        }
        else
        {
            cout << time+1 << '\n';
            return 0;
        }
        
        time++;
    }
    
    return 0;
}
