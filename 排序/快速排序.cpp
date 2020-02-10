#include<iostream>

using namespace std;
int Partition(int r[],int first,int end);
void QuickSort(int r[],int first,int end);
int main()
{
	int a[20];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	QuickSort(a,1,n);


	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
} 
int Partition(int r[],int first,int end)
{
	int flag = 0;
	int exchange = end;
	int temp;
	int i=first;
	int j=end;
	while(i<j)
	{
	
		while(i<j&&r[i]<=r[j])
		{
			j--;
		}
		if(i<j)
		{
			cout<<r[j]<<" ";
			temp =r[j];
			r[j] = r[i];
			r[i] = temp;
			i++;
			flag = 1;		
		}
		
		while(i<j&&r[i]<=r[j])
		{
			i++;
		}
		if(i<j)
		{
			cout<<r[i]<<" ";
			temp =r[j];
			r[j] = r[i];
			r[i] = temp;
			j--;
			flag = 1;
		}
		
	}
	if(flag == 1)
	{
		cout<<endl;
	}
	return i;
}

void QuickSort(int r[],int first,int end)
{
	int pivot;
	if(first<end)
	{
		pivot = Partition(r,first,end);
		
		QuickSort(r,first,pivot-1);
		QuickSort(r,pivot+1,end);
		if (first>=end)
		cout<<endl;
	}
}
