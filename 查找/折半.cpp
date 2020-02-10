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
	int low = 1;
	int high = b;
	int mid;
	while(low<=high)
	{
		mid = (low + high)/2;
		cout<< low <<" "<< mid <<" " << high <<" "<< a[mid] <<endl;
		if(c < a[mid])
		{
			high = mid - 1;
			
		}
		else if(c > a[mid])
			{
			low = mid + 1;
			
			}
		else 
		{
			return mid;
		}
	}	
		return 0;
	
}
