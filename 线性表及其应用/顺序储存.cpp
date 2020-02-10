#include <iostream>

using namespace std;

const int Maxsize = 100;
class SeqList
{
public:
	SeqList()
	{
		length = 0;
	}
	SeqList(int *a, int n);
	~SeqList();
	int Length()
	{
		return length;
	}
	int Get(int n);
	int Loacate(int x);
	void Insert(int i, int x);
	int Delete(int i);
	void PrintList();

private:
	int Data[Maxsize];
	int length;
};


int main()
{
	int n;
	
	char flag='a';
	int i;
	SeqList b;
	int temp1, temp2;
	

	for (; flag != 'E';)
	{
		cin >> flag;

		if (flag == 'I')
		{
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cin >> temp1;
				cin >> temp2;
				b.Insert(temp1, temp2);
			}
		}

		if (flag == 'S')
		{
			cin >> temp1;
			temp2 = b.Loacate(temp1);

			if (temp2 == 0)
			{
				cout << "None" << endl;
			}
			else
			{
				cout << temp2 << endl;
			}

		}

		if (flag == 'G')
		{
			cin >> temp1;
			temp2 = b.Get(temp1);
			cout << temp2 << endl;
		}

		if (flag == 'V')
		{
			b.PrintList();
		}

		if (flag == 'D')
		{
			cin >> temp1;

			if ((temp2 = b.Delete(temp1)) != 0)
			{
				cout << temp2 << endl;
			}
			
			
		}
	}

	return 0;
}


SeqList::SeqList(int *a, int n)
{
	int i;

	if (n > Maxsize)
	{
		cout << "位置非法" << endl;
	}
	for (i = 0; i < n; i++)
	{
		Data[i] = a[i];
	}
	length = n;
}


SeqList::~SeqList()
{
}

int SeqList::Get(int i)
{

	if (i<1 && i>length)
	{
		cout << "位置不正确" << endl;
	}
	else
	{
		return Data[i - 1];
	}

}

int SeqList::Loacate(int x)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (Data[i] == x)
		{
			return i + 1;
		}
	}

	return 0;
}

int SeqList::Delete(int i)
{
	int x;
	int j;

	if (length == 0)
	{
		cout << "下溢" << endl;
		return 0;
	}
	else if (i<1 || i>length)
	{
		cout << "位置非法" << endl;
		return 0;
	}
	else
	{
		x = Data[i - 1];
		for (j = i; j < length; j++)
		{
			Data[j - 1] = Data[j];
		}
		length--;
		return x;
	}

	
}

void SeqList::PrintList()
{
	int i;
	for (i = 0; i < length; i++)
	{
		cout << Data[i] << endl;
	}
}

void SeqList::Insert(int i, int x)
{

	int j;
	cout <<length;
	for (j = length; j >= i; j--)
	{
		Data[j] = Data[j - 1];
	}

	Data[i - 1] = x;
	length++;
}
