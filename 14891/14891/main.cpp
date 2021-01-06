#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int k,result = 0;
char cogwheel[5][16];
vector<pair<int,int> > roll;

void print_cogwheel(void)
{
    printf("Printing Cogwheel\n");
    for(int i = 1; i <= 4; i++)
    {
        printf("%s\n", cogwheel[i]);
    }
    printf("\n");
}

void rotate(char *cw,int turn) // 톱니바퀴 회전
{
    char temp;
    
    if(turn == 1) // clockwise
    {
        temp = cw[7];
        for(int i = 7; i > 0; i--)
        {
            cw[i] = cw[i-1];
        }
        cw[0] = temp;
    }
    else // counter clockwise -1
    {
        temp = cw[0];
        for(int i = 0; i < 7; i++)
        {
            cw[i] = cw[i+1];
        }
        cw[7] = temp;
    }
}

int main(int argc, const char * argv[])
{
    int temp = 1;
    
    memset((int *)cogwheel,0,sizeof(cogwheel));
    for(int i = 1; i <= 4; i++)
    {
        scanf("%s", cogwheel[i]);
    }
    
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int cw,dir;
        cin >> cw >> dir;
        roll.push_back({cw,dir});
    }
    
    for(int i = 0; i < roll.size(); i++)
    {
        int cw,dir;
        char left,right;
        
        cw = roll[i].first;
        dir = roll[i].second;
        left = cogwheel[cw][6];
        right = cogwheel[cw][2];
        
        rotate(cogwheel[cw],dir);
        
        int temp = dir;
        for(int j = cw-1; j > 0; j--) // left sides
        {
            if(cogwheel[j][2] != left)
            {
                int reverse = (temp == 1 ? -1 : 1);
                left = cogwheel[j][6];
                rotate(cogwheel[j],reverse);
                temp = reverse;
            }
            else
                break;
        }
        
        temp = dir;
        for(int j = cw+1; j <= 4; j++)
        {
            if(cogwheel[j][6] != right)
            {
                int reverse = (temp == 1 ? -1 : 1);
                right = cogwheel[j][2];
                rotate(cogwheel[j],reverse);
                temp = reverse;
            }
            else
                break;
        }
    }
    
    for(int i = 1; i <= 4; i++)
    {
        if(cogwheel[i][0] == '1')
        {
            result += temp;
        }
        temp *= 2;
    }
    
    cout << result << endl;
    return 0;
}
