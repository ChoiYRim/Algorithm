#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m,result = 0;
vector<vector<int> > map;
vector<vector<pair<int,int>> > figure; // [height][width]

void make_figures(void)
{
    vector<pair<int,int> > temp; // [y][x]
    
    temp.push_back({0,0});
    temp.push_back({0,1});
    temp.push_back({0,2});
    temp.push_back({0,3});
    figure.push_back(temp);
    
    // 1
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {2,0};
    temp[3] = {3,0};
    figure.push_back(temp);
    
    // 2
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {2,0};
    temp[3] = {3,0};
    figure.push_back(temp);
    
    // 3
    temp[0] = {0,0};
    temp[1] = {0,1};
    temp[2] = {1,0};
    temp[3] = {1,1};
    figure.push_back(temp);
    
    // 4
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {2,0};
    temp[3] = {2,1};
    figure.push_back(temp);
    
    // 5
    temp[0] = {0,0};
    temp[1] = {0,1};
    temp[2] = {1,1};
    temp[3] = {2,1};
    figure.push_back(temp);
    
    // 6
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {1,1};
    temp[3] = {1,2};
    figure.push_back(temp);
    
    // 7
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {1,1};
    temp[3] = {2,1};
    figure.push_back(temp);
    
    // 8
    temp[0] = {0,0};
    temp[1] = {0,1};
    temp[2] = {1,0};
    temp[3] = {1,-1};
    figure.push_back(temp);
    
    // 9
    temp[0] = {0,0};
    temp[1] = {0,1};
    temp[2] = {1,1};
    temp[3] = {0,2};
    figure.push_back(temp);
    
    // 10
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {1,1};
    temp[3] = {2,0};
    figure.push_back(temp);
    
    // 11
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {1,-1};
    temp[3] = {2,0};
    figure.push_back(temp);
    
    // 12
    temp[0] = {0,0};
    temp[1] = {0,1};
    temp[2] = {0,2};
    temp[3] = {1,2};
    figure.push_back(temp);
    
    // 13
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {1,-1};
    temp[3] = {1,1};
    figure.push_back(temp);
    
    // 14
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {2,0};
    temp[3] = {2,-1};
    figure.push_back(temp);
    
    // 15
    temp[0] = {0,0};
    temp[1] = {0,1};
    temp[2] = {1,0};
    temp[3] = {2,0};
    figure.push_back(temp);
    
    // 16
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {1,-1};
    temp[3] = {1,-2};
    figure.push_back(temp);
    
    // 17
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {0,1};
    temp[3] = {0,2};
    figure.push_back(temp);
    
    // 18
    temp[0] = {0,0};
    temp[1] = {1,0};
    temp[2] = {1,-1};
    temp[3] = {2,-1};
    figure.push_back(temp);
    
    // 19
    temp[0] = {0,0};
    temp[1] = {0,1};
    temp[2] = {1,1};
    temp[3] = {1,2};
    figure.push_back(temp);
}

void check(int fig,int y,int x)
{
    int temp = 0,next_x,next_y;

    for(int i = 0; i < figure[fig].size(); i++)
    {
        next_x = x+figure[fig][i].second;
        next_y = y+figure[fig][i].first;
        
        if((0 <= next_x) && (next_x < m) && (0 <= next_y) && (next_y < n))
        {
            temp += map[next_y][next_x];
        }
        else
            return;
    }
    
    //cout << "temp : " << temp << endl;
    result = max(result,temp);
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        vector<int> row;
        
        for(int j = 0; j < m; j++)
        {
            int temp;
            
            cin >> temp;
            row.push_back(temp);
        }
        map.push_back(row);
    }
    
    make_figures();
    
    for(int i = 0; i < figure.size(); i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                check(i,j,k);
            }
        }
        //cout << "result of fig " << i << " : " << result << endl;
    }
    
    cout << result << '\n';
    return 0;
}
