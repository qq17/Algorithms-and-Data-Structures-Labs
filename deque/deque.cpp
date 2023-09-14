#include <iostream>
using namespace std;

struct node
{
	int value;
	node* next;
	node* prev;
};

struct dequestr
{
	node* tail = nullptr;
	node* head = nullptr;
};

int initialize(dequestr& dq, int x)
{
	try
	{
		dq.head = new node;
	}
	catch (bad_alloc & e)
	{
		cout << endl << "memory allocation error";
		return 1;
	}
	dq.head->next = nullptr;
	dq.head->prev = nullptr;
	dq.head->value = x;
	dq.tail = dq.head;
	return 0;
}

int pushFront(dequestr& dq, int x)
{
	if (dq.head == nullptr)
	{
		initialize(dq, x);
		return 0;
	}
	try
	{
		dq.head->prev = new node;
	}
	catch (bad_alloc & e)
	{
		cout << endl << "memory allocation error";
		return 1;
	}
	dq.head->prev->next = dq.head;
	dq.head = dq.head->prev;
	dq.head->prev = nullptr;
	dq.head->value = x;
	return 0;
}

int pushBack(dequestr& dq, int x)
{
	if (dq.tail == nullptr)
	{
		initialize(dq, x);
		return 0;
	}
	try
	{
		dq.tail->next = new node;
	}
	catch (bad_alloc & e)
	{
		cout << endl << "pushback memory allocation error";
		return 1;
	}
	(dq.tail->next)->prev = dq.tail;
	dq.tail = dq.tail->next;
	dq.tail->next = nullptr;
	dq.tail->value = x;
	return 0;
}

int popFront(dequestr& dq)
{
	if (dq.head == nullptr)
	{
		cout << "popFront(): dq.head == nullptr" << endl;
		return 1;
	}
	node* head = dq.head;

	if (dq.head == dq.tail)
	{
		dq.head = nullptr;
		dq.tail = nullptr;

	}
	else
	{
		dq.head = dq.head->next;
		dq.head->prev = nullptr;
	}

	delete head;
	return 0;
}

int popBack(dequestr& dq)
{
	if (dq.tail == nullptr)
	{
		cout << "popBack(): dq.tail == nullptr" << endl;
		return 1;
	}
	node* tail = dq.tail;

	if (dq.head == dq.tail)
	{
		dq.head = nullptr;
		dq.tail = nullptr;
	}
	else
	{
		dq.tail = dq.tail->prev;
		dq.tail->next = nullptr;
	}

	delete tail;
	return 0;
}

int printFront(dequestr dq)
{
	if (dq.head == nullptr)
	{
		cout << "printFront(): dq.head == nullptr" << endl;
		return 1;
	}
	cout << dq.head->value;
	return 0;
}

int printBack(dequestr dq)
{
	if (dq.tail == nullptr)
	{
		cout << "printBack(): dq.tail == nullptr" << endl;
		return 1;
	}
	cout << dq.tail->value;
	return 0;
}

int printDeleteAllFront(dequestr& dq)
{
	while (dq.head != nullptr)
	{
		printFront(dq);
		popFront(dq);
		cout << endl;
	}
	return 0;
}

int printDeleteAllBack(dequestr& dq)
{
	while (dq.tail != nullptr)
	{
		printBack(dq);
		popBack(dq);
		cout << endl;
	}
	return 0;
}

int justprintFront(dequestr dq)
{
	node* head = dq.head;
	while (head != nullptr)
	{
		cout << head->value;
		cout << endl;
		head = head->next;
	}
	return 0;
}

int justprintBack(dequestr dq)
{
	node* tail = dq.tail;
	while (tail != nullptr)
	{
		cout << tail->value;
		cout << endl;
		tail = tail->prev;
	}
	return 0;
}

int main()
{
	dequestr dq;
	int x;
	bool again = true;
	cout << "0 is the end" << endl;
	cin >> x;
	
	while (x)
	{
		pushBack(dq, x);
		cin >> x;
	}
	
	while (again)
	{
		cout << "\n1: pushFront\n2: pushBack\n3: popFront\n4: popBack\n5: printFront\n6: printBack\n7: print and delete front\n8: print and delete all back\n0: exit" << endl;
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
			pushFront(dq, x);
			break;
		case 2:
			cin >> x;
			while (!cin.good())
			{
				cout << "enter number\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> x;
			}
			pushBack(dq, x);
			break;
		case 3:
			popFront(dq);
			break;
		case 4:
			popBack(dq);
			break;
		case 5:
			printFront(dq);
			break;
		case 6:
			printBack(dq);
			break;
		case 7:
			printDeleteAllFront(dq);
			break;
		case 8:
			printDeleteAllBack(dq);
			break;
		default:
			continue;
		}
	}

	return 0;
}