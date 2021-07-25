#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N,M,K;
vector<int> result;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
bool Map[100][100] = {0,};

//void printArea(void)
//{
//    for(int i = 0; i < M; i++)
//    {
//        for(int j = 0; j < N; j++)
//        {
//            cout << Map[i][j] << " ";
//        }
//        cout << '\n';
//    }
//}

void paintArea(int x1,int y1,int x2,int y2)
{
    for(int y = y1; y < y2; y++)
    {
        for(int x = x1; x < x2; x++)
        {
            Map[y][x] = true;
        }
    }
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<pair<pair<int,int>,pair<int,int>>> input;
    
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        input.push_back({{x1,y1},{x2,y2}});
    }
    for(int i = 0; i < (int)input.size(); i++)
    {
        pair<int,int> one = input[i].first,two = input[i].second;
        paintArea(one.first, one.second, two.first, two.second);
    }
        
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(!Map[i][j])
            {
                int extent = 1;
                queue<pair<int,int>> q;
                
                q.push({i,j});
                Map[i][j] = true;
                while(!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    
                    for(int k = 0; k < 4; k++)
                    {
                        int ny = y+dy[k];
                        int nx = x+dx[k];
                        
                        if((nx >= 0 && nx < N) && (ny >= 0 && ny < M) && !Map[ny][nx])
                        {
                            Map[ny][nx] = true;
                            q.push({ny,nx});
                            extent++;
                        }
                    }
                }
                result.push_back(extent);
            }
        }
    }
    
    sort(result.begin(),result.end());
    cout << result.size() << '\n';
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i] << ' ';
    cout << '\n';
    return 0;
}
