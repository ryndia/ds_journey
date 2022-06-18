#include <iostream>
#include <bits/stdc++.h>
#include <assert.h>
#define null 0

using namespace std;

class node{
public:
	int data;
	node * next;

	node(int x){
	data = x;
	next= nullptr;
	}
};

void push(node **headref,int data)
{
	node *head= *headref;
	node * temp = new node(data);
	temp->next= *headref;
	
	if(*headref!= nullptr)
	{
		while(head->next!=*headref){
			head= head->next;
		}
		head->next=temp;
	}
	else
	{
		temp ->next= temp;
	}
	*headref=temp;
	return;
}

void printlist(node *headref)
{
	node * first = headref;
	do
	{
		cout<<headref->data<<" ";
		headref=headref->next;
	}
	while(headref!= first);
	cout<<endl;

	return;
}

void splitList(node *head, node **head1_ref, 
                           node **head2_ref)  
{
    node *slow_ptr = head;  
    node *fast_ptr = head;  
      
    if(head == NULL)  
        return;  

    while(fast_ptr->next != head &&  
          fast_ptr->next->next != head)  
    {  
        fast_ptr = fast_ptr->next->next;  
        slow_ptr = slow_ptr->next;  
    }  
      

    if(fast_ptr->next->next == head)  
        fast_ptr = fast_ptr->next;  
          
    *head1_ref = head;
          
    if(head->next != head)  
        *head2_ref = slow_ptr->next;  
          

    fast_ptr->next = slow_ptr->next;  

    slow_ptr->next = head;  
    return;
}

void sorted_insert(node **headref,int data)
{
	node *temp = new node(data);
	node *head = *headref;
	node *current = *headref;
	node *prev = *headref;

	if(head==nullptr){
		*headref = temp;
		return;
	}

	if(data<=head->data){
		while(current->next!= head){
			current = current->next;
		}
		current->next= temp;
		temp->next = head;
		*headref = temp;
		return;
	}

	while(current->next != head){
		if(data< current->data){
			prev->next = temp;
			temp->next= current;
			return;
		}
		prev = current;
		current = current->next;
	}
	current->next = temp;
	temp -> next = head;
	return;
}

void loop_Detection(node *head)
{

	node*current = head;

	while(current->next!= head&&current->next!= null){
		current = current->next;
	}

	if(current->next == head){
		cout<<"loop Detected\n";
	}
	else
	{
		cout<<"loop not Detected\n";	
	}
}

void delete_node(int key, node **headref)
{
	node *head = *headref;
	node *temp = *headref;
	node *prev = *headref;

	if(head != null){
		
		if(head->data==key){
			while(temp->next!=head){
				temp = temp->next;
			}
			temp->next = head->next;
			*headref=head->next;
			delete head;
			return;
		}
		else{
			while(temp->next != head){
				if(key==temp->data){
					prev->next = temp->next;
					delete temp;
					return;
				}
				prev = temp;
				temp = temp->next;
			}
			prev->next = head;
			delete temp;
			return;
		}
	}
	else{
		return;
	}
}

void countNode(node *head)
{
	node *temp = head;
	int count = 0;

	do{

		count++;
		temp = temp->next;
		
	}while(temp->next!= head);
	cout<<"count: "<<count<<endl;
}

void singlyToCircular(node **singly,node **circular)
{
	node *s = *singly;
	while(s->next!=null){
		s=s->next;
	}
	s->next= *singly;
	*circular=s;
	return;
}

void swap(node **headref)
{
	node * head = *headref;
	
	if(head->next->next == head)
	{
		*headref=head->next;
		return;
	}

	node * temp= * headref;
	node *prev = nullptr;
	
	 while(temp->next!= head)
	 {
	 	prev = temp;
	 	temp = temp ->next;
	 }
	 temp->next = head->next;
	 head->next = temp;
	 prev->next = head;
	 *headref = temp;
	 return;
}

int main()
{
	node * head = new node(7);
	node *head1=nullptr;
	node *head2=nullptr;

	head->next=head;
	push(&head,6);
	push(&head,5);
	//push(&head,4);
	//push(&head,3);
	//push(&head,2);
	//push(&head,1);
	//printlist(head);
	//sorted_insert(&head,8);
	swap(&head);
	printlist(head);
	//countNode(head);
	//printlist(head);
	//delete_node(4,&head);
	//printlist(head);
	//delete_node(1,&head);
	//printlist(head);
	//delete_node(8,&head);
	//printlist(head);
	//splitList(head,&head1,&head2);
	//printlist(head1);
	//printlist(head2);
	//loop_Detection(head);
	
}