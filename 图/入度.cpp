#include <iostream>
using namespace std;
const int Maxsize = 10;
template <class T>
class MGraph
{
public:
	MGraph(T *a, int n, int e);
	~MGraph(void)
	{
	}
	void DFSTraverse(int v);
	void BFSTraverse(int v);
	void PrintMatrix();
	void DFST();
	void BFST();
	void in();
private:
	T vertex[Maxsize];
	int arc[Maxsize][Maxsize];
	int vertexNum, arcNum;
	int visited[Maxsize];
};


template<class T>
void MGraph<T>::in()
{
	int i;
	cin >> i;
	int j;
	int count = 0;
	for ( j = 0; j < vertexNum; j++)
	{
		count += arc[j][i];
	}
	cout << count;
}

template <class T>
MGraph<T>::MGraph(T *a, int n, int e)
{
	int i, j, k;
	vertexNum = n; 
	arcNum = e;
	for (i = 0; i<vertexNum; i++)
	{
		vertex[i] = a[i];
	}
	for (i = 0; i<vertexNum; i++)
	{
		for (j = 0; j<vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}
	for (k = 0; k<arcNum; k++)
	{
		cin >> i >> j;
		arc[i][j] = 1;
	}
}
int main()
{
	int a, o, i;
	cin >> a >>o;
	char ch[100];
	for (i = 0; i<a; i++)
	{
		cin >> ch[i];
	}
	MGraph<char> A(ch, a, o);
	A.in();
	return 0;
}
