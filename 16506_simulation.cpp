#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Cmd
{
    string cmd;
    int rD;
    int rA;
    int rB;
};

int N;
vector<Cmd> v;
vector<string> result;
map<string,string> m;

void makeCommandList(void)
{
    m.insert({"ADD","00000"});
    m.insert({"ADDC","00001"});
    
    m.insert({"SUB","00010"});
    m.insert({"SUBC","00011"});

    m.insert({"MOV","00100"});
    m.insert({"MOVC","00101"});

    m.insert({"AND","00110"});
    m.insert({"ANDC","00111"});

    m.insert({"OR","01000"});
    m.insert({"ORC","01001"});

    m.insert({"NOT","01010"});
    
    m.insert({"MULT","01100"});
    m.insert({"MULTC","01101"});

    m.insert({"LSFTL","01110"});
    m.insert({"LSFTLC","01111"});

    m.insert({"LSFTR","10000"});
    m.insert({"LSFTRC","10001"});

    m.insert({"ASFTR","10010"});
    m.insert({"ASFTRC","10011"});

    m.insert({"RL","10100"});
    m.insert({"RLC","10101"});

    m.insert({"RR","10110"});
    m.insert({"RRC","10111"});
}

string convertCommand(int num,int len)
{
    string ret = "";
    
    while(num > 0)
    {
        ret += to_string(num%2);
        num /= 2;
    }
    while(ret.length() != len)
        ret += "0";
    reverse(ret.begin(),ret.end());
    
    return ret;
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    int a,b,c;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> str >> a >> b >> c;
        v.push_back({str,a,b,c});
    }
    
    makeCommandList();
    
    for(int i = 0; i < N; i++)
    {
        string str = "";
        map<string,string>::iterator it = m.find(v[i].cmd);
        int len = (int)v[i].cmd.length();
        
        str += (it->second + "0");
        str += convertCommand(v[i].rD,3);
        str += convertCommand(v[i].rA,3);
        if(v[i].cmd[len-1] != 'C')
        {
            str += convertCommand(v[i].rB,3);
            str += "0";
        }
        else
            str += convertCommand(v[i].rB,4);
        
        result.push_back(str);
    }
    
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i] << "\n";
    return 0;
}
