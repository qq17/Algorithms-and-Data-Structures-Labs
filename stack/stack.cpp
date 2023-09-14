#include <iostream>
#include <limits>
using namespace std;

struct stack
{
	int* arrptr = nullptr;
	unsigned size = 0;
	unsigned capacity = 0;
};

int top(int& result, stack stk)
{
	if (stk.arrptr == nullptr)
	{
		cout << "top(): arr = nullptr" << endl;
		return 1;
	}

	result = stk.arrptr[stk.size - 1];
	return 0;
}

int pop(stack& stk)
{
	if (stk.arrptr == nullptr)
	{
		if (stk.size != 0)
		{
			cout << "pop(): arr = nullptr and n != 0" << endl;
			return 1;
		}
		return 0;
	}
	if (stk.size < 0)
	{
		cout << "pop(): n < 0" << endl;
		return 2;
	}

	int* newptr = nullptr;
	--stk.size;
	stk.capacity = stk.size;
	if (stk.size != 0)
	{
		try
		{
			newptr = new int[stk.size];
		}
		catch (bad_alloc & e)
		{
			cout << "pop(): memory allocation error" << endl;
			return 1;
		}

		for (int i = 0; i < stk.size; i++)
		{
			newptr[i] = stk.arrptr[i];
		}
		delete[] stk.arrptr;
		stk.arrptr = newptr;
	}
	else
	{
		stk.arrptr = nullptr;
	}

	return 0;
}

int push(int x, stack& stk)
{
	int* newptr = nullptr;
	++stk.size;
	if (stk.size > stk.capacity)
	{
		stk.capacity = stk.size * 1.5;
		try
		{
			newptr = new int[stk.capacity];
		}
		catch (bad_alloc & e)
		{
			cout << "push(): memory allocation error" << endl;
			return 1;
		}
		
		for (int i = 0; i < stk.size - 1; i++)
		{
			newptr[i] = stk.arrptr[i];
		}
		newptr[stk.size - 1] = x;
		if (stk.size != 1 && stk.arrptr != nullptr)
		{
			delete[] stk.arrptr;
		}
		stk.arrptr = newptr;
	}
	else
	{
		stk.arrptr[stk.size - 1] = x;
	}

	return 0;
}

int main()
{
	stack stk;
	int* newptr = nullptr;
	int x;
	int error = 0;
	int n = 0;
	bool again = true;
	string s;
	cout << "0 is the end" << endl;
	cin >> x;
	while (!cin.good())
	{
		cout << "enter number\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> x;
	}

	while (x)
	{
		if ((error = push(x, stk)) != 0)
		{
			return error;
		}
		cin >> x;
		while (!cin.good())
		{
			cout << "enter number\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> x;
		}
	}

	while (again)
	{
		cout << "\n1: push\n2: pop\n3: top\n4: print and delete\n0: exit\n";
		cin >> x;
		while (!cin.good())
		{
			cout << "enter number\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> x;
		}
		switch (x)
		{
		case 0:
			again = false;
			continue;
		case 1:
			cin >> x;
			while (!cin.good())
			{
				cout << "enter number\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> x;
			}
			push(x, stk);
			break;
		case 2:
			pop(stk);
			break;
		case 3:
			top(x, stk);
			cout << x << endl;
			break;
		case 4:
			cout << "elements from the top:" << endl;
			while (stk.arrptr != nullptr)
			{
				if ((error = top(x, stk)) != 0)
				{
					return error;
				}
				cout << x << endl;
				if ((error = pop(stk)) != 0)
				{
					return error;
				}
			}
			break;
		default:
			continue;
		}
	}

	return 0;
}