#include<iostream>

using namespace std;
void BubbleSort(int r[],int n);

int main()
{
	int a[20];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	
	BubbleSort(a,n);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
} 
void BubbleSort(int r[],int n)
{
	int j;
	int flag = 0;
	int exchange = n;
	int temp;
	
	while(exchange!=0) 
	{
		flag = 0;
		int bound = exchange;
		exchange = 0;
		for (j=1;j<bound;j++)
		{
			if(r[j]>r[j+1])
			{
				temp =r[j];
				r[j] = r[j+1];
				r[j+1] = temp;
				exchange = j; 
				cout<<r[j]<<" ";
				flag = 1; 
			}
		}
		if(flag == 1)
		{
			cout<<endl;
		}
	}	
}
