#include<iostream>

using namespace std;
void ShellSort(int r[],int n);

int main()
{
	int a[20];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	
	ShellSort(a,n);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
} 
void ShellSort(int r[],int n)
{
	int j;
	int flag = 0;
	for (int d=n/2;d>=1;d=d/2)
	{
		flag = 0;
		for(int i=d+1;i<=n;i++)
		{
			r[0]=r[i];
			for( j=i-d;j>0&&r[0]<r[j];j=j-d)
			{
				r[j+d] = r[j];
				flag = 1;
				cout<<r[j]<<" ";
			}
			r[j+d] = r[0];
		}
		
		if(flag == 1)
		{
			cout<<endl;
		}
	}
}
