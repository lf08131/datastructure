#include <iostream>

using namespace std;

int main()
{
	int a[100];
	int n;
	int i;
	int x;
	int y;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> x;
	cin >> y;
	for (i = 0; i < n; i++)
	{
		if (a[i] != x && a[i] != y)
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}
