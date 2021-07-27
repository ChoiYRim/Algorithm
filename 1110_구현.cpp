#include <string>
#include <iostream>

using namespace std;

int N;
int cycle = 1;

int numberExtend(void)
{
    int n = N;
    string num = to_string(n);
    
    num = num + num;
    n = stoi(num);
    
    return n;
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int prev;
    string num = "";
    
    cin >> N;
    if(N < 10)
        N = numberExtend();
    
    prev = N;
    int ten = N/10;
    int one = N%10;
    N = (one*10) + ((ten+one)%10);
    
    while(N != prev)
    {
        ten = N/10;
        one = N%10;
        N = (one*10) + ((ten+one)%10);
        cycle++;
    }
    
    cout << cycle << '\n';
    return 0;
}
