/*
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _fireBall
{
    int y; // 행
    int x; // 열
    int mass; // 질량
    int speed; // 속도
    int dir; // 방향
}Fireball;

typedef struct _duplicate
{
    int y;
    int x;
    int num;
}Dup;

int n,m,k;
int map[55][55];
int result = 0;
vector<Fireball> fireBall;

int vect_y[8] = {-1,-1,0,1,1,1,0,-1}; // clockwise
int vect_x[8] = {0,1,1,1,0,-1,-1,-1}; // clockwise

void print_map(void)
{
    cout << "Map" << '\n';
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << map[i][j] << " ";
        cout << '\n';
    }
}

void print_fb(void)
{
    for(int i = 0; i < fireBall.size(); i++)
    {
        printf("[%d] : (y = %d, x = %d, m = %d, s = %d, d = %d\n",i+1,fireBall[i].y,fireBall[i].x,fireBall[i].mass,fireBall[i].speed,fireBall[i].dir);
    }
}

void split_fb(void)
{
    int i,j,k;
    int nm = 0,ns = 0,nd = 0,check = -3;
    vector<Dup> temp;
    
    for(i = 0; i < n; i++) // 중첩 찾기
    {
        for(j = 0; j < n; j++)
        {
            if(map[i][j] > 1)
            {
                k = 0;
                nm = ns = 0;
                nd = -1;
                check = -3;
                while(k < fireBall.size())
                {
                    if(i == fireBall[k].y && j == fireBall[k].x)
                    {
                        nm += fireBall[k].mass;
                        ns += fireBall[k].speed;
                        if(check == -3)
                            check = fireBall[k].dir % 2;
                        else
                        {
                            if(check != fireBall[k].dir % 2)
                                check = -1;
                        }
                        fireBall.erase(fireBall.begin()+k);
                        k = 0;
                        continue;
                    }
                    k++;
                }
                if(nm / 5 < 1)
                {
                    map[i][j] = 0;
                    continue;
                }
                else
                {
                    ns /= map[i][j];
                    map[i][j] = 4;
                    nm /= 5;
                    
                    if(check != -1)
                        nd = -2;
                    for(k = 0; k < 4; k++)
                    {
                        nd += 2;
                        fireBall.push_back({i,j,nm,ns,nd});
                    }
                }
            }
        }
    }
}

int cal(int a,int b)
{
    int ret = (a*b)%n;
    
    if(ret < 0)
    {
        ret = -ret;
    }
    
    return ret;
}

void move_fb(void)
{
    int i,cur_y,cur_x;
    
    for(i = 0; i < fireBall.size(); i++)
    {
        cur_y = fireBall[i].y;
        cur_x = fireBall[i].x;
        
        int next_y = cur_y + vect_y[fireBall[i].dir]*(fireBall[i].speed%n);
        int next_x = cur_x + vect_x[fireBall[i].dir]*(fireBall[i].speed%n);
        
        if(next_y < 0)
            next_y += n;
        if(next_y >= n)
            next_y -= n;
        if(next_x < 0)
            next_x += n;
        if(next_x >= n)
            next_x -= n;
        
        //printf("ny : %d, nx : %d\n", next_y, next_x);
        
        map[cur_y][cur_x]--;
        map[next_y][next_x]++;
        fireBall[i].y = next_y; fireBall[i].x = next_x;
    }
}

void get_result(void)
{
    for(int i = 0; i < fireBall.size(); i++)
    {
        result += fireBall[i].mass;
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int step = 0;
    
    memset((int *)map,0,sizeof(map));
    
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int ty,tx,tm,ts,td;
        cin >> ty >> tx >> tm >> ts >> td;
        fireBall.push_back({ty-1,tx-1,tm,ts,td});
        map[ty-1][tx-1] = 1;
    }
    
    while(step < k)
    {
        move_fb();
        split_fb();
        //cout << "Step : " << step+1 << '\n';
        //print_map();
        //print_fb();
        step++;
    }
    
    get_result();
    cout << result << '\n';
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N,M,K;
const int dy[8]={-1,-1,0,1,1,1,0,-1};
const int dx[8]={0,1,1,1,0,-1,-1,-1};

struct Fireball{
    int r,c,m,s,d;
    Fireball(int r,int c,int m,int s,int d):r(r),c(c),m(m),s(s),d(d){}
};

vector<Fireball> board[50][50];

Fireball move(Fireball f){
    for(int i=0;i<f.s;i++){
        f.r += dy[f.d];
        if(f.r==N) f.r=0;
        else if(f.r==-1) f.r=N-1;

        f.c += dx[f.d];
        if(f.c==N) f.c=0;
        else if(f.c==-1) f.c=N-1;
    }
    return f;
}

void moveFireballs(){
    vector<Fireball> newBoard[50][50];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(Fireball f:board[i][j]){
                Fireball next = move(f);
                newBoard[next.r][next.c].push_back(next);
            }
        }
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            board[i][j]=newBoard[i][j];
}

void unionFireballs(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j].size()<2) continue;

            int totN=board[i][j].size();
            int totM=0, totS=0, chk=0;

            for(Fireball f:board[i][j]){
                totM += f.m;
                totS += f.s;
                if(f.d%2==0) ++chk;
                else --chk;
            }

            board[i][j].clear();

            if(totM/5==0) continue;

            for(int k=0;k<4;k++){
                if(abs(chk)==totN)
                    board[i][j].push_back(Fireball(i,j,totM/5,totS/totN,k*2));
                else
                    board[i][j].push_back(Fireball(i,j,totM/5,totS/totN,k*2+1));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>M>>K;

    for(int i=0;i<M;i++){
        int r,c,m,s,d;
        cin>>r>>c>>m>>s>>d;
        board[r-1][c-1].push_back(Fireball(r-1,c-1,m,s,d));
    }

    while(K--){
        moveFireballs();
        unionFireballs();
    }

    int ans=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(Fireball f:board[i][j])
                ans+=f.m;

    cout<<ans;

    return 0;
}
