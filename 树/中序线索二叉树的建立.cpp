#include <iostream>
using namespace std;
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

		cout << "����" << endl;

		//T s;

		return NULL;

	}

	else

	{

		//T s;

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

		cout << "����" << endl;

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

struct BiNode

{

	T data;

	BiNode<T> *lchild;

	BiNode<T> *rchild;

	bool ltag;

	bool rtag;

};





template <class T>

class BiTree

{

public:

	BiTree()

	{

		root = Creat(root);

		Deepth = 0;

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

	void LeafNode()

	{

		LeafNode(root);

	}

	int GetDeepth()

	{

		int *Max = new int(0);

		int *temp = new int(0);

		GetDeepth(root, Max, temp);

		Deepth = *Max;

		delete Max;

		delete temp;

		return Deepth;

	}

	void LeverOrder();



	int IsEmpty();





private:

	BiNode<T> *root;

	BiNode<T>* Creat(BiNode<T> *bt);

	void PreOrder(BiNode<T> *bt);

	void InOrder(BiNode<T> *bt);

	void PostOrder(BiNode<T> *bt);

	void Release(BiNode<T> *bt);

	LinkQueue<BiNode<T>*> Layer;

	void LeafNode(BiNode<T> *bt);

	void ThrBiTree(BiNode<T> *bt, BiNode<T> *pre);

	void GetDeepth(BiNode<T> *bt, int *Max, int *temp);

	int Deepth;

};



template <class T>

BiNode<T>* BiTree<T>::Creat(BiNode<T> *bt)

{

	//�˴��ɸ�����Ҫ�޸�

	T ch;

	cin >> ch;



	if (ch == '#')

	{

		bt = NULL;

	}

	else

	{

		bt = new BiNode<T>;

		bt->data = ch;

		bt->ltag = 0;

		bt->rtag = 0;

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

		//�Ժ���������������Ҫ����

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

		//�Ժ���������������Ҫ����

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

		//�Ժ���������������Ҫ����

		PostOrder(bt->lchild);

		PostOrder(bt->rchild);

		cout << bt->data << ' ';

	}

}



template <class T>

void BiTree<T>::LeverOrder()

{

	//Node<T> *q;

	BiNode<T> *p;



	if (root != NULL)

	{

		Layer.EnQueue(root);

		while (!Layer.Empty())

		{

			p = (Layer.DeQueue())->Data;

			//p = q->Data;

			cout << p->data << " ";



			if (p->lchild != NULL)

			{

				Layer.EnQueue(p->lchild);

			}

			if (p->rchild != NULL)

			{

				Layer.EnQueue(p->rchild);

			}

			//delete p;

		}

	}

}



template<class T>

int BiTree<T>::IsEmpty()

{

	if (root == NULL)

	{

		return 1;

	}

	else

	{

		return 0;

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



template<class T>

void BiTree<T>::LeafNode(BiNode<T>* bt)

{

	if (root == NULL)

	{

		cout << "NULL" << endl;

	}



	if (bt != NULL)

	{

		//�Ժ���������������Ҫ����

		if (bt->lchild == NULL && bt->rchild == NULL)

		{

			cout << bt->data << ' ';

		}

		else

		{

			LeafNode(bt->lchild);

			LeafNode(bt->rchild);

		}
	}
}
template<class T>
void BiTree<T>::ThrBiTree(BiNode<T>* bt, BiNode<T>* pre)
{
	if (bt != NULL)
	{
	}
}
template<class T>
void BiTree<T>::GetDeepth(BiNode<T>* bt, int * Max, int * temp)
{
	if (bt != NULL)
	{
		*temp = *temp + 1;
		if (*Max < *temp)
		{
			*Max = *temp;
		}
		GetDeepth(bt->lchild, Max, temp);
		GetDeepth(bt->rchild, Max, temp);
		*temp = *temp - 1;
	}
}
int main()
{
	BiTree<char> *b;
	int flag = 0;
	for (; flag == 0;)
	{
		b = new BiTree<char>;
		cout << b->GetDeepth() << endl;
		flag = b->IsEmpty();
		delete b;
	}
	return 0;
}
