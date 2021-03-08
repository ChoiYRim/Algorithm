#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
double result = 0;
double num[10001];

int main(int argc, const char * argv[])
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%lf", &num[i]);
    
    result = num[0];
    for(int i = 1; i < N; i++)
    {
        num[i] = max(num[i], num[i]*num[i-1]);
        result = max(result,num[i]);
    }
    
    printf("%.3lf\n", result);
    return 0;
}
