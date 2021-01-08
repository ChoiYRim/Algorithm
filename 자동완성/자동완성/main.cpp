// [Reference] : https://yabmoons.tistory.com/490
// 시간 초과 문제로 타인 코드 참조

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N,L;

struct Trie
{
    Trie *child[26];
    int numString;
    bool isLast;
    
    void insert(const char *str);
    int find(const char *str,int count);
};

int numTrie = 0;
Trie nodes[1000001];

Trie *createTrie()
{
    Trie *newNode = &nodes[numTrie++];
    
    newNode->numString = 0;
    newNode->isLast = false;
    
    for(int i = 0; i < 26; i++)
        newNode->child[i] = NULL;
    
    return newNode;
}

void Trie::insert(const char *str)
{
    numString++;
    
    if(*str == 0)
    {
        isLast = true;
        return;
    }
    
    int idx = str[0]-'a';
    
    if(child[idx] == NULL)
        child[idx] = createTrie();
    child[idx]->insert(str+1);
}

int Trie::find(const char *str,int count)
{
    if(*str == 0 || numString == 1)
        return count;
    
    int idx = str[0]-'a';
    
    if(child[idx])
        return child[idx]->find(str+1,count+1);
    return 0;
}

int solution(vector<string> words)
{
    int answer = 0;
    Trie *root = createTrie();
    
    for(string word : words)
    {
        root->insert(word.c_str());
    }
    
    for(string word : words)
    {
        answer += root->find(word.c_str(),0);
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
