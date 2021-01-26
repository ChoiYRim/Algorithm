/*
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M,K;
int maximum = -1;

// dp[k][i][j] : k번째 서로 다른 i와 j를 교체했을 때의 값
int dp[16][8][8];

string getNumber(void)
{
    string str = "";
    int num = N;
    
    while(num > 0)
    {
        int remainder = num%10;
        str += to_string(remainder);
        num /= 10;
    }
    reverse(str.begin(),str.end());
    return str;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    bool visit[1000001] = {0,};
    cin >> N >> K;
    
    string num = getNumber();
    if(N < 10 && (num.length() == 2 && N % 10 == 0))
    {
        cout << -1 << endl;
        return 0;
    }
    
    int len = (int)num.length();
    for(int k = 1; k <= K; k++)
    {
        for(int i = 0; i < len; i++)
        {
            dp[k][i][i] = -1;
            for(int j = i+1; j < len; j++)
            {
                if(i == 0 && num[j] == '0')
                    dp[k][i][j] = -1;
                else
                {
                    swap(num[i],num[j]);
                    int temp = stoi(num);
                    if(!visit[temp])
                    {
                        dp[k][i][j] = temp;
                    }
                    else
                    {
                        dp[k][i][j] = -1;
                    }
                    swap(num[i],num[j]);
                }
            }
        }
    }
    
    for(int i = 0; i < len; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            maximum = max(maximum,dp[K][i][j]);
        }
    }
    
    cout << maximum << endl;
    return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int N,M,K;
int result = -1;

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int loop = 0;
    
    cin >> N >> K;
    string num = to_string(N);
    if(N < 10 && (N % 10 == 0 && num.length() == 2))
    {
        cout << -1 << endl;
        return 0;
    }
    
    queue<int> q;
    bool visit[1000001] = {0,};

    q.push(N);
    visit[N] = true;
    while(!q.empty())
    {
        int qsize = (int)q.size();
        int len = (int)num.length();
        
        memset((bool *)visit,0,sizeof(visit));
        loop++;
        for(int s = 0; s < qsize; s++)
        {
            int cur = q.front();
            string num = to_string(cur);
            q.pop();

            for(int i = 0; i < len; i++)
            {
                for(int j = i+1; j < len; j++)
                {
                    char c = num[j];
                    if(!(i == 0 && c == '0'))
                    {
                        swap(num[i],num[j]);
                        int inum = stoi(num);
                        if(!visit[inum])
                        {
                            q.push(inum);
                            visit[inum] = true;
                            if(loop == K)
                                result = max(result,inum);
                        }
                        swap(num[i],num[j]);
                    }
                }
            }
        }
        if(loop == K)
            break;
    }
    
    cout << result << '\n';
    return 0;
}
