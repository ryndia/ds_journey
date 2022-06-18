#include <iostream>
#include <bits/stdc++.h>
#include <assert.h>
#define null 0

using namespace std;

class node{
public:
	int data;
	node *next;

	node(int x){
		data =x;
		next = nullptr;
	}
};

void printlist(node *list)
{
	while(list != null){
		cout<<list->data<<" ";
		list = list->next;
	}
	cout<<endl;
	return;
}

void push(node **headref,int data)
{
	node *temp = new node(data);
	temp->next= *headref;
	*headref=temp;
}

void append(node **list,int data)
{
	node * temp = new node(data);
	node *last = *list;

	if(*list==null){
		*list=temp;
		return;
	}

	while(last->next != null){
		last = last->next;
	}
	last->next=temp;

	return;
}

void deletenode(node **headref,int key)
{
	node*temp = *headref;
	node *prev= nullptr;

	if(temp!= null && temp->data==key){
		*headref=temp->next;
		delete temp;
		return;
	}

	while(temp!=null && temp->data!=key)
	{
		prev=temp;
		temp = temp->next;
	}

	if(temp ==null){
		cout<<"node not found\n";
		return;
	}

	prev->next=temp->next;
	delete temp;
	return;
}

void deleteposition(node **headref,int position)
{
	node*temp = *headref;
	node *prev = nullptr;
	int i = 0;

	if(position == 0)
	{
		*headref= temp->next;
		delete temp;
		return;
	}

	while(position != i && temp != null)
	{
		prev = temp;
		temp = temp -> next;
		i++;
	}

	if(temp == null)
	{
		cout<<"not found\n";
		return;
	}

	prev->next =temp -> next;
	delete temp;
	return;
}

void deletelist(node **headref)
{
	node *temp = *headref;
	node *temp1= nullptr;
	while(temp !=null)
	{
		temp1= temp;
		delete temp;
		temp= temp1->next;

	}
	delete *headref;
	delete temp1;
	return;
}

void findlength(node ** headref)
{
	node*temp = *headref;
	int i = 0;
	while(temp!= null)
	{
		temp = temp->next;
		i++;
	}
	cout<<"length: "<<i<<endl;
	return;
}

void recursivelength(node*headref,int i=0)
{
	if(headref== null)
	{
		cout<<"length: "<<i<<endl;
		return;
	}
	i++;
	recursivelength(headref->next,i);
	return;
}

void search(node *headref,int key)
{
	if(headref->data== key){
		cout<<"element found"<<endl;
		return;
	}
	while(headref!=null)
	{
		if(headref->data== key){
			cout<<"element found\n";
			return;}
		headref=headref->next;
	}
	cout<<"element not found\n";
	return;
}

void recursivesearch(node*headref,int key)
{
	if(headref==null)
	{
		cout<<"not found\n";
		return;
	}
	if(headref->data==key)
	{
		cout<<"found\n";
		return;
	}
	recursivesearch(headref->next,key);
	return;
}

void findNnode(node*headref,int index)
{
	int i = 0;
	while(headref!=null)
	{
		if(i==index){
			cout<<headref->data;
			return;
		}
		headref= headref->next;
		i++;

	}
	return;
}

void getnth(node * headref,int index)
{
	int i = 0;
	if(headref==null)
	{
		cout<<"node index exceed linked list size\n";
		return;
	}
	if(i==index)
	{
		cout<<headref->data<<endl;
		return;
	}
	getnth(headref->next,index-1);
	return;
}

void printNthFromLast(node ** headref,int position)
{
	node*temp = *headref;
	int i = 0;
	while(temp!= null)
	{
		temp = temp->next;
		i++;
	}
	temp = *headref;
	if(position<i){
	getnth(temp,(i-position-1));
	}
	return;
}

void printmiddle(node **headref)
{
	node*temp = *headref;
	int size = 0;
	while(temp!= null)
	{
		temp = temp->next;
		size++;
	}
	int middle = int((size)/2);
	temp = *headref;
	findNnode(temp,middle);
	return;
}

void occurtime(node *headref,int key)
{
	int occur=0;
	while(headref!= null)
	{
		if(headref->data==key)
		{
			occur++;
		}
		headref=headref->next;
	}
	cout<<"number of time occur: "<<occur<<"\n";
	return;

}

