#include<iostream>

using namespace std;

struct Node
{
	char string;
	Node *next;
};

class LinkStack
{
	public:
		
		LinkStack()
		{
			top = NULL;
		}
		
		~LinkStack(){}
		
		void Push(char x)     //��ջ 
		{
			Node *s = new Node;
			s->string = x;
			s->next = top;
			top = s; 
		}
		
		char Pop()        //����ջ��Ԫ�� 
		{
			char x;
			Node *p;
			
			x = top->string;
			p = top;
			top = top->next;
			
			delete p;
			return x;
			
		} 
		
		char GetTop()    //ȡջ��Ԫ�� 
		{
			return top->string;
		}
		
		void Empty()   //���ջ 
		{
			top = NULL;
		}
		
		int JudEmp()  //�ж�ջ�Ƿ�Ϊ�� 
		{
			if (top == NULL)
			{
				return 1;
			}
			
			else
			{
				return 0;
			}
		}
		
	private:
		Node *top;
};

int main()
{
	char option;
	char element;
	LinkStack A;
	
	while(1)
	{
		cin >> option;
		
		switch(option)
	        {
	        	case 'P':
	        		cin >> element;
	        		A.Push(element);
	        		
	        		break;
	        		
	        	case 'D':
	        		
	        		if (A.JudEmp() == 1)
					{
						cout << "None" << endl;
					} 
					
					else
					{
						cout << A.Pop() << endl;
					}
	    
	        		break;
	        		
	        	case 'G':
	        		
	        		if (A.JudEmp() == 1)
	        		{
	        			cout << "None" << endl;
					}
					
					else
					{
						cout << A.GetTop() << endl;
					}
	        		
	        		break;
	        		
	        	case 'T':
				    A.Empty();
				    
				    break;
				    
				case 'Y':
					
					if (A.JudEmp() == 1)
					{
						cout << "Yes" << endl;
					}
					
					else
					{
						cout << "No" << endl;
					}
	        		
	        		break;
	        	
	        	case 'E':
	        		break;
	        }
	        
	        if (option == 'E')
	        {
	        	break;
			}
	}
	
	return 0;
	
}
