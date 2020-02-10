//在有序表中插入两个元素
#include <iostream>

using namespace std;

void add(int *a, int n1, int n2, int x)
{
	int i;
	for (i = n1; i > n2; i--)
	{
		a[i] = a[i - 1];
	} 
	a[i] = x;
}

void sort(int *a, int y, int n1)
{
	int i;
	for (i = 0; i < n1; i++)
	{
		if (i == 0)
		{
			if (y < a[0])
			{
				add(a, n1, i , y);
			}
		}
		if (y > a[i] && y < a[i + 1])
		{
			add(a, n1, i+1, y);
			break;
		}
		if (i == n1 - 1)
		{
			if (y >= a[n1 - 1])
			{
				a[n1] = y;
			}
		}
		
	}
}

int main()
{
	int a[100];
	int i;
	int n1;
	int x,y;

	cin >> n1;

	for (i = 0; i < n1; i++)
	{
		cin >> a[i];
	}

	cin >> x;
	cin >> y;

	sort(a, x, n1);
	n1++;
	sort(a, y, n1);
	n1++;

	for (i = 0; i < n1; i++)
	{
		cout << a[i];
		cout << " ";
	}
	return 0;
}
