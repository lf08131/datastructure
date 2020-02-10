#include <iostream>
const int MaxSize = 10;

using namespace std;

struct ArcNode
{
	int adjvex;
	ArcNode *next;
};

struct VertexNode
{
	char vertex;
	ArcNode *firstedge;
};

class MGraph
{
	public:
		MGraph(char a[], int n, int e);
		void DFSTraverse(int v);
		void BFSTraverse(int v);
		void print(int n)
		{
			int i;
			for(i = 0; i<n; i++)
			{
				cout << adjlist[i].vertex << " ";
				ArcNode *p;
				p = adjlist[i].firstedge;
				for(;p!=NULL;p = p->next)
				{
					cout << p->adjvex << " ";
				}
				cout << endl;
			}
		}
		void aaa(int i)
		{
			int j;
			for(j = 0; j<i; j++)
			{
				visited[j] = 0;
			}
		}
	private:
		VertexNode adjlist[MaxSize];
		int vertexNum,arcNum,visited[100];
};

MGraph::MGraph(char a[], int n, int e)
{
	int i,j,k;
	vertexNum = n;
	arcNum = e;
	
	for(i= 0;i<n; i++)
	{
		visited[i] = 0;
	}
	
	for(i = 0; i<vertexNum; i++)
	{
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;
	}
	for(k = 0; k<arcNum; k++)
	{
		ArcNode *s; 
		cin >> i >> j;
		s = new ArcNode;
		s->adjvex = j;
		s->next = adjlist[i].firstedge;
		adjlist[i].firstedge = s;
	}
}
void MGraph::DFSTraverse(int v)
{
	if(!visited[v])
	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	ArcNode *p; 
	p = adjlist[v].firstedge;
	while(p!=NULL)
	{
		int j  = p->adjvex;
		if(visited[j] == 0)
		{
			DFSTraverse(j);
		}
		p = p->next;
	}
}

void MGraph::BFSTraverse(int v)
{
	int front,rear,j,Q[100];
	front = rear = -1;
	if(!visited[v])
	cout << adjlist[v].vertex << " ";
	visited[v] = 1;
	Q[++rear] = v;
	while(front!=rear)
	{
		v = Q[++front];
		ArcNode *p;
		p = adjlist[v].firstedge;
		while(p!=NULL)
		{
			j = p->adjvex;
			if(visited[j] == 0)
			{
				cout << adjlist[j].vertex << " ";
				visited[j] = 1;
				Q[++rear] = j;	
			} 
			p = p->next;
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
	A.print(a);
	for(i=0; i<a; i++)
	A.DFSTraverse(i);
	A.aaa(a);
	cout << endl;
	for(i=0; i<a; i++)
	A.BFSTraverse(i);
	A.aaa(a);
	cout << endl;
	return 0;
}


