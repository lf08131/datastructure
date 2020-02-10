#include<iostream>

using namespace std;

struct Node
{
	char data;
	Node *next;
};

class LinkQueue
{
	public:
		LinkQueue()            //����һ���յ���ʽ���� 
		{
			Node *s;
			s = new Node;
			s->next = NULL;
			front = rear = s;
		}
		
		~LinkQueue(){}
		 
		void EnQueue(char x)  //��� 
		{
			Node *p;
			p = new Node;
			p->data = x;
			p->next = NULL;
			rear->next = p; //�����嵽��β 
			rear = p;
			if (front == rear)
			{
			   cout << "123" <<endl;
			}
		}
		
		char DeQueue()
		{
			char temp;
			Node *p;
			
			p = new Node;
			p = front->next;
			temp = p->data;
			front->next = p->next;   //����ͷԪ��ժ�� 
			
			if (p->next == NULL)
			{
				rear = front;
			}
			
			delete p;
			return temp; 
		}
		
		char GetQueue()
		{
			return front->next->data;
		}
		
		void Empty()
		{
			front = rear;
		}
		
		int JudEmp()
		{
			if (front == rear)
			{
				return 1;
			}
			
			else
			{
				return 0;
			}
		}
		
	protected:
		Node *front;
		Node *rear;
};

int main()
{
	char data;
	char option;
	LinkQueue A;
	
	while(1)
	{
		cin >> option;
		
		switch(option)
		{
			case 'E':
				cin >> data;
				
				A.EnQueue(data);
				
				break;
				
			case 'D':
				
				if(A.JudEmp() == 1)
				{
					cout << "None" << endl; 
				}
				
				else
				{
					cout << A.DeQueue() << endl;
				}
				
				break;
				
			case 'G':
				
				if(A.JudEmp() == 1)
				{
					cout << "None" << endl; 
				}
				
				else
				{
					cout << A.GetQueue() << endl;
				}
				
				break;
				
			case 'C':
				
				A.Empty();
				
				break;
				
			case 'Q':
			   
			    break; 
			    
			default:
				
				break;
		}
		
		if (option == 'Q')
		{
			break;
		}
	}
	
	return 0;
}  

