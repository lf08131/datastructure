#include <iostream>

using namespace std;

struct Node
{
	int  t;
	Node *next;
};

Node *HashSearch1(Node **ht, int m, int k)
{
	int b;
	int count = 1;
	b = k % m;
	Node *p = ht[b];
	while (p!=NULL && p->t!=k)
	{
		p = p->next;
		count++;
	}
	if (p!=NULL && p->t == k)
	{
		cout << b << " " << count << endl;
		return p;
	}
	else
	{
		Node *q = new Node;
		q->t = k;
		q->next = ht[b];
		ht[b] = q;
		return NULL;
	}
}

int main()
{
	Node *p;
	int n;
	cin >> n;
	Node **c = new Node*[n];
	int i;
	for (i=0; i<n; i++)
	{
		c[i] = NULL;
	}
	int m;
	cin >> m;
	int num;
	cin >> num;
	int temp1;
	for (i=0; i<num; i++)
	{
		cin >> temp1;
		HashSearch1(c, m, temp1);
	}
	int b[3];
	for (i=0; i<3; i++)
	{
		cin >> b[i];
	}
	for (i=0; i<3; i++)
	{
		p = HashSearch1(c, m, b[i]);
		if (p==NULL)
		{
			cout << "none" << endl; 
		}
	}
	return 0;
}
