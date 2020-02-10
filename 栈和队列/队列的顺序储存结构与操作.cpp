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
		
		void EnQueue(char x)               //入队 
		{
			rear = (rear+1)%100;
			element[rear] = x;
		}
		
		char DeQueue()     //队首出队 
		{
			front = (front+1)%100;
			return element[front];
		}
		
		char GetQueue()    //读队首 
		{
			int i;
			
			i = (front+1)%100; 
			return element[i];
		}
		
		void Empty()        //清空队列 
		{
			front = rear;
	    }
	    
	    int JudEmp()   //判断队空 
	    {
	    	if(front == rear)
	    	{
	    		return 1;   //队空为1 
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

