#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct _
{
    int x;
    int d;
    int k;
}Rot;

int n,m,t;
int sum = 0;
vector<Rot> rot;
vector<deque<int>> circle;

void getSum(void)
{
    sum = 0;
    for(int i = 0; i < circle.size(); i++)
    {
        for(int j = 0; j < circle[i].size(); j++)
        {
            sum += circle[i][j];
        }
    }
}

int getCount(void)
{
    int count = 0;
    for(int i = 0; i < circle.size(); i++)
    {
        for(int j = 0; j < circle[i].size(); j++)
        {
            if(circle[i][j] > 0)
                count++;
        }
    }
    
    return count;
}

void modifyCircle(double avg)
{
    for(int i = 0; i < circle.size(); i++)
    {
        for(int j = 0; j < circle[i].size(); j++)
        {
            if(circle[i][j] > 0)
            {
                if((double)circle[i][j] > avg)
                    circle[i][j] -= 1;
                else if((double)circle[i][j] < avg)
                    circle[i][j] += 1;
            }
        }
    }
}

bool calculateAdjoin(void)
{
    bool check = false;
    vector<pair<int,int>> pos;
    
    for(int i = 0; i < circle.size(); i++)
    {
        for(int j = 0; j < circle[i].size(); j++)
        {
            if(circle[i][j] > 0)
            {
                if(i == 0)
                {
                    if(circle[i][j] == circle[i+1][j])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i+1,j});
                        //circle[i][j] = circle[i+1][j] = 0;
                    }
                }
                else if(i > 0 && i < n-1)
                {
                    if(circle[i][j] == circle[i+1][j])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i+1,j});
                        //circle[i][j] = circle[i+1][j] = 0;
                    }
                    if(circle[i][j] == circle[i-1][j])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i-1,j});
                        //circle[i][j] = circle[i-1][j] = 0;
                    }
                }
                else
                {
                    if(circle[i][j] == circle[i-1][j])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i-1,j});
                        //circle[i][j] = circle[i-1][j] = 0;
                    }
                }
                
                if(j == 0)
                {
                    if(circle[i][j] == circle[i][j+1])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i,j+1});
                        //circle[i][j] = circle[i][j+1] = 0;
                    }
                    if(circle[i][j] == circle[i][m-1])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i,m-1});
                        //circle[i][j] = circle[i][m-1] = 0;
                    }
                }
                else if(j > 0 && j < m-1)
                {
                    if(circle[i][j] == circle[i][j+1])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i,j+1});
                        //circle[i][j] = circle[i][j+1] = 0;
                    }
                    if(circle[i][j] == circle[i][j-1])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i,j-1});
                        //circle[i][j] = circle[i][j-1] = 0;
                    }
                }
                else
                {
                    if(circle[i][j] == circle[i][0])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i,0});
                        //circle[i][j] = circle[i][0] = 0;
                    }
                    if(circle[i][j] == circle[i][j-1])
                    {
                        check = true;
                        pos.push_back({i,j});
                        pos.push_back({i,j-1});
                        //circle[i][j] = circle[i][j-1] = 0;
                    }
                }
            }
        }
    }
    
    if(check)
    {
        for(int i = 0; i < pos.size(); i++)
        {
            int x = pos[i].first;
            int y = pos[i].second;
            circle[x][y] = 0;
        }
    }
    
    return check;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++)
    {
        deque<int> de;
        for(int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            de.push_back(temp);
        }
        circle.push_back(de);
    }
    
    for(int i = 0; i < t; i++)
    {
        int x,d,k;
        cin >> x >> d >> k;
        rot.push_back({x,d,k});
    }
    
    for(int i = 0; i < rot.size(); i++)
    {
        int x,d,k;
        
        x = rot[i].x;
        d = rot[i].d;
        k = rot[i].k;
        
        for(int j = 1; x*j-1 < circle.size(); j++)
        {
            int idx = x*j-1;
            int temp;
            
            for(int a = 0; a < k; a++)
            {
                if(d == 0) // clockwise
                {
                    temp = circle[idx].back();
                    circle[idx].pop_back();
                    circle[idx].push_front(temp);
                }
                else // counter clockwise
                {
                    temp = circle[idx].front();
                    circle[idx].pop_front();
                    circle[idx].push_back(temp);
                }
            }
        }
        
        if(!calculateAdjoin())
        {
            int count = getCount();
            if(count > 0)
            {
                getSum();
                double avg = (double)sum / count;
                modifyCircle(avg);
            }
        }
    }
    
    getSum();
    cout << sum << '\n';
    return 0;
}