void loopdetection(node *headref)
{
	node *slow_p= headref;
	node *fast_p= headref;
	while(slow_p && fast_p && fast_p->next){
		slow_p=slow_p->next;
		fast_p=fast_p->next->next;
		if(fast_p==slow_p){
			cout<<"loop detected"<<endl;
			return;
		}
	}
	cout<<"no loop "<<endl;
	return;
}

void lenghloop(node *headref){

	int count=0;
	node *slow_p= headref;
	node *fast_p= headref;

	while(slow_p && fast_p && fast_p->next){

		slow_p=slow_p->next;
		fast_p=fast_p->next->next;
		count++;
		if(fast_p==slow_p){
			cout<<"length: "<<count<<endl;
			return;
		}
		
	}
	cout<<"length: "<<count<<endl;

	return;

}

void palindrumdetection(node *headref)
{
	return;	
}

void deleteduplicate(node **headref)
{
	node * temp = *headref;
	node * temp1= nullptr;

	if(temp ==null){
		cout<<"empty"<<endl;
		return;
	}
	while(temp->next!= null)
	{
		if(temp->data==temp->next->data)
		{
			temp1 =temp->next->next;
			delete temp->next;
			temp->next = temp1;
		}
		else
		{
			temp=temp->next;
		}

	}
	return;
}

void removeduplicate(node **headref)
{
	node * temp = *headref;
	node * temp1= nullptr;
	node * temp2= nullptr;

	while(temp!=null&&temp->next!=null)
	{
		temp1=temp;
		while(temp1->next!= null)
	{
			if(temp->data==temp1->next->data)
			{
				temp2 = temp1->next;
				temp1->next =temp1->next->next;
				delete temp2;
			}
			else{
			temp1= temp1->next;
			}
	}
	temp = temp->next;
	}
	return;
}

void swapelement(node **headref,int key,int key2)
{
	node *temp = *headref;
	node *ptr1 = nullptr;
	node *ptr2 = nullptr;
	node *prev1 = *headref;
	node *prev2 = *headref;
	node *temporaly = nullptr;

	if(key==key2)
	{
		cout<<"exact value no swap"<<endl;
		return;
	}
	if(temp->data==key){
		ptr1= temp;
		while(temp!=null)
		{
			if(temp->data== key2){
				ptr2= temp;
				if(ptr2->next==null)
				{
					prev2->next=ptr1;
					ptr2->next= ptr1->next;
					ptr1->next=nullptr;
					return;
				}
				else
				{
					temporaly = ptr1->next;
					prev2->next= ptr1;
					ptr1->next=ptr2->next;
					ptr2->next=temporaly;
					temp=ptr2;
					return;
				}
			}
			prev2 = temp;
			temp=temp->next;
		}
		cout<<"element not found\n";
		return;
	}
	if(temp->data==key2){
		ptr2= temp;
		while(temp!=null)
		{
			if(temp->data== key){
				ptr1= temp;
				if(ptr1->next==null)
				{
					prev1->next=ptr2;
					ptr1->next= ptr2->next;
					ptr2->next=nullptr;
					return;
				}
				else
				{
					temporaly = ptr2->next;
					prev1->next= ptr2;
					ptr2->next=ptr1->next;
					ptr1->next=temporaly;
					temp=ptr1;
					return;
				}
			}
			prev1 = temp;
			temp=temp->next;
		}
		cout<<"element not found\n";
		return;
	}
}

int main()
{
	node *head = new node(6);
	node *middle = new node(7);
	node *last= new node(8);
	head->next=middle;
	middle->next = last;

	

	
	
	push(&head,5);
	
	push(&head,4);
	push(&head,3);

	push(&head,2);
	push(&head,1);
	push(&head,0);
	printlist(head);


	swapelement(&head,0,7);
	//removeduplicate(&head);
	/*last->next=head; use to test loop detection else program crash if call other function due to no null detection*/
	//deleteduplicate(&head);
	printlist(head);

	/*push(&head,0);
	printlist(head);

	append(&head,0);
	printlist(head);*/

/*	loopdetection(head);
	lenghloop(head);*/

	/*deletenode(&head,3);
	printlist(head);
	
	deleteposition(&head,2);
	printlist(head);
	
	findlength(&head);

	recursivelength(head);

	search(head,5);

	recursivesearch(head,4);

	getnth(head,3);

	findNnode(head,2);
	
	printNthFromLast(&head,0);

	printmiddle(&head);

	occurtime(head,0);
	//deletelist(&head);
	//printlist(head);*/

}