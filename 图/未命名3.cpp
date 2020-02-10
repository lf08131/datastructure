#include <iostream>



using namespace std;



const int MaxSize = 10;



class MGraph

{

private:

	char vertex[MaxSize];

	int arc[MaxSize][MaxSize];

	int vertexNum, arcNum;

public:

	MGraph() {};

	MGraph(char a[], int n, int e);

	~MGraph() {};

	void DFSTraverse(int v);

	void BFSTraverse(int v);

	void printf();

	int visited[MaxSize];

	int visited2[MaxSize];

	void OutPutVertex();

};



MGraph::MGraph(char a[], int n, int e)

{

	int i, j, k;



	for (i = 0; i < 10; i++)

	{

		visited[i] = 0;

		visited2[i] = 0;

	}





	vertexNum = n;

	arcNum = e;



	for (i = 0; i < vertexNum; i++)

	{

		vertex[i] = a[i];

	}

	for (i = 0; i < vertexNum; i++)

	{

		for (j = 0; j < vertexNum; j++)

		{

			arc[i][j] = 0;

		}

	}

	for (k = 0; k < arcNum; k++)

	{

		cin >> i >> j;

		arc[i][j] = 1;

		arc[j][i] = 1;

	}

}



void MGraph::OutPutVertex()

{

	int i;

	for (i = 0; i < vertexNum; i++)

	{

		cout << vertex[i] << " ";

	}

}



void MGraph::printf()

{

	int i, j;

	for (i = 0; i < vertexNum; i++)

	{

		for (j = 0; j < vertexNum; j++)

		{

			cout << arc[i][j] << " ";

		}

		cout << endl;

	}

}



void MGraph::DFSTraverse(int v)

{

	if (visited[v] == 0)

	{

		cout << vertex[v] << " ";

		visited[v] = 1;

	}

	int j;

	for (j = 0; j < vertexNum; j++)

	{

		if (arc[v][j] == 1 && visited[j] == 0)

		{

			DFSTraverse(j);

		}

	}

}



void MGraph::BFSTraverse(int v)

{

	int front, rear;

	int Q[20];

	int j;



	front = rear = -1;

	if (visited2[v] == 0)

	{

		cout << vertex[v] << " ";

		visited2[v] = 1;

	}

	Q[++rear] = v;

	while (front != rear)

	{

		v = Q[++front];

		for (j = 0; j < vertexNum; j++)

		{

			if (arc[v][j] == 1 && visited2[j] == 0)

			{

				cout << vertex[j] << " ";

				visited2[j] = 1;

				Q[++rear] = j;

			}

		}

	}

}



int main()
{
	int a, e;
	int i;
	cin >> a >> e;
	char *a = new char[5];
	for (i = 0; i < a; i++)
	{
		cin >> a + i;
	}
	MGraph MG(a, a, e);
	MG.OutPutVertex();
	cout << endl;
	MG.printf();
	int v;
	for (v = 0; v < n; v++)
	{
		MG.DFSTraverse(v);
	}
	cout << endl;
	for (v = 0; v < n; v++)
	{
		MG.BFSTraverse(v);
	}

	return 0;

}
