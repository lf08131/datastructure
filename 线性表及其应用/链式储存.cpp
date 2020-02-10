#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

class LinkList
{
public:
	LinkList();
	virtual ~LinkList();
	LinkList(int *a, int n);
	int Length();
	int Get(int i);
	int Locate(int x);
	void Insert(int i, int x);
	int Delete(int i);
	void PrintList();
private:
	Node *first;

};

int main()
{
	int n;
	//int a[100];
	char flag = 'a';
	int i;
	LinkList b;
	int temp1, temp2;

	for (; flag != 'E';)
	{
		cin >> flag;

		if (flag == 'I')
		{
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cin >> temp1;
				cin >> temp2;
				b.Insert(temp1, temp2);
			}
		}

		if (flag == 'S')
		{
			cin >> temp1;
			temp2 = b.Locate(temp1);

			if (temp2 == 0)
			{
				cout << "None" << endl;
			}
			else
			{
				cout << temp2 << endl;
			}

		}

		if (flag == 'G')
		{
			cin >> temp1;
			temp2 = b.Get(temp1);
			cout << temp2 << endl;
		}

		if (flag == 'V')
		{
			b.PrintList();
		}

		if (flag == 'D')
		{
			cin >> temp1;

			if ((temp2 = b.Delete(temp1)) != 0)
			{
				cout << temp2 << endl;
			}

		}

		if (flag == 'L')
		{
			cout << b.Length() << endl;
		}
	}

	return 0;
}

LinkList::LinkList()
{
	first = new Node;
	first->next = NULL;
}

LinkList::LinkList(int *a, int n)
{
	Node *r, *s;
	first = new Node;
	int i;
	r = first;
	for (i = 0; i<n; i++)
	{
		s = new Node;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

LinkList::~LinkList()
{
	Node *q;
	while (first != NULL)
	{
		q = first;
		first = first->next;
		delete q;
	}
}

void LinkList::PrintList()
{
	Node *p;
	p = first->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

int LinkList::Length()
{
	int count = 0;
	Node *p = first->next;

	while (p != NULL)
	{
		p = p->next;
		count++;
	}

	return count;
}

int LinkList::Get(int i)
{
	Node *p = first->next;
	int count = 1;

	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		return p->data;
	}
}

int LinkList::Locate(int x)
{
	Node *p = first->next;
	int count = 1;

	while (p != NULL)
	{
		if (p->data == x)
		{
			return count;
		}

		p = p->next;
		count++;
	}

	return 0;
}

void LinkList::Insert(int i, int x)
{
	Node *p = first;
	int count = 0;

	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}

	if (p == NULL)
	{
		//char *s = "位置";
		//throw s;
		cout << "位置不正确" << endl;
	}
	else
	{
		Node *s = new Node;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

int LinkList::Delete(int i)
{
	Node *p = first;
	Node *q;
	int count = 0;
	int x;

	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}

	if (p == NULL || p->next == NULL)
	{
		/*char *s = "位置";
		throw s;*/
		cout << "位置" << endl;
	}
	else
	{
		q = p->next;
		x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}
