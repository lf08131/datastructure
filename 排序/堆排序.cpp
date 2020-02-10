#include<iostream>

using namespace std;

void HeapSort(int r[],int n);
int main()
{
	int a[20];
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	HeapSort(a,n);


	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";

	return 0;
} 
void Sift(int r[],int k,int m,int *flag)
{
	int temp;
	int i=k;
	int j=2*i;
	*flag = 0;
	while(j<=m)
	{
		
		if(j<m&&r[j]<r[j+1])
		{
		
			j++;
		}
		if(r[i]>r[j])
		{
			break;
		}
		else
		{
			cout<<r[j]<<" ";
			temp =r[i];
			r[i] = r[j];
			r[j] = temp;
			
			*flag = 1; 
			i = j;
			j = 2 * i;
		}
	
	}
}

void HeapSort(int r[],int n)
{
	int flag;
	int temp;
	for(int i=n/2;i>=1;i--)
	{
		Sift(r,i,n,&flag);
		if(flag == 1)
		{
			cout<<endl;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<r[i]<<" ";
	}
	
	cout<<endl;
	for(int i=1;i<n;i++)
	{
		temp =r[1];
		r[1] = r[n-i+1];
		r[n-i+1] = temp;
		Sift(r,1,n-i,&flag);
		if(flag == 1)
		{
			cout<<endl;
		}
	}
}
