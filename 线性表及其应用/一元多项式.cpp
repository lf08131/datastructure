#include <iostream>

using namespace std;

struct Node
{
	int coef;
	int exp1;
	Node *next;
};

class LinkList
{

public:
	LinkList();
	LinkList(int *a, int n);
	int Length();
	void Insert(int i, int x,int y);
	void PrintList();
private:
	Node *first;
	friend void Add(LinkList A, LinkList B);

};

int main()
{

	int i;
	int temp1, temp2;
	char flag = 'e';
	LinkList A;
	LinkList B;

	while (flag!='E')
	{
		cin >> flag;

		if (flag == 'A')
		{
			for (i = 0; ; i++)
			{
				cin >> temp1;
				cin >> temp2;
				if (temp1)
				{
					A.Insert(i + 1, temp1, temp2);
				}
				else
				{
					break;
				}
			}
		}

		if (flag == 'B')
		{
			for (i = 0; ; i++)
			{
				cin >> temp1;
				cin >> temp2;
				if (temp1)
				{
					B.Insert(i + 1, temp1, temp2);
				}
				else
				{
					break;
				}
			}
			
		}

		if (flag=='C')
		{
			Add(A, B);
			//A.PrintList();
		}
	} 


	return 0;
}

void Add(LinkList A, LinkList B)
{
	Node *pre, *qre, *p, *q, *ptemp;
	pre = A.first;
	p = pre->next;
	qre = B.first;
	q = qre->next;
	while (p != NULL && q != NULL)
	{

		if (p->exp1 < q->exp1)
		{
			pre = p;
			p = p->next;
		}
		else if (p->exp1 > q->exp1)
		{
			ptemp = q->next;
			pre->next = q;
			q->next = p;
			pre = q;
			q = ptemp;
		}
		else
		{
			p->coef = p->coef + q->coef;
			if (p->coef == 0)
			{
				pre->next = p->next;
				delete p;
				p = pre->next;
			}
			else
			{
				pre = p;
				p = p->next;
			}
			qre->next = q->next;
			delete q;
			q = qre->next;
		}
	}

	//
	if (q != NULL)
	{
		pre->next = q;
	}

	delete B.first;
	B.first = NULL;

	Node *ptemp2;
	ptemp2 = A.first->next;
	while (ptemp2 != NULL)
	{
		cout << ptemp2->coef << ' ' << ptemp2->exp1 << endl;
		ptemp2 = ptemp2->next;
	}
}

LinkList::LinkList()
{
	first = new Node;
	first->next = NULL;
}


void LinkList::PrintList()
{
	Node *p;
	p = first->next;
	while (p != NULL)
	{
		cout << p->coef << ' ' << p->exp1 <<endl;
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

void LinkList::Insert(int i, int x, int y)
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
		s->coef = x;
		s->exp1 = y;
		s->next = p->next;
		p->next = s;
	}
}



