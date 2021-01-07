/*
    작성자 : ChoiYRim
    프로그램 : Trie Tree
    Version : 1.0 ( insert() , treePrint() 테스트 완료 )
*/

#include <string>
#include <vector>
#include <iostream>

typedef struct _alphaTrieNode
{
private:
    char ch;
    int depth;
    int numChild;
    bool isRoot;
    int last; // 마지막 자식의 인덱스
    bool isLast; // 현재 노드가 현재 노드의 부모의 마지막 자식인가?
    
    struct _alphaTrieNode* parent;
    struct _alphaTrieNode* child[26];
    
public:
    _alphaTrieNode() // for root
    {
        this->depth = 0;
        this->numChild = 0;
        this->isRoot = true;
        this->parent = NULL;
        this->last = -1;
        this->isLast = false;
        
        for(int i = 0; i < 26; i++)
            this->child[i] = NULL;
    }
    _alphaTrieNode(int depth)
    {
        this->depth = depth;
        this->numChild = 0;
        this->isRoot = false;
        this->parent = NULL;
        this->last = -1;
        this->isLast = false;
        
        for(int i = 0; i < 26; i++)
            this->child[i] = NULL;
    }
    ~_alphaTrieNode()
    {
        for(int i = 0; i < 26; i++)
        {
            if(this->child[i] != NULL)
            {
                delete this->child[i]; // delete -> 소멸자 호출 즉, 자식의 자식들까지 모두 정리 (?)
            }
        }
    }
    struct _alphaTrieNode** getChildren(void)
    {
        return this->child;
    }
    bool isNodeLast(void)
    {
        return this->isLast;
    }
    void connectWithParent(struct _alphaTrieNode* node)
    {
        this->parent = node;
    }
    void setLastNode(bool tf)
    {
        this->isLast = tf;
    }
    void setCharacter(char ch)
    {
        this->ch = ch;
    }
    void insert(std::string str)
    {
        char c;
        
        if(str.length() <= 0)
            return;
        
        c = std::tolower(str[0]);
        int order = c - 'a';
        
        if(this->isRoot) // root
        {
            if(child[order] == NULL)
            {
                if(order > this->last)
                {
                    if(this->last != -1)
                        child[this->last]->isLast = false;
                    this->last = order;
                }
                this->numChild++;
                child[order] = new _alphaTrieNode(this->depth+1);
                if(order == this->last)
                    child[order]->setLastNode(true);
                child[order]->connectWithParent(this);
                child[order]->setCharacter(c);
            }
            std::string newStr = str.substr(1,str.length());
            child[order]->insert(newStr);
        }
        else // not root
        {
            std::string newStr;
            newStr = str.substr(1,str.length());
            if(child[order] == NULL)
            {
                if(order > this->last)
                {
                    if(this->last != -1)
                        child[this->last]->isLast = false;
                    this->last = order;
                }
                this->numChild++;
                child[order] = new _alphaTrieNode(this->depth+1);
                if(order == this->last)
                    child[order]->setLastNode(true);
                child[order]->connectWithParent(this);
                child[order]->setCharacter(c);
            }
            child[order]->insert(newStr);
        }
        
        return;
    }
    struct _alphaTrieNode* getParent(void)
    {
        return this->parent;
    }
    char getCharacter(void)
    {
        return this->ch;
    }
    int getDepth(void)
    {
        return this->depth;
    }
    struct _alphaTrieNode* getLast(void)
    {
        if(this->last != -1)
            return this->child[this->last];
        return NULL;
    }
    int numberOfChildren(void)
    {
        return this->numChild;
    }
    char getCh(void)
    {
        return this->ch;
    }
    void erase(std::string str)
    {
        char c;
        int order;
        
        if(str.length() <= 0)
            return;
        
        c = std::tolower(str[0]);
        order = c-'a';
        
        if(this->child[order] && str.length() > 1)
        {
            std::string newStr = str.substr(1,str.length());
            if(newStr.length() == 1 && this->child[order]->numberOfChildren() == 0)
            {
                if(this->last == order)
                {
                    bool check = false;
                    for(int i = 0; i < last; i++)
                    {
                        if(this->child[i] != NULL)
                        {
                            check = true;
                            this->last = i;
                            break;
                        }
                    }
                    if(!check)
                        this->last = -1;
                }
                this->numChild--;
                delete this->child[order];
                return;
            }
            this->child[order]->erase(newStr);
        }
        return;
    }
    std::string makeTabs(struct _alphaTrieNode* root,struct _alphaTrieNode* start)
    {
        std::string result = "";
        int diff = start->getDepth() - root->getDepth();
        struct _alphaTrieNode* par, *cur;
        
        if(diff <= 0)
            return result;
        else if(diff == 1)
        {
            result = "   ";
            return result;
        }
        else // diff > 1
        {
            par = start->getParent();
            cur = start;
            
            while(par != root)
            {
                if(par->isNodeLast() == true)
                    result += 'x';
                else
                    result += 'o';
                
                cur = par;
                par = par->getParent();
            }
        }
        
        std::reverse(result.begin(),result.end());
        return result;
    }
    void printTabs(std::string tabs)
    {
        for(int i = 0; i < tabs.length(); i++)
        {
            if(tabs[i] == 'o')
                std::cout << "│  ";
            else if(tabs[i] == 'x')
                std::cout << "   ";
        }
    }
    void print(struct _alphaTrieNode* root,struct _alphaTrieNode* cur)
    {
        std::string tabs = makeTabs(root,cur);
        struct _alphaTrieNode* par = cur->getParent();
        struct _alphaTrieNode** child = cur->getChildren();
        
        printTabs(tabs);
        if(cur == root)
        {
            std::cout << "Root" << '\n';
        }
        else
        {
            if(cur == par->getLast())
                std::cout << "└──" << cur->getCh() << '\n';
            else
                std::cout << "├──" << cur->getCh() << '\n';
        }
        for(int i = 0; i < 26; i++)
        {
            if(child[i] != NULL)
            {
                print(root,child[i]);
            }
        }
    }
    void treePrint(struct _alphaTrieNode* root)
    {
        // ├──
        //
        // │
        //
        // └──
        
        if(root == NULL)
            return;
        
        print(root,root); // root부터 출력 시작
        return;
    }
}ATri;

int main(int argc, const char * argv[])
{
    int n;
    std::vector<std::string> strs;
    
    std::cout << "Trie Test" << '\n';
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string temp;
        std::cin >> temp;
        strs.push_back(temp);
    }
    
    ATri* root = new ATri;
    
    for(int i = 0; i < n; i++)
        root->insert(strs[i]);
    
    root->treePrint(root);
    
    return 0;
}
