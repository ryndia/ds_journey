#include <iostream>

using namespace std;

class Queue
{
public:
	int front, rear,size;
	int *arr;

	Queue(int s)
	{	
		int size = s;
		rear = front = -1;
		arr = new int[s];
	}	

	void enQueue(int data)
	{
		if(front == 0 && rear == size - 1)
		{
			cout<<"full queue"<<endl;
		}
		else if(front == -1)
		{
			rear = front = 0;
			arr[rear] = data;
		}
		else if(front != 0 and rear == size - 1)
		{
			rear = 0;
			arr[rear] = data;
		}
		else
		{
			rear++;
			arr[rear] = data;
		}
	}

	int deQueue()
	{
		 if(front == -1 && rear == -1)
		 {
		 	cout<<"empty queue"<<endl;
		 	return 0;
		 }
		 int data = arr[front];

		 if(front == rear)
		 {
		 	rear = front = -1;
		 }
		 else if(front == size - 1)
		 {
		 	front = 0;
		 }
		 else
		 {
		 	front++;
		 }
		 return data;
	}

	void displayQueue()
	{
		if(front <=rear)
		{
			for(int i = front; i<= rear; i++)
			{
				cout<<arr[i]<<endl;
			}
		}
		else
		{
			for(int i = front; i < size; i++)
			{
				cout<<arr[i]<<endl;
			}
			for(int i = 0; i <=rear;i++)
			{
				cout<<arr[i]<<endl;
			}
		}
	}
};


int main()
{
	Queue q(6);
	q.enQueue(1);
	q.enQueue(6);
	q.enQueue(2);
	q.deQueue();
	q.displayQueue();
	q.enQueue(3);
	q.displayQueue();

}