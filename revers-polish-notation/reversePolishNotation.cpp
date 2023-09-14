#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c)
{
	char op[] = { '+', '-', '*', '/', '^' };
	for (int i = 0; i < 5; i++)
	{
		if (c == op[i])
		{
			return true;
		}
	}
	return false;
}

int getPriority(char c)
{
	if (c == '+' || c == '-')
	{
		return 1;
	}
	if (c == '*' || c == '/')
	{
		return 2;
	}
	if (c == '^')
	{
		return 3;
	}
	return 0;
}

int main()
{
	stack<char> stk;
	string s;
	string res;
	cout << "enter infix notation" << endl;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (!isOperator(s[i]))
		{
			if (s[i] == '(')
			{
				stk.push(s[i]);
				continue;
			}
			if (s[i] == ')')
			{
				while (!stk.empty())
				{
					if (stk.top() == '(')
					{
						break;
					}
					res += stk.top();
					stk.pop();
				}
				if (stk.empty())
				{
					cout << "error";
					return 1;
				}
				else
				{
					stk.pop();
				}
				continue;
			}
			res += s[i];
		}
		else
		{
			while (!stk.empty() && (isOperator(stk.top()) && (getPriority(s[i]) <= getPriority(stk.top()))))
			{
				res += stk.top();
				stk.pop();
			}
			stk.push(s[i]);
		}
	}
	while (!stk.empty())
	{
		res += stk.top();
		stk.pop();
	}
	cout << res << endl;
	return 0;
}