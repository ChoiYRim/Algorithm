#include <stdio.h>

int N; // 어떤 생성자 X의 분해합이 N임

// 245의 분해합은 245+2+4+5 = 256이므로 245는 256의 생성자

int main(void)
{
    scanf("%d", &N);
    for(int i = 1; i < N; i++)
    {
        int num = i;
        int sum = num;
        
        while(num > 0)
        {
            sum += (num%10);
            num /= 10;
        }
        
        if(sum == N)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
