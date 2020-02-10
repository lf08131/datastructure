#include<iostream>

using namespace std;

int Search(int *a,int b,int c);
int main()
{
	int n;
	int S;
	cin >> n;
	int *p = new int[n + 1];
	for(int i=0;i<n;i++)
	{
		cin >> p[i+1];
	}
	for(int i=0;i<3;i++)
	{
		cin >> S;
		cout<<Search(p,n,S)<<endl;
	}
	delete []p;
	return 0;
}

int Search(int *a,int b,int c)
{
	int i;
	a[0]=c;
	i=b;
	while(a[i]!=c)
	{
		cout<<a[i]<<" ";
		i--;
	}
	cout<<endl;
		return i;	
}
