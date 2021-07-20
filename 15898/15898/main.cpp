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
Kiln ingredient[10][4][4] = {0,};
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

void turn(int idx,bool clockWise,Kiln arr[4][4])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(!clockWise) // counter clock wise
            {
                ingredient[idx][i][j].quality = arr[j][3-i].quality;
                ingredient[idx][i][j].color = arr[j][3-i].color;
            }
            else
            {
                ingredient[idx][i][j].quality = arr[3-j][i].quality;
                ingredient[idx][i][j].color = arr[3-j][i].color;
            }
        }
    }
}

void turnIngredient(int idx,bool clockWise)
{
    Kiln arr[4][4] = {0,};
    memcpy((Kiln *)arr, (Kiln *)ingredient[idx], sizeof(ingredient[idx]));
    turn(idx,clockWise,arr);
    
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

void putIngredient(int idx,pair<int,int> leftUp)
{
    int y = leftUp.first,x = leftUp.second;
    int inY = 0,inX = 0;
    
    if((y > 1 || x > 1) || (y < 0 || x < 0))
        return;
    
    for(int i = y; i < 5 && inY < 4; i++)
    {
        for(int j = x; j < 5 && inX < 4; j++)
        {
            if(ingredient[idx][inY][inX].color != 'W')
                kiln[i][j].color = ingredient[idx][inY][inX].color;
            kiln[i][j].quality += ingredient[idx][inY][inX].quality;
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

void DFS(int idx,vector<int> comb,vector<pair<int,int>> coordinate)
{
    if(idx >= 3)
    {
        init();
        for(int i = 0; i < (int)coordinate.size(); i++)
            putIngredient(comb[i],coordinate[i]);
        result = MAX(result,getQuality());
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        coordinate.push_back(leftUps[i]);
        Kiln save[4][4] = {0,};
        memcpy((Kiln *)save, (Kiln *)ingredient[comb[idx]], sizeof(ingredient[comb[idx]]));
        
        for(int j = 0; j < 3; j++)
        {
            turnIngredient(comb[idx],false);
            DFS(idx+1,comb,coordinate);
        }
        memcpy((Kiln *)ingredient[comb[idx]], (Kiln *)save, sizeof(ingredient[comb[idx]]));
        for(int j = 0; j < 3; j++)
        {
            turnIngredient(comb[idx],true);
            DFS(idx+1,comb,coordinate);
        }
        memcpy((Kiln *)ingredient[comb[idx]], (Kiln *)save, sizeof(ingredient[comb[idx]]));
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
            ingredient[i][j/4][j%4].quality = temp;
        }
        for(int j = 0; j < 16; j++)
        {
            char temp;
            cin >> temp;
            ingredient[i][j/4][j%4].color = temp;
        }
    }
    for(int i = 0; i < N; i++)
        perm.push_back(i);
    
    leftUps = {{0,0},{0,1},{1,0},{1,1}};
    permutation(perm,0,N,3);
    //combination(comb, 3, 0, 0);
    for(int i = 0; i < (int)allCase.size(); i++)
        DFS(0,allCase[i],{});
    cout << result << '\n';
    return 0;
}
