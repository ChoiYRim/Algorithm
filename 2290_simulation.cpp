#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int S;
long long N;
vector<vector<string>> numbers;

void get_numbers(long long n,vector<int>& print)
{
    while(n > 0)
    {
        int num = (int)(n%10);
        print.push_back(num);
        n /= 10;
    }
    
    reverse(print.begin(),print.end());
}

void make_numbers(int s,int w,int h)
{
    string str = "";
    numbers = vector<vector<string>>(10,vector<string>());
    
    for(int row = 0; row < h; row++)
    {
        for(int col = 0; col < w; col++)
        {
            if(row != 0 && row != h-1 && row != h/2) // not starting point , middle point , end point
            {
                if(col != 0 && col != w-1)
                {
                    for(int i = 0; i < 10; i++)
                        numbers[i].push_back(" ");
                }
                else
                {
                    for(int i = 0; i < 10; i++)
                    {
                        if(i == 0 || i == 8)
                            numbers[i].push_back("|");
                        else if((i == 1 || i == 3) && col == w-1)
                            numbers[i].push_back("|");
                        else if(i == 2 && ((col == w-1 && row < h/2) || (col == 0 && row > h/2)))
                            numbers[i].push_back("|");
                        else if(i == 4 && ((row < h/2) || (row > h/2 && col == w-1)))
                            numbers[i].push_back("|");
                        else if(i == 5 && ((row < h/2 && col == 0) || (row > h/2 && col == w-1)))
                            numbers[i].push_back("|");
                        else if(i == 6 && ((row < h/2 && col == 0) || (row > h/2)))
                            numbers[i].push_back("|");
                        else if(i == 7 && col == w-1)
                            numbers[i].push_back("|");
                        else if(i == 9 && (row < h/2 || (row > h/2 && col == w-1)))
                            numbers[i].push_back("|");
                        else
                            numbers[i].push_back(" ");
                        
                    }
                }
            }
            else
            {
                if(col != 0 && col != w-1)
                {
                    for(int i = 0; i < 10; i++)
                    {
                        if(row == 0)
                        {
                            if(i != 1 && i != 4)
                                numbers[i].push_back("-");
                            else
                                numbers[i].push_back(" ");
                        }
                        else if(row == h/2)
                        {
                            if(i != 0 && i != 1 && i != 7)
                                numbers[i].push_back("-");
                            else
                                numbers[i].push_back(" ");
                        }
                        else
                        {
                            if(i != 1 && i != 4 && i != 7)
                                numbers[i].push_back("-");
                            else
                                numbers[i].push_back(" ");
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < 10; i++)
                        numbers[i].push_back(" ");
                }
            }
        }
    }
}

void print_numbers(int s,vector<int> print)
{
    if(numbers.size() <= 0)
        return;
    
    int width = s+2,height = s*2+3,col = 0;
    
    for(int row = 0; row < height; row++)
    {
        for(int i = 0; i < (int)print.size(); i++)
        {
            int cur = print[i];
            int col_save = col;
            
            for(int j = 0; j < width; j++)
                cout << numbers[cur][col_save++];
            cout << " ";
        }
        col += width;
        cout << '\n';
    }
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int width,height;
    vector<int> print;
    
    cin >> S >> N;
    
    width = S+2;
    height = 2*S+3;
    get_numbers(N,print);
    make_numbers(S,width,height);
    
    print_numbers(S,print);
    return 0;
}
