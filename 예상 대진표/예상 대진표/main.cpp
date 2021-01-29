#include <iostream>
#include <algorithm>

#define ISEVEN(x) (x % 2 == 0 ? x / 2 : x / 2 + 1)

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int left,right;
    
    if(a > b)
    {
        left = b;
        right = a;
    }
    else
    {
        left = a;
        right = b;
    }

    while(left < right)
    {
        left = ISEVEN(left);
        right = ISEVEN(right);
        answer ++;
    }
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 8,a = 4,b = 7;
    
    cout << solution(n,a,b) << '\n';
    return 0;
}
