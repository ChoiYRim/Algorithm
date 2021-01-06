#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void print_answer(vector<int> answer)
{
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}

void make_dictionary(map<string,int>& dict)
{
    int num = 1;
    char alpha;
    
    for(alpha = 'A'; alpha <= 'Z'; alpha++)
    {
        char temp[4] = {0,};
        temp[0] = alpha;
        
        dict.insert(make_pair(temp,num));
        num++;
    }
}

vector<int> solution(string msg)
{
    int num;
    int last = 26;
    map<string,int> dict;
    vector<int> answer;
   
    make_dictionary(dict); // make an initial dictionary
   
    for(int i = 0; i < msg.size(); i++)
    {
        int new_num;
        string cur;
        
        for(int j = i; j < msg.size(); j++)
        {
            cur += msg[j];
            if(dict.find(cur) == dict.end()) // not exists
            {
                last++;
                new_num = last;
                dict.insert(make_pair(cur,new_num));
                cur.clear();
                answer.push_back(num);
                i = j-1;
                break;
            }
            else
            {
                num = dict.find(cur)->second;
                if(j+1 >= msg.size())
                {
                    i = j;
                    answer.push_back(num);
                    break;
                }
            }
            
        }
    }
        
    return answer;
}

int main(int argc, const char * argv[])
{
    vector<int> ans = solution("ABABABABABABABAB");
    
    return 0;
}
