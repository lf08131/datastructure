#include <iostream>
using namespace std;
int HashSearch(int ht[], int m, int k, int n)
{
	int v;
	int i;
	v = k % m;
	if (ht[v] == k)
	{
		return v;
	}
	else if (ht[v] == -1)

	{
		ht[v] = k;
		return 0;
	}

	i = (v + 1) % m;
	while (ht[i] != -1 && i!=v)
	{
		if (ht[i]==k)
		{
			return i;
		}
		else
		{
			i = (i + 1) % n;
		}
	}
	if (i == v)
	{
		return -1;
	}
	else
	{
		ht[i] = k;
		return 0;
	}
}
int main()
{
	int n;
	int temp;
	cin >> n;
	int *a = new int[n];
	int m;
	cin >> m;
	int num;
	cin >> num;
	{
		for (int j = 0; j < n; j++)
		{
			a[j] = -1;
		}
		for (int i = 0; i < num; i++)
		{
			cin >> temp;
			HashSearch(a, m, temp,n);
		}
		int b[3];
		cin >> b[0];
		cin >> b[1];
		cin >> b[2];
		temp = HashSearch(a, m, b[0], n);
		if (temp > 0)
		{
			cout << temp << endl;
		}
		else if (temp == 0)
		{
			cout << "none" << endl;
		}
		else if (temp == -1)
		{

			cout << "full" << endl;
		}
		temp = HashSearch(a, m, b[1], n);
		if (temp > 0)
		{
			cout << temp << endl;
		}
		else if (temp == 0)
		{
			cout << "none" << endl;
		}
		else if (temp == -1)
		{
			cout << "full" << endl;
		}
		temp = HashSearch(a, m, b[2], n);
		if (temp > 0)
		{
			cout << temp << endl;
		}
		else if (temp == 0)
		{
			cout << "none" << endl;
		}
		else if (temp == -1)
		{
			cout << "full" << endl;
		}
	}
	delete[] a;
	return 0;
}
