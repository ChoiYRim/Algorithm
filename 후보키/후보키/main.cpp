#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int rsize = 0;
int csize = 0;
vector<vector<string>> db;

inline bool comp(int &a,int &b) { return a < b; }

// 유일성 만족 검사
bool checkExclusiveness(int bit)
{
    if(!bit) // 000...0은 불가
        return false;
    
    for(int i = 0; i < rsize-1; i++)
    {
        for(int j = i+1; j < rsize; j++)
        {
            bool check = false;
            
            for(int k = 0; k < csize; k++)
            {
                if((bit & (1<<k)) == 0)
                    continue;
                if(db[i][k] != db[j][k])
                {
                    check = true;
                    break;
                }
            }
            if(!check)
                return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;
    vector<int> bits;
    
    db = relation;
    rsize = (int)relation.size(); // row 개수
    csize = (int)relation.front().size(); // column 개수
    
    for(int i = 0; i < (1 << csize); i++)
    {
        // 유일성 만족 여부 검사
        if(checkExclusiveness(i))
            bits.push_back(i);
    }
    
    // 최소성 만족 여부 검사
    sort(bits.begin(),bits.end(),comp);
    
    for(int i = 0; i < (int)bits.size(); i++)
    {
        bool check = false;
        int pivot = bits[i];
        
        for(int j = i+1; j < (int)bits.size(); )
        {
            int comp = bits[j];
            
            if((pivot & comp) == pivot) // 최소성 검사 핵심
                check = true;
            if(check)
            {
                bits.erase(bits.begin()+j);
                check = false;
            }
            else
            {
                j++;
            }
        }
    }
    
    answer = (int)bits.size();
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<string>> relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    
    cout << solution(relation) << '\n';
    return 0;
}
