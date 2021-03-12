#include<iostream>
#include<cstring>

using namespace std;

pair<int, int> recur(char input[], int curr)
{
    int cnt=0;
    int i;

    for(i = curr; i >= 0; i--)
    {
        if(input[i] == '(')
            break;

        else if(input[i] == ')')
        {
            pair<int, int> result = recur(input, i-1); //괄호 안에 있는 갯수
            i = result.first;
            cnt += (input[i]-'0')*(result.second);
        }
        else
            cnt++;
    }

    return make_pair(i-1, cnt);
}

int main(void)
{
    char input[64] = {0,};
    
    cin >> input;
    cout << recur(input,(int)strlen(input)-1).second << endl;
    
    return 0;
}


// reference : https://kswims.tistory.com/1
