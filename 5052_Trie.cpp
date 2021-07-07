#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Trie
{
private:
    char c; // '0' ~ '9'
    Trie *child[10]; // 0 ~ 9
    
public:
    Trie(char ch)
    {
        c = ch;
        for(int i = 0; i < 10; i++)
            child[i] = NULL;
    }
    
    void insert(string num)
    {
        if(num.length() <= 0)
            return;
        
        for(int i = 0; i < 10; i++)
        {
            if(i == num[0]-'0')
            {
                if(!child[i])
                    child[i] = new Trie(i+'0');
                
                num.erase(0,1);
                child[i]->insert(num);
                break;
            }
        }
    }
    
    bool find(string num)
    {
        if(num.length() <= 0)
        {
            for(int i = 0; i < 10; i++)
                if(child[i])
                    return false;
            return true;
        }
        
        if(child[num[0]-'0'])
        {
            int idx = num[0]-'0';
            string next = num.erase(0,1);
            return child[idx]->find(next);
        }
        
        return false;
    }
    
    ~Trie()
    {
        for(int i = 0; i < 10; i++)
        {
            if(child[i] != NULL)
                delete child[i];
        }
    }
};

int TC,N;

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> TC;
    while(TC--)
    {
        Trie *root;
        bool check = true;
        vector<string> phone;
        
        root = new Trie(0);
        
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            string temp = "";
            cin >> temp;
            phone.push_back(temp);
            root->insert(temp);
        }
        
        for(int i = 0; i < N; i++)
        {
            if(!(root->find(phone[i])))
            {
                check = false;
                cout << "NO" << '\n';
                break;
            }
        }
        if(check)
            cout << "YES" << '\n';
        
        delete root;
    }
    
    return 0;
}
