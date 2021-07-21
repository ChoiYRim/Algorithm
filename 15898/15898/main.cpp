#include <memory>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

struct Kiln
{
    char color; // R G B Y W
    int quality; // -9 ~ 9
};

int N,result = 0;
Kiln kiln[5][5] = {0,};
Kiln ingredient[10][2][4][4][4] = {0,}; // [재료 인덱스][(시계 / 반시계)][ 회전 횟수][Y][X]
vector<pair<int,int>> leftUps;
vector<vector<int>> allCase;

void init(void)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            kiln[i][j].color = 'W';
            kiln[i][j].quality = 0;
        }
    }
}

void makeTurnedIngredient(int idx,bool clockWise)
{
    for(int turn = 1; turn < 4; turn++)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(!clockWise) // counter clock wise
                {
                    ingredient[idx][1][turn][i][j].quality = ingredient[idx][1][turn-1][j][3-i].quality;
                    ingredient[idx][1][turn][i][j].color = ingredient[idx][1][turn-1][j][3-i].color;
                }
                else
                {
                    ingredient[idx][0][turn][i][j].quality = ingredient[idx][0][turn-1][3-j][i].quality;
                    ingredient[idx][0][turn][i][j].color = ingredient[idx][0][turn-1][3-j][i].color;
                }
            }
        }
    }
}

int getQuality(void)
{
    int r,g,b,y;
    
    r = g = b = y = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(kiln[i][j].color == 'R')
                r += kiln[i][j].quality;
            else if(kiln[i][j].color == 'G')
                g += kiln[i][j].quality;
            else if(kiln[i][j].color == 'B')
                b += kiln[i][j].quality;
            else if(kiln[i][j].color == 'Y')
                y += kiln[i][j].quality;
        }
    }
    
    return (7*r+3*g+5*b+2*y);
}

void putIngredient(int idx,pair<int,int> leftUp,int turn)
{
    int y = leftUp.first,x = leftUp.second;
    int inY = 0,inX = 0;
    int clockWise,turnIdx;
    
    if((y > 1 || x > 1) || (y < 0 || x < 0))
        return;
    
    clockWise = turn/4; turnIdx = turn%4;
    for(int i = y; i < 5 && inY < 4; i++)
    {
        for(int j = x; j < 5 && inX < 4; j++)
        {
            if(ingredient[idx][clockWise][turnIdx][inY][inX].color != 'W')
                kiln[i][j].color = ingredient[idx][clockWise][turnIdx][inY][inX].color;
            kiln[i][j].quality += ingredient[idx][clockWise][turnIdx][inY][inX].quality;
            if(kiln[i][j].quality < 0)
                kiln[i][j].quality = 0;
            else if(kiln[i][j].quality > 9)
                kiln[i][j].quality = 9;
            inX++;
        }
        inY++;
        inX = 0;
    }
}

inline int MAX(int x,int y) { return (x > y ? x : y); }

void DFS(int idx,vector<int> comb,vector<pair<int,int>> coordinate,vector<int> turn)
{
    if(idx >= 3)
    {
        init();
        for(int i = 0; i < (int)coordinate.size(); i++)
            putIngredient(comb[i],coordinate[i],turn[i]);
        result = MAX(result,getQuality());
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        coordinate.push_back(leftUps[i]);
        
        for(int j = 0; j < 6; j++)
        {
            turn.push_back(j);
            DFS(idx+1,comb,coordinate,turn);
            turn.pop_back();
        }
        
        coordinate.pop_back();
    }
}

//void combination(vector<int> comb,int r,int index,int depth)
//{
//    if(!r)
//        DFS(0,comb,{});
//    else if(depth == N)
//        return;
//    else
//    {
//        // depth 번째 ingredient를 골랐다면
//        comb[index] = depth;
//        combination(comb,r-1,index+1,depth+1);
//
//        // 고르지 않았다면
//        combination(comb,r,index,depth+1);
//    }
//}

void permutation(vector<int> perm,int depth,int n,int r)
{
    if(depth == r)
    {
        allCase.push_back(perm);
        return;
    }
    
    for(int i = depth; i < n; i++)
    {
        swap(perm[depth],perm[i]);
        permutation(perm,depth+1,n,r);
        swap(perm[i],perm[depth]);
    }
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> perm;
            
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            int temp;
            cin >> temp;
            ingredient[i][0][0][j/4][j%4].quality = temp;
            ingredient[i][1][0][j/4][j%4].quality = temp;
        }
        for(int j = 0; j < 16; j++)
        {
            char temp;
            cin >> temp;
            ingredient[i][0][0][j/4][j%4].color = temp;
            ingredient[i][1][0][j/4][j%4].color = temp;
        }
    }
    for(int i = 0; i < N; i++)
    {
        perm.push_back(i);
        makeTurnedIngredient(i,true);
        makeTurnedIngredient(i,false);
    }
    leftUps = {{0,0},{0,1},{1,0},{1,1}};
    permutation(perm,0,N,3);
    //combination(comb, 3, 0, 0);
    for(int i = 0; i < (int)allCase.size(); i++)
        DFS(0,allCase[i],{},{});
    cout << result << '\n';
    return 0;
}
