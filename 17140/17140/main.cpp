#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int t = 0;
int r,c,k;
int map[102][102];

void print_map(int size_r,int size_c)
{
    for(int i = 1; i <= size_r; i++)
    {
        for(int j = 1; j <= size_c; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

bool sortNumber(pair<int,int>& a,pair<int,int>& b)
{
    if(a.second < b.second)
        return true;
    else if(a.second == b.second)
        if(a.first < b.first)
            return true;
    return false;
}

void rowSort(int *size_r,int *size_c)
{
    int m = -1;
    pair<int,int> count[101];
    
    for(int i = 1; i <= *size_r; i++)
    {
        int col = 1;
        
        for(int j = 0; j <= 100; j++)
        {
            count[j].first = j;
            count[j].second = 0;
        }
        
        for(int j = 1; j <= *size_c; j++)
        {
            count[map[i][j]].second++;
        }
                
        /*
        for(int j = 1; j <= 100; j++)
        {
            int temp = count[j].second;
            
            if(temp > 0)
                count[temp].second++;
        }
        */
        
        sort(count,count+101,sortNumber);
        
        for(int j = 0; j <= 100; j++)
        {
            int temp = count[j].second;
            
            if(count[j].first != 0 && temp > 0)
            {
                map[i][col++] = count[j].first;
                map[i][col++] = temp;
            }
        }
        for(int j = col; j <= 100; j++)
        {
            map[i][j] = 0;
        }
        
        if(m < col-1)
            m = col-1;
    }
    *size_c = m;
}

void transpose(int new_map[102][102],int size_r,int size_c)
{
    // 전치행렬 만들기
    for(int mr = 1; mr <= size_r; mr++)
        for(int mc = 1; mc <= size_c; mc++)
            new_map[mc][mr] = map[mr][mc];
}

int main(int argc, const char * argv[])
{
    int size_r,size_c;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> map[i][j];
        }
    }
    
    size_r = size_c = 3;
    
    while(t <= 100)
    {
        if(map[r][c] == k)
        {
            cout << t << '\n';
            return 0;
        }

        if(size_r >= size_c)
        {
            rowSort(&size_r,&size_c);
        }
        else
        {
            int temp = size_c;
            int new_map[102][102];
            
            memset((int *)new_map,0,sizeof(new_map));
            transpose(new_map,size_r,size_c);
            memcpy((int *)map,(int *)new_map,sizeof(map));
            
            size_c = size_r;
            size_r = temp;
            
            rowSort(&size_r,&size_c);
            
            memset((int *)new_map,0,sizeof(new_map));
            transpose(new_map,size_r,size_c);
            memcpy((int *)map,(int *)new_map,sizeof(map));
            
            temp = size_c;
            size_c = size_r;
            size_r = temp;
        }
        
        //print_map(size_r,size_c);
        t++;
    }
    
    cout << -1 << '\n';
    return 0;
}
