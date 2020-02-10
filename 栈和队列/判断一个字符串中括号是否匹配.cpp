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
	string A;
	int flag = 0;
	LinkStack<char> B;
	cin >> A;
	int i;
	char x;

	for (i = 0; i < A.length(); i++)
	{
		if (A[i] == '{' || A[i] == '(' || A[i] == '[')
		{
			B.Push(A[i]);
		}
		else
		{
			x = B.GetTop();

			if (x == '(' && A[i] == ')')
			{
				B.Pop();
			}
			else if (x == '{' && A[i] == '}')
			{
				B.Pop();
			}
			else if (x == '[' && A[i] == ']')
			{
				B.Pop();
			}
			else
			{
				//cout << "no" << endl;
				cout << "no" ;
				flag = 1;
				break;
				
			}
		}
	}

	if (flag == 0)
	{
		//cout << "yes" << endl;
		cout << "yes";
	}

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
