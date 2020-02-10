#include <iostream>
using namespace std;
struct BiNode
{
	char data;
	BiNode *lchild;
	BiNode *rchild;
	bool ltag;
	bool rtag;
};
class BiTree
{
public:
	BiTree()
	{
		root = Creat(root);
	}
	void PreOrder()
	{
		PreOrder(root);
	}
	int NodeNum()
	{
		int n = 0;
		n = NodeNum(root, n);
		return n;
	}
	int IsEmpty();
private:
	BiNode  *root;
	BiNode * Creat(BiNode  *bt);
	void PreOrder(BiNode  *bt);
	int NodeNum(BiNode  *bt,int n);
};

BiNode * BiTree ::Creat(BiNode  *bt)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		bt = NULL;
	}
	else
	{
		bt = new BiNode ;
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}
void BiTree ::PreOrder(BiNode  *bt)
{
	if (bt != NULL)
	{
		cout << bt->data << ' ';
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
int BiTree ::IsEmpty()
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
int BiTree ::NodeNum(BiNode * bt, int n)
{
	if (bt != NULL)
	{
		n++;
		n = NodeNum(bt->lchild, n);
		n = NodeNum(bt->rchild, n);
	}
	return n;
}
int main()
{
	int temp;
	int flag = 0;
	BiTree *B = new BiTree;
		temp = B->NodeNum();
		if (temp == 0)
		{
			cout << "NULL";
		} 
		else
		{
			cout << temp << endl;
		}	
		flag = B->IsEmpty();
		delete B;
	return 0;
}
