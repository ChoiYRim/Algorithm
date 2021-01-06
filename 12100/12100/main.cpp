#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n,result = INT_MIN;
int bd[25][25]; // board

void move(int direct,int b[25][25])
{
	if(direct == 1) // east
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = n; j > 0; j--)
			{
				for(int k = n; k > 0; k--)
				{
					if(b[i][k] != 0 && b[i][k-1] == 0)
						continue;
					if(b[i][k] != 0 && b[i][k-1] != 0)
                        continue;
					b[i][k] = b[i][k-1];
                    b[i][k-1] = 0;
                }
			}
            for(int j = n; j > 0; j--)
            {
                if(b[i][j] == b[i][j-1])
                {
                    b[i][j] *= 2;
                    b[i][j-1] = 0;
                    for(int k = j-1; k > 0; k--)
                    {
                        b[i][k] = b[i][k-1];
                    }
                }
            }
		}
	}
	else if(direct == 2) // west
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				for(int k = 1; k <= n; k++)
				{
					if(b[i][k] != 0 && b[i][k+1] == 0)
						continue;
					if(b[i][k] != 0 && b[i][k+1] != 0)
						continue;
					b[i][k] = b[i][k+1];
					b[i][k+1] = 0;
				}
			}
            for(int j = 1; j <= n; j++)
            {
                if(b[i][j] == b[i][j+1])
                {
                    b[i][j] *= 2;
                    b[i][j+1] = 0;
                    for(int k = j+1; k <= n; k++)
                    {
                        b[i][k] = b[i][k+1];
                    }
                }
            }
		}
	}
	else if(direct == 3) // south
	{
        for(int i = 1; i <= n; i++)
        {
            for(int j = n; j > 0; j--)
            {
                for(int k = n; k > 0; k--)
                {
                    if(b[k][i] != 0 && b[k-1][i] == 0)
                        continue;
                    if(b[k][i] != 0 && b[k-1][i] != 0)
                        continue;
                    b[k][i] = b[k-1][i];
                    b[k-1][i] = 0;
                }
            }
            for(int j = n; j > 0; j--)
            {
                if(b[j][i] == b[j-1][i])
                {
                    b[j][i] *= 2;
                    for(int k = j-1; k > 0; k--)
                    {
                        b[k][i] = b[k-1][i];
                    }
                }
            }
        }
	}
	else // north
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				for(int k = 1; k <= n; k++)
				{
					if(b[k][i] != 0 && b[k+1][i] == 0)
						continue;
					if(b[k][i] != 0 && b[k+1][i] != 0)
						continue;
					b[k][i] = b[k+1][i];
					b[k+1][i] = 0;
				}
			}
            for(int j = 1; j <= n; j++)
            {
                if(b[j][i] == b[j+1][i])
                {
                    b[j][i] *= 2;
                    for(int k = j+1; k <= n; k++)
                    {
                        b[k][i] = b[k+1][i];
                    }
                }
            }
		}
	}
}

int find_max(int b[25][25])
{
    int maxi = INT_MIN;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            maxi = max(maxi,b[i][j]);
        }
    }
    
    return maxi;
}

void dfs(int depth,int ret,int arr[25][25])
{
    if(depth == 5)
    {
        result = max(result,ret);
        return;
    }
        
    for(int i = 1; i < 5; i++)
    {
        int board[25][25];
        
        memset((int *)board,0,sizeof(board));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                board[i][j] = arr[i][j];
            }
        }
        
        move(i,board);
    
        int temp = find_max(board);
        
        dfs(depth+1,temp,board);
    }
}

int main(int argc, const char * argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset((int *)bd,0,sizeof(bd));

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> bd[i][j];
		}
	}
        
    dfs(0,result,bd);
    cout << result << '\n';
	
    return 0;
}
