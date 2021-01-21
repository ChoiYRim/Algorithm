#include <cstring>
#include <iostream>
#include <algorithm>

#define ISRANGE(x,R) (1 <= x && x <= R)

using namespace std;

struct Coordinate
{
    int x;
    int y;
};

int N; // 5 ~ 20
int A[21][21];
int map[21][21];
int answer;
Coordinate north,east,south,west;

void print_map(void)
{
    cout << "Map\n";
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cout << map[i][j] << " ";
        cout << '\n';
    }
    
    cout << "Answer : " << answer << '\n';
}

bool conditionOK(int x,int y,int d1,int d2)
{
    if(x+d1 >= N || y-d1 < 0)
        return false;
    if(x+d2 >= N || y+d2 >= N)
        return false;
    if(x+d1+d2 >= N || y-d1+d2 >= N)
        return false;
    if(x+d1+d2 >= N || y-d1+d2 < 0)
        return false;
    return true;
}

void getResult(int x,int y,int d1,int d2)
{
    int mini,maxi;
    int one,two,three,four,five;
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            map[i][j] = 5;
    
    int cnt = 0;
    for(int i = 1; i < west.x; i++) // Sector 1 : Correct
    {
        if(i >= north.x)
            cnt++;
        for(int j = 1; j <= north.y-cnt; j++)
        {
            map[i][j] = 1;
        }
    }
    
    cnt = 0;
    for(int i = 1; i <= east.x; i++) // Sector 2 : Modified
    {
        if(i > north.x)
            cnt++;
        for(int j = north.y+1+cnt; j <= N; j++)
        {
            map[i][j] = 2;
        }
    }
    
    cnt = 0;
    for(int i = west.x; i <= N; i++) // Sector 3 : Correct
    {
        for(int j = 1; j < south.y && j < west.y+cnt; j++)
        {
            map[i][j] = 3;
        }
        cnt++;
    }
    
    cnt = 0;
    for(int i = N; i >= east.x+1; i--) // Sector 4 : Modified
    {
        if(i <= south.x)
            cnt++;
        for(int j = south.y+cnt; j <= N; j++)
        {
            map[i][j] = 4;
        }
    }
        
    one = two = three = four = five = 0;
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(map[i][j] == 1)
                one+=A[i][j];
            else if(map[i][j] == 2)
                two+=A[i][j];
            else if(map[i][j] == 3)
                three+=A[i][j];
            else if(map[i][j] == 4)
                four+=A[i][j];
            else
                five+=A[i][j];
        }
    }
    
    maxi = max(one,max(two,max(three,max(four,five))));
    mini = min(one,min(two,min(three,min(four,five))));
    answer = min(answer,maxi-mini);
    
    //print_map();
}

int solution(void)
{
    memset((int *)map,0,sizeof(map));
    answer = 0x7fffffff;

    for(int x = 1; x <= N; x++) // Row
    {
        for(int y = 1; y <= N; y++) // Column
        {
            for(int d1 = 1; d1 <= N; d1++)
            {
                for(int d2 = 1; d2 <= N; d2++)
                {
                    if(conditionOK(x,y,d1,d2))
                    {
                        north.x = x; north.y = y; // 5번의 북쪽 꼭지점
                        west.x = x+d1; west.y = y-d1; // " 서쪽
                        south.x = x+d1+d2; south.y = y-d1+d2; // " 남쪽
                        east.x = x+d2; east.y = y+d2; // " 동쪽
                        getResult(x,y,d1,d2);
                    }
                }
            }
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset((int *)A,0,sizeof(A));
    
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> A[i][j];
    }
    
    cout << solution() << '\n';
    return 0;
}
