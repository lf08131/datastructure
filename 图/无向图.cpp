#include <iostream>

using namespace std;

const int maxsize = 100;

class MGraph
{
public:
	MGraph(char a[], int n, int e);
	void DFSTraverse(int v);
	void BFSTraverse(int v);
	void print(int n)
	{
		int i,j; 
		for(i = 0;i<n; i++)
		{
			for(j = 0; j<n; j++)
			{
				cout << arc[i][j] << " ";
			}
			cout << endl;
		}
	}
	void A(int n)
	{
		int i;
		for(i = 0; i<n; i++)
		{
			visited[i] = 0;
		}
	}
private:
	char vertex[maxsize];
	int arc[maxsize][maxsize],visited[maxsize];
	int vertexNum,arcNum;

};


MGraph::MGraph(char a[], int n, int e)
{
	vertexNum = n;
	arcNum = e;
	int i,j,k;
	for(i = 0; i<vertexNum; i++)
	{
		vertex[i] = a[i];
	}
	for(i = 0; i<vertexNum; i++)
	{
		
		for(j = 0; j<vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}
	for(k = 0; k<arcNum; k++)
	{
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = 1;
	}
}

void MGraph::DFSTraverse(int v)
{
	int j;
		if(!visited[v])
	cout << vertex[v] << " ";
	visited[v] = 1;
	for(j = 0; j<vertexNum; j++)
	{
		if(arc[v][j] == 1&&visited[j] == 0)
		{
			DFSTraverse(j);
		}
	}
}

void MGraph::BFSTraverse(int v)
{
	int front,rear,j;
	int Q[100];
	front = rear =-1;
	if(!visited[v])
	cout << vertex[v] << " ";
	visited[v] = 1;
	Q[++rear] = v;
	while(front!=rear)
	{
		v = Q[++front];
		for(j = 0; j<vertexNum; j++)
		{
			if(arc[v][j] == 1&&visited[j] == 0)
			{
				cout << vertex[j] << " ";
				visited[j] = 1;
				Q[++rear] = j;
			}
		}
	}

}

int main()
{
	int a,b,i;
	cin >> a >> b;
	char c[100];
	for(i = 0; i<a; i++)
	{
		cin >> c[i];
	}
	MGraph A(c,a,b);
	for(i = 0; i<a; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	A.A(a);
	A.print(a);
	A.A(a);
	for(i=0; i<a; i++)
	A.DFSTraverse(i);
	cout << endl;
	A.A(a);
	for(i=0; i<a; i++)
	A.BFSTraverse(i);
	cout << endl;

	return 0;
}

