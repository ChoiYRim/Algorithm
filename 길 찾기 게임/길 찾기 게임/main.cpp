#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int x;
    int y;
    int index;
    Node *left;
    Node *right;
};

Node *root;
int vsize = 0;
vector<Node> ns;

void print_vector(vector<vector<int>> v)
{
    for(int i = 0; i < (int)v.size(); i++)
    {
        cout << "Vector[" << i << "] : ";
        for(int j = 0; j < (int)v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}

void preorder(vector<int> &a,Node *cur)
{
    if(!cur)
        return;
    a.push_back(cur->index);
    if(cur->left)
        preorder(a,cur->left);
    if(cur->right)
        preorder(a,cur->right);
}

void postorder(vector<int> &a,Node *cur)
{
    if(!cur)
        return;
    if(cur->left)
        postorder(a,cur->left);
    if(cur->right)
        postorder(a,cur->right);
    a.push_back(cur->index);
}

bool comp(const Node& n1,const Node& n2)
{
    if(n1.y == n2.y)
        return (n1.x < n2.x);
    return (n1.y > n2.y);
}

void alloc(Node *&cur,Node item)
{
    cur = new Node();
    cur->x = item.x;
    cur->y = item.y;
    cur->index = item.index;
    cur->left = cur->right = NULL;
}

void insert(Node *&cur,Node &node)
{
    if(!cur)
    {
        alloc(cur,node);
        return;
    }
    
    if(cur->y > node.y)
    {
        if(cur->x > node.x)
            insert(cur->left,node);
        else
            insert(cur->right,node);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    Node node;
    int len,x,y;
    vector<vector<int>> answer;
    vector<int> a1,a2;
    
    len = (int)nodeinfo.size();
    if(!len)
        return answer;
    
    for(int i = 0; i < len; i++)
    {
        x = nodeinfo[i][0];
        y = nodeinfo[i][1];
        node = {x,y,i+1,NULL,NULL};
        ns.push_back(node);
    }
    
    sort(ns.begin(),ns.end(),comp);
    vsize = (int)ns.size();
    root = &ns[0];
    for(int i = 1; i < vsize; i++)
        insert(root,ns[i]);
    preorder(a1,root);
    postorder(a2,root);
    answer.push_back(a1);
    answer.push_back(a2);
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<int>> nodeinfo = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
    vector<vector<int>> result = solution(nodeinfo);
    
    print_vector(result);
    return 0;
}
