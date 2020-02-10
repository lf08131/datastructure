#include<iostream>

using namespace std;

class CirQueue
{
	public:
		
		CirQueue()     
		{
			front = rear = 99;
		}
		
		~CirQueue(){}
		
		void EnQueue(char x)               //��� 
		{
			rear = (rear+1)%100;
			element[rear] = x;
		}
		
		char DeQueue()     //���׳��� 
		{
			front = (front+1)%100;
			return element[front];
		}
		
		char GetQueue()    //������ 
		{
			int i;
			
			i = (front+1)%100; 
			return element[i];
		}
		
		void Empty()        //��ն��� 
		{
			front = rear;
	    }
	    
	    int JudEmp()   //�ж϶ӿ� 
	    {
	    	if(front == rear)
	    	{
	    		return 1;   //�ӿ�Ϊ1 
			}
			
			else
			{
				return 0;
			}
		}
		
	protected:
		
		char element[100];
		int front, rear;
};	

int main()
{
	char option;
	char x;
	CirQueue A;
	
	while(1)
	{
		cin >> option;
		
		switch(option)
		{
			case 'C':
				A.Empty();
				
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
				
			case 'E':
			    cin >> x;
			    A.EnQueue(x);
			    
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

