#include <iostream>

using namespace std;

template <class T>

struct BiNode

{
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
	bool ltag;
	bool rtag;
};

template <class T>

struct Node
{
	T Data;
	Node *next;
};

template <class T>
class LinkQueue
{
public:
	LinkQueue();
	virtual ~LinkQueue();
	void EnQueue(T x);
	Node<T>* DeQueue();
	Node<T>* GetQueue();
	int Empty();
	void GetClean();
private:
	Node<T> *front;
	Node<T> *rear;
};

template <class T>
LinkQueue<T>::LinkQueue()
{
	Node<T> *s = new Node<T>;
	s->next = NULL;
	front = s;
	rear = s;
}

template <class T>

LinkQueue<T>::~LinkQueue()

{
	Node<T> *p;
	while (front != NULL)
	{
		p = front;
		front = front->next;
		delete p;
	}
}

template<class T>
void LinkQueue<T>::EnQueue(T x)
{
	Node<T> *s = new Node<T>;
	s->Data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

template<class T>
Node<T>* LinkQueue<T>::DeQueue()
{
	Node<T> *s = new Node<T>;
	if (rear == front)
	{
		cout << "ÏÂÒç" << endl;


		return NULL;

	}

	else
	{
		Node<T> *t;
		t = front->next;
		s->Data = t->Data;
		front->next = t->next;
		if (t->next == NULL)
		{
			rear = front;
		}
		delete t;
	}

	return s;
}

template<class T>
Node<T>* LinkQueue<T>::GetQueue()
{
	Node<T> *p;
	Node<T> *s = new Node<T>;
	if (front == rear)
	{
		cout << "ÏÂÒç" << endl;
		return NULL;
	}
	else
	{
		p = front->next;
		s->Data = p->Data;
	}

	return s;
}

template<class T>

int LinkQueue<T>::Empty()

{
	if (front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class T>

void LinkQueue<T>::GetClean()
{
	Node<T> *p;
	while (front->next != NULL)
	{
		p = front;
		front = front->next;
		delete p;
	}
	rear = front;
}

template <class T>

class BiTree
{
public:
	BiTree()
	{
		root = Creat(root);
	}
	~BiTree()
	{
		Release(root);
	}
	void PreOrder()
	{
		PreOrder(root);
	}

	void InOrder()
	{
		InOrder(root);
	}

	void PostOrder()
	{
		PostOrder(root);
	}
	void LeverOrder();

private:
	BiNode<T> *root;
	BiNode<T>* Creat(BiNode<T> *bt);
	void PreOrder(BiNode<T> *bt);
	void InOrder(BiNode<T> *bt);
	void PostOrder(BiNode<T> *bt);
	void Release(BiNode<T> *bt);
	LinkQueue<BiNode<T>*> Layer;
};

template <class T>
BiNode<T>* BiTree<T>::Creat(BiNode<T> *bt)
{
	T ch;
	cin >> ch;
	if (ch == 0)
	{
		bt = NULL;
	}
	else
	{
		bt = new BiNode<T>;
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}

template <class T>
void BiTree<T>::PreOrder(BiNode<T> *bt)
{
	if (bt != NULL)
	{
		cout << bt->data << ' ';
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

template <class T>
void BiTree<T>::InOrder(BiNode<T> *bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		cout << bt->data << ' ';
		InOrder(bt->rchild);
	}
}

template <class T>
void BiTree<T>::PostOrder(BiNode<T> *bt)
{
	if (bt != NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data << ' ';
	}
}
template <class T>
void BiTree<T>::LeverOrder()
{
	BiNode<T> *p;
	if (root != NULL)
	{
		Layer.EnQueue(root);
		while (!Layer.Empty())
		{
			p = (Layer.DeQueue())->Data;
			cout << p->data << " ";
			if (p->lchild != NULL)
			{
				Layer.EnQueue(p->lchild);
			}
			if (p->rchild != NULL)
			{
				Layer.EnQueue(p->rchild);
			}
		}
	}
}

template <class T>
void BiTree<T>::Release(BiNode<T> *bt)
{
	if (bt != NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

int main()
{
	BiTree<int> C;
	C.PreOrder();
	cout << endl;
	C.InOrder();
	cout << endl;
	C.PostOrder();
	cout << endl;
	C.LeverOrder();
	cout << endl;
	return 0;
}
