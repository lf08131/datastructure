//�ҵ������е����ֵ��������ĵ�λ�ú����ֵ
#include <iostream>

using namespace std;



int main()
{
	int a[100];
	int n;

	int i,Max,Poz;

	for (i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	
	Max = a[0];

	for (i = 0; i < 3; i++)
	{
		if (a[i] >= Max)
		{
			Max = a[i];
			Poz = i;
		}
	}
	
	cout << Max;

	return 0;
}
