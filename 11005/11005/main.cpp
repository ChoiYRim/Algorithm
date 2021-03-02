#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N,B;
string alpha[36];

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> B;
    
    string result = "";
    
    for(int i = 0; i < 10; i++)
        alpha[i] = to_string(i);
    for(int i = 10; i < 36; i++)
        alpha[i] = 'A'+(i-10);
    while(N > 0)
    {
        int num = N % B;
        N /= B;
        result += alpha[num];
    }
    reverse(result.begin(),result.end());
    
    cout << result << '\n';
    return 0;
}
