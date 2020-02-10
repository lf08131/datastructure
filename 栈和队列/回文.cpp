#include <iostream>
#include <string>

using namespace std;

struct Node
{
	char data;
	Node *next;
};

template <class T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void Push(T x);
	T Pop();
	T GetTop();
	int Empty();
private:
	Node *top;
};


int main()
{
	string a;
	cin >> a;
	int i;
	LinkStack<char> A;
	LinkStack<char> B;

	if (a.length()%2==0)
	{
		for (i = 0; i < (a.length() / 2); i++)
		{
			A.Push(a[i]);
		}

		for (i = a.length() - 1; i >= (a.length() / 2); i--)
		{
			B.Push(a[i]);
		}
	} 
	else
	{
		for (i = 0; i < (a.length() / 2); i++)
		{
			A.Push(a[i]);
		}

		for (i = a.length() - 1; i > (a.length() / 2); i--)//奇数的时候没有相等的情况
		{
			B.Push(a[i]);
		}
	}

	for (i = 0; i < (a.length() / 2); i++)
	{
		if (A.GetTop() == B.GetTop())
		{
			A.Pop();
			B.Pop();
		}
	}

	if (A.Empty() && B.Empty())
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	

	//cout << a.length() << endl;
	


	return 0;
}

template <class T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

template <class T>
void LinkStack<T>::Push(T x)
{
	Node *s = new Node;
	s->data = x;
	s->next = top;
	top = s;
}

template <class T>
T LinkStack<T>::Pop()
{
	if (top == NULL)
	{
		return '0';
	}
	else
	{
		int x;
		x = top->data;
		top = top->next;
		return x;
	}

}

template <class T>
T LinkStack<T>::GetTop()
{
	if (top == NULL)
	{
		return '0';
	}
	else
	{
		return top->data;
	}

}

template <class T>
int LinkStack<T>::Empty()
{
	if (top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <class T>
LinkStack<T>::~LinkStack()
{
	Node *p, *q;
	if (top != NULL)
	{
		//如果top都是空的，就没必要释放
		q = top;
		p = top->next;

		while (p != NULL)
		{
			delete q;
			q = p;
			p = p->next;
		}
		delete q;
	}

	top = NULL;
}
