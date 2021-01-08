#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,L;

struct Trie
{
    Trie *child[26];
    int depth;
    int numString;
    char ch;
    bool isRoot;
    bool isLast;
    
    Trie(char ch,int depth,bool isRoot) // Constructor
    {
        this->numString = 0;
        this->depth = depth;
        this->ch = ch;
        this->isRoot = isRoot;
        this->isLast = false;
        
        for(int i = 0; i < 26; i++)
        {
            this->child[i] = NULL;
        }
    }
    
    void insert(string str)
    {
        this->numString++;
        
        if(str.length() <= 0)
            return;
        
        char c = str[0];
        int idx = c-'a';
        
        if(this->child[idx])
        {
            string newStr = str.substr(1,str.length());
            this->child[idx]->insert(newStr);
        }
        else
        {
            this->child[idx] = new Trie(c,this->depth+1,false);
            
            string newStr = str.substr(1,str.length());
            if(newStr.length() > 0)
                this->child[idx]->insert(newStr);
            else
                this->child[idx]->isLast = true;
        }
    }
    
    int find(string str,int count)
    {
        if(str.length() <= 0 || (this->numString == 1 && !(this->isLast) && str.length() > 0))
            return count;
        
        char c = str[0];
        int idx = c-'a';
        string newStr = str.substr(1,str.length());
        
        if(this->child[idx])
            return this->child[idx]->find(newStr,count+1);
        return 0;
    }
};

int solution(vector<string> words)
{
    int answer = 0;
    Trie *root = new Trie(' ',0,true);
    
    for(string word : words)
        root->insert(word);
    
    for(string word : words)
    {
        answer += root->find(word,0);
        //cout << "Answer : " << answer << endl;
    }
    
    return answer;
}

int main(int argc,const char *argv[])
{
    vector<string> words;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> L;
    for(int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        words.push_back(word);
    }
    
    cout << solution(words) << '\n';
    return 0;
}
