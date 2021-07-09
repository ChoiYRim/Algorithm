#include <queue>
#include <vector>
#include <string>
#include <iostream>

#define RANGE(x,y) ((0 <= x && x < 6) && (0 <= y && y < 12))

using namespace std;

int result = 0;
int dx[4] = {0,1,0,-1}; // 북 동 남 서
int dy[4] = {-1,0,1,0}; // "
vector<vector<int>> v;

void print(void)
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 6; j++)
            cout << v[i][j] << " ";
        cout << '\n';
    }
}

void pull(void)
{
    for(int x = 0; x < 6; x++)
    {
        int top,bottom;
        for(int y = 11; y >= 0; y--)
        {
            if(!v[y][x])
            {
                int temp = y;
                
                bottom = y;
                while(temp > -1 && !v[temp][x])
                    temp--;
                top = temp;
                
                for(int k = top; k >= 0; k--)
                {
                    v[bottom][x] = v[k][x];
                    v[k][x] = 0;
                    bottom--;
                }
            }
        }
    }
}

bool is_finished(void)
{
    bool check = false;
    vector<vector<pair<int,int>>> point;
    
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(v[i][j])
            {
                int color = v[i][j];
                queue<pair<int,int>> q;
                vector<pair<int,int>> temp;
                
                q.push({i,j});
                temp.push_back({i,j});
                v[i][j] *= -1;
                while(!q.empty())
                {
                    pair<int,int> cur = q.front();
                    q.pop();
                    
                    int x = cur.second,y = cur.first;
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        
                        if(RANGE(nx,ny) && v[ny][nx] == color)
                        {
                            v[ny][nx] *= -1;
                            q.push({ny,nx});
                            temp.push_back({ny,nx});
                        }
                    }
                }
                if(temp.size() > 3)
                {
                    check = true;
                    point.push_back(temp);
                    temp.clear();
                }
                else
                {
                    for(int i = 0; i < (int)temp.size(); i++)
                        v[temp[i].first][temp[i].second] *= -1;
                }
            }
        }
    }
    
    for(int i = 0; i < (int)point.size(); i++)
    {
        for(int j = 0; j < (int)point[i].size(); j++)
        {
            int x = point[i][j].second,y = point[i][j].first;
            v[y][x] = 0;
        }
    }
    
    return !check;
}

void game(void)
{
    //cout << "Before start" << "\n\n";
    //print();
    
    while(!is_finished())
    {
        pull();
        //cout << "\nPrint Result" << "\n\n";
        //print();
        result++;
    }
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i < 12; i++)
    {
        string str = "";
        vector<int> temp;

        cin >> str;
        for(int j = 0; j < (int)str.length(); j++)
        {
            if(str[j] == 'R')
                temp.push_back(1);
            else if(str[j] == 'G')
                temp.push_back(2);
            else if(str[j] == 'B')
                temp.push_back(3);
            else if(str[j] == 'P')
                temp.push_back(4);
            else if(str[j] == 'Y')
                temp.push_back(5);
            else
                temp.push_back(0);
        }
        v.push_back(temp);
    }
    
    game();
    cout << result << '\n';
    return 0;
}
