#include<iostream>

using namespace std;
void SelectSort(int r[],int n);

int main()
{
	int a[20];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	
	SelectSort(a,n);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
} 
void SelectSort(int r[],int n)
{
	int j;
	int flag = 0;
	int temp;
	for(int i=1;i<n;i++)
	{
		flag = 0;
		int index = i;
		for(j=i+1;j<=n;j++)
		{
			if(r[j]<r[index])
			{
				cout<<r[j]<<" ";
				index = j;
				 
				flag = 1;
			}
			
		}
		if(index!=i)
		{
			temp =r[index];
			r[index] = r[i];
			r[i] = temp;
			
		}
		if(flag == 1)
		{
			cout<<endl;
		}
	}
}
