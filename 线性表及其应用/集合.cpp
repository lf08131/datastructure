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
	LinkList(LinkList &a);
	~LinkList();
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
	int i, j, x, n, temp;
	char flag = 'e';
	//int a[100];
	LinkList A, B, E;

	while (flag != 'E')
	{
		cin >> flag;
		if (flag=='A')
		{
			cin >> n;
			for (i = 0; i < n; i++)
			{
				//cin >> a[i];
				cin >> x;
				A.Insert(i + 1, x);
			}

		}

		if (flag == 'B')
		{
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cin >> x;
				B.Insert(i + 1, x);
			}

			//LinkList B(a, n);
		}

		if (flag=='U')
		{
			LinkList C(A);
			for (j = 1; j <= B.Length(); j++)
			{
				if (C.Locate(B.Get(j)))
				{
					//进去就是存在
				}
				else
				{
					//进去就是不存在
					C.Insert(C.Length() + 1, B.Get(j));
				}
			}

			C.PrintList();
		}

		if (flag == 'I')
		{
			LinkList D(A);
			for (j = 1; j <= D.Length(); j++)
			{
				if (B.Locate(D.Get(j)))
				{
					//进去就是存在


				}
				else
				{
					//进去就是不存在
					D.Delete(j);
					j--;
				}
			}

			D.PrintList();
		}
	}
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

LinkList::LinkList(LinkList &a)
{
	first = new Node;
	Node *p,*q;
	q = first;
	p = a.first->next;
	while ( p != NULL )
	{
		q->next = new Node;
		q = q->next;
		q->data = p->data;
		q->next = NULL;
		p = p->next;
	}
}
