#include <iostream>

using namespace std;

class Date
{
public:
	Date(){top = 0;}
	void P();
	void D();
	void G();
	void T();
	void Y();
private:
	int a[10];
	int top;
};

void Date::Y()
{
	if(a[top] == 0 && top ==0)
	{
		cout << "Yes" <<endl;
	}
	else
	{
		cout << "No" <<endl;
	}
}

void Date::P()
{
	int b;
	cin >> b;
	a[top] = b;
	top++;
}

void Date::D()
{
	if(a[top] == NULL && top ==0)
	{
		cout << "None" <<endl;
	}
	else
	{
		cout << a[top-1] << endl;
		a[top-1] = NULL;
		top--;

	}
}

void Date::G()
{
	if(a[top] == 0 && top ==0)
	{
		cout << "None" <<endl;
	}
	else
	{
		cout << a[top-1] << endl;
	}
}

void Date::T()
{
	for(top--; top == -1;top--)
	{
		a[top] = 0;
	}
	top = 0;
}

int main()
{
	char a;
	Date A;
	while(1)
	{
		cin >> a;
		if(a == 'P')
		{
			A.P();
		}
		else if(a == 'D')
		{
			A.D();
		}
		else if(a == 'G')
		{
			A.G();
		}
		else if(a == 'T')
		{
			A.T();
		}
		else if(a == 'Y')
		{
			A.Y();
		}
		else if(a == 'E')
		{
			break;
		}
	}

	return 0;
}

