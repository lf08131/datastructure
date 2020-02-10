#include<iostream>

using namespace std;
void InsertSort(int r[],int n);

int main()
{
	int a[20];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	
	InsertSort(a,n);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
} 
void InsertSort(int r[],int n)
{
	int j;
	int flag=0;
	
	for(int i=2;i<=n;i++)
	{
		r[0] = r[i];
		for(j=i-1;r[0]<r[j];j--)
		{
			r[j+1] = r[j];
			cout<<r[j+1]<<" ";
			flag = 1;
		}
		if(flag == 1)
		cout<<endl;
		r[j+1] = r[0];
		flag = 0;
		
	}

}
