#include <map>
#include <stack>
#include <string>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define IS_NUM(x) (x >= '0' && x <= '9')
#define IS_PARENTHESIS(x) (x == '(' || x == ')')
#define IS_OP(x) (x == '*' || x == '+' || x == '-')

using namespace std;

int N;
string str;
map<char,int> priority;
int result = INT_MIN;
char parenthesis[32];

void set_priority(void)
{
	priority['('] = priority[')'] = 5;
	priority['*'] = 3;
	priority['+'] = priority['-'] = 1;
}

int calculate(int a,int b,char op)
{
	switch(op)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
	}
	return 0;
}

int calculate_postfix(string postfix)
{
    int ret,len = (int)postfix.size();

    for(int i = 0; i < len; i++)
    {
        if(IS_OP(postfix[i]))
        {
            postfix[i-2] = calculate(postfix[i-2]-'0',postfix[i-1]-'0',postfix[i]) + '0';
            for(int j = i-1; j < len; j++)
            {
                for(int k = j; k < len-1; k++)
                {
                    postfix[k] = postfix[k+1];
                }
            }
            len -= 2;
            i -= 3;
        }
    }
    
    ret = (postfix[0]-'0');
    return ret;
}

int make_postfix(void)
{
    cout << "str : " << str << '\n';
    cout << "parenthesis : " << parenthesis << '\n';
    
	stack<char> st;
	string postfix;

	for(int i = 0; i < N; i++)
	{
		if(IS_NUM(str[i]))
		{
			postfix += str[i];
		}
		else if(IS_PARENTHESIS(parenthesis[i]))
		{
			if(parenthesis[i] == '(')
				st.push(parenthesis[i]);
			else // ')'
			{
				while(!st.empty())
				{
					char temp = st.top();
					if(!IS_PARENTHESIS(temp))
						postfix += temp;
                    st.pop();
				}
			}
		}
		else // operator
		{
			if(!st.empty())
			{
				if(!IS_PARENTHESIS(st.top()) && priority[st.top()] > priority[str[i]])
				{
					while(!st.empty())
					{
						if(IS_PARENTHESIS(st.top()))
							break;
						postfix += st.top();
                        st.pop();
					}
					st.push(str[i]);
				}
			}
			else
				st.push(str[i]);
		}
	}

    cout << "Postfix : " << postfix << '\n';
	return calculate_postfix(postfix);
}

void dfs(int idx)
{
	if(idx >= N)
	{
		result = max(result,make_postfix());
		return;
	}

	for(int i = idx; i < N; i++)
	{
		if(i + 2 >= N)
		{
            dfs(i+1);
            continue;
        }
        if(!IS_PARENTHESIS(str[i]) && !IS_PARENTHESIS(str[i+2]))
        {
            parenthesis[i] = '(';
            parenthesis[i+2] = ')';
            dfs(i+2);
            parenthesis[i] = ' ';
            parenthesis[i+2] = ' ';
        }
	}
}

int main(int argc, const char * argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> str;

    memset((char *)parenthesis,' ',sizeof(parenthesis));
	set_priority();
	dfs(0);

	cout << result << '\n';
    return 0;
}
