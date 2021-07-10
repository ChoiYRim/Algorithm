#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
string input = "";
vector<string> sig;
vector<vector<string>> numbers;

void make_numbers(void)
{
    vector<string> nums;
    string num = "";
    
    // 0
    num = "###";
    nums.push_back(num);
    num = "#.#";
    nums.push_back(num);
    num = "#.#";
    nums.push_back(num);
    num = "#.#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
    
    // 1
    num = "#..";
    nums.push_back(num);
    num = "#..";
    nums.push_back(num);
    num = "#..";
    nums.push_back(num);
    num = "#..";
    nums.push_back(num);
    num = "#..";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
    
    // 2
    num = "###";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    num = "#..";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
    
    // 3
    num = "###";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
    
    // 4
    num = "#.#";
    nums.push_back(num);
    num = "#.#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
    
    // 5
    num = "###";
    nums.push_back(num);
    num = "#..";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
    
    // 6
    num = "###";
    nums.push_back(num);
    num = "#..";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    num = "#.#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
    
    // 7
    num = "###";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
    
    // 8
    num = "###";
    nums.push_back(num);
    num = "#.#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    num = "#.#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
    
    // 9
    num = "###";
    nums.push_back(num);
    num = "#.#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    num = "..#";
    nums.push_back(num);
    num = "###";
    nums.push_back(num);
    numbers.push_back(nums);
    nums.clear();
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int split = 0;
    string result = "";
    
    cin >> N;
    cin >> input;
    for(int i = 0; i < 5; i++)
    {
        string temp = "";
        temp = input.substr(split,N/5);
        sig.push_back(temp);
        split += N/5;
    }
    
    make_numbers();
    for(int i = 0; i < (int)(N/5); i++) // column
    {
        if(sig[0][i] == '.')
            continue;
        if(i+1 >= N/5 || (i+1 < (int)(N/5) && sig[0][i+1] == '.')) // 1 , 4 ??
        {
            if(i+1 < (int)(N/5))
            {
                bool check = false;
                for(int j = 1; j < 5; j++)
                {
                    if(sig[j][i+1] != '.')
                    {
                        check = true;
                        result += "4";
                        i += 2;
                        break;
                    }
                }
                if(!check)
                    result += "1";
            }
            else
                result += "1";
        }
        else
        {
            vector<bool> check = {1,0,1,1,1,1,1,1,1,1};
            
            for(int j = 0; j < 5; j++)
            {
                string temp = "";
                for(int col = i; col < i+3; col++)
                    temp += sig[j][col];
                for(int number = 0; number < 10; number++)
                {
                    if(!check[number])
                        continue;
                    if(temp != numbers[number][j])
                        check[number] = 0;
                }
            }
            for(int j = 0; j < 10; j++)
            {
                if(check[j])
                {
                    result += to_string(j);
                    break;
                }
            }
            i += 2;
        }
    }
    
    cout << result << '\n';
    return 0;
}
