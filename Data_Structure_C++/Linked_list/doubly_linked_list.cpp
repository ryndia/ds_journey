#include <iostream>
#include <cstring>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node *prev;

	node(int data)
	{
		this->data = data;
		this->prev = nullptr;
		this->next = nullptr;
	}
};

void push(node **headref, int data)
{
	node* temp = new node(data);
	node *head = *headref;

	if(head == nullptr)
	{
		*headref= temp;
		return;
	}

	head->prev = temp;
	temp ->next = head;
	*headref = temp;
	return;
}

void printlist(node * head)
{
	while(head != nullptr)
	{
		cout<<head->data;//<<" ";
		head = head->next;
	}
	cout<<endl;
	return;
}

void add(node **headref, int data)
{
	node *head = *headref;
	node *temp = new node (data);

	if(head == nullptr){
		*headref = temp;
		return;
	}

	while(head->next!=nullptr){
		head = head->next;
	}
	head->next =temp;
	temp -> prev = head;

	return;
}

void insert( node  **headref,int d,int key)
{
	node *head = *headref;
	node * temp = new node (d);
	
	if(head->data == key){
	head->prev = temp;
	temp ->next = head;
	*headref = temp;
	return;
	}

	head = head->next;

	while(head!=nullptr){
		if(head->data == key){
			temp ->prev =head->prev;
			head->prev->next = temp;
			head->prev = temp;
			temp->next = head;
			return;
		}
		head = head->next;
	}
		cout<<"key not found"<<endl;
}

void InsertSort( node  **headref,int d)
{
	node *head = *headref;
	node * temp = new node (d);
	
	if(head->data  >=d){
	head->prev = temp;
	temp ->next = head;
	*headref = temp;
	return;
	}

	head = head->next;

	while(head!=nullptr){
		if(head->data >= d){
			temp ->prev =head->prev;
			head->prev->next = temp;
			head->prev = temp;
			temp->next = head;
			return;
		}
		head = head->next;
	}
}

void deleteposition(node **headref,int position)
{
	node*temp = *headref;
	node *prev = nullptr;
	int i = 1;

	if(position == 1)
	{
		*headref= temp->next;
		delete temp;
		return;
	}

	while(position != i && temp != nullptr)
	{
		prev = temp;
		temp = temp -> next;
		i++;
	}

	if(temp == nullptr)
	{
		cout<<"not found\n";
		return;
	}

	prev->next =temp -> next;
	delete temp;
	return;
}

void deleteNode(node **headref, int key)
{
	node * head = *headref;

	if(head->data ==key){
		head->next->prev = nullptr;
		*headref = head->next;
		delete head;
		return;
	}

	head = head->next;

	while(head->next!= nullptr)
	{
		if(head->data == key){
			head->prev->next = head->next;
			head->next->prev = head->prev;
			delete head; 
			return;
		}
		head = head->next;
	}

	if(head->data==key)
	{
		head->prev->next = nullptr;
		delete head;
		return;
	}

	cout<<"key not found"<<endl;
}

void size(node *head)
{
	node *temp = head;
	int counter = 0;
	while(temp != nullptr)
	{
		temp = temp->next;
		counter++;
	}

	cout<<"size: "<<counter<<endl;
	return;
}

void deleteoccur(node **headref, int key)
{
	node *head = *headref;
	node *temp = nullptr;

	if(head->data==key)
	{
		while(head->data == key)
		{
			temp= head->next;
			head->next->prev = nullptr;
			delete head;
			head=temp;
		}
		*headref= head;
		return;
	}

	while(head!= nullptr)
	{
		if(head->data == key)
		{
			temp = head->next;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			delete head;
			head = temp;

		}
		else{
			head = head->next;
		}
	}
	return;
}

void reverselist(node **headref)
{
	node * current = *headref;
	node * temp = nullptr;


	while(current!= nullptr)
	{
        temp = current->prev; 
        current->prev = current->next; 
        current->next = temp;             
        current = current->prev; 
	}

	if(temp!=  nullptr){
		*headref = temp->prev;
	}

	return;

}

void deletedup(node **headref)
{

	node * head = *headref;
	node * temp = nullptr;

	if(head == nullptr)
	{
		return;
	}

	while(head->next!= nullptr)
	{
		if(head->data == head->next->data)
		{
			temp = head->next->next;
			delete head->next;
			head->next = temp;
			if(temp != nullptr){
			head->next->prev = head;}
		}
		else{
		head= head->next;
		}
	}	
}


int findpair(node * head, node *backward,int key)
{
	node * forward = head;
	int count = 0;

	//while(backward->next != nullptr)
	///{
	//	backward= backward->next;
	//}

	while(backward!= nullptr&& forward!= nullptr&& backward!= forward && backward->next != forward)
	{
		if(backward->data+forward->data == key)
		{
			cout<<backward->data<<" "<<forward->data<<endl;
			count++;
			backward= backward->prev;
			forward=forward->next;
		}
		else if(backward->data+forward->data < key)
		{
			forward = forward->next;
		}
		else
		{
			backward= backward->prev;
		}
	}
	return count;
}

int triplecount(node *head,int num)
{
	node * first = head;
	node * last = head;
	int count = 0;

	while(last->next!= nullptr)
	{
		last = last->next;
	}

	for(node * current = head; current != nullptr; current = current->next)
	{
		first = current;
		count += findpair(first,last,num-current->data);
	}
	cout<< "number of triple: "<<count;
	return count;
}

void reversek(node **headref, int k)
{
	if(k== 1)
	{
		return;
	}

	node * last = *headref;
	int count =  0;
	while(count != k&& last != nullptr)
	{
		last = last->next;
		count++;
	}
	cout<<last->data<<endl;

	node * current = *headref;
	node * temp = nullptr;


	while(current!= last)
	{
        temp = current->prev; 
        current->prev = current->next; 
        current->next = temp;             
        current = current->prev; 
	}

	if(temp!=  nullptr){
		*headref = temp->prev;
	}

	return;
}

void aritmeticAdd(string num1, string num2)
{
	node *n1 = nullptr;
	node *n2 = nullptr;
	node *addition = nullptr;
	int temp = 0;
	int carry = 0;
	for(char c:num1)
	{
		push(&n1,c-48);
	}

	for(char c:num2)
	{
		push(&n2,c-48);
	}

	while(n1!= nullptr && n2!= nullptr)
	{
		temp = n1->data + n2->data+carry;
		carry = temp % 10;
		push(&addition,carry);
		carry = (temp -carry)/10;
		n1= n1->next;
		n2= n2->next;
	}

	while(n1!= nullptr)
	{
		temp = n1->data+carry;
		carry = temp % 10;
		push(&addition,carry);
		carry = (temp -carry)/10;
		n1= n1->next;
	}

	while(n2!= nullptr)
	{
		temp = n2->data+carry;
		carry = temp % 10;
		push(&addition,carry);
		carry = (temp -carry)/10;
		n2= n2->next;
	}

	printlist(n1);
	printlist(n2);
	printlist(addition);
	return;
}

void aritmeticSub(string num1,string num2)
{
	node *n1 = nullptr;
	node *n2 = nullptr;
	node *subtraction = nullptr;
	int temp = 0;
	int comp1,comp2;
	char sign =' ';

	comp1 = num1[0]-48;
	comp2 = num2[0]-48;

	if((num1.length() <num2.length()) ||(num1.length() ==num2.length() && comp2>= comp1) ){
		for(char c:num2)
			{
				push(&n1,c-48);
			}

		for(char c:num1)
			{
				push(&n2,c-48);
			}
		sign ='-';
	}
	else
	{
		for(char c:num1)
			{
				push(&n1,c-48);
			}

		for(char c:num2)
			{
				push(&n2,c-48);
			}
	}

	while(n1!= nullptr && n2!= nullptr)
	{
		if(n1->data < n2->data){
			if(n1->next != nullptr)
			{
				n1->next->data =n1->next->data-1;
				temp = 10-n2->data+n1->data;
				push(&subtraction,temp);
			}}
			else{
				temp = n1->data - n2->data;
				push(&subtraction,temp);
			}	
		n1= n1->next;
		n2= n2->next;	
	}
	while(n1!= nullptr)
	{
		if(n1->data<0){
			n1->next->data = n1->next->data-1;
			temp= n1->data +10;
			push(&subtraction,temp);
		}
		else
		{
			temp= n1->data;
			push(&subtraction,temp);			
		}
		n1 = n1->next;
	}
	cout<<num1<<" - "<<num2<<" =";
	cout<<sign;
	printlist(subtraction);
}

void aritmeticProduct(string num1,string num2)
{
	int carry = 0,temp = 0;
	node *multiplication = new node(0);
	node *n1 = nullptr;
	node *n2 = nullptr;
	node *n1head = nullptr;
	node *mulhead = nullptr;
	mulhead = multiplication;

	for(char c:num1)
		{
			push(&n1,c-48);
		}
	for(char c:num2)
		{
			push(&n2,c-48);
		}
	
	n1head = n1;

	while(n2!= nullptr)
	{
		while(n1!=nullptr)
		{
			carry = ((n1->data*n2->data) + multiplication->data)% 10;
			temp = (((n1->data*n2->data)+multiplication->data)- carry)/10;
			multiplication->data = carry;
			if(multiplication->prev!= nullptr)
				{
					multiplication = multiplication->prev;
					multiplication->data = multiplication->data + temp;
				}
			else
				{
					push(&multiplication,temp);
				}

			n1 = n1->next;
		}
		mulhead = mulhead->prev;
		multiplication = mulhead;
		n2 = n2->next;
		n1 = n1head;
	}

	while(multiplication->prev != nullptr)
	{
		multiplication= multiplication->prev;
	}

	//multiplication = multiplication->prev->prev;
	cout<<num1<<" x "<<num2<<" = "<<endl;
	printlist(multiplication);
}
int main()
{
	//node *head = new node(6);
	//push(&head, 5);
	//push(&head, 5);
	//push(&head, 5);
	//push(&head, 5);
	//push(&head, 4);
	//push(&head, 4);
	//push(&head, 4);
	//add(&head,7);
	//add(&head,7);
	//add(&head,7);
	//add(&head,7);
	//printlist(head);
	//insert(&head,8,2);
	//printlist(head);
	//insert(&head,1,5);
	//printlist(head);
	//insert(&head,4,6);
	//printlist(head);
	//deleteNode(&head,7);
	//printlist(head);
	//reverselist(&head);
	//printlist(head);
	//size(head); 453-384
	//deleteoccur(&head, 4);
	//printlist(head);
	//deletedup(&head);
	//InsertSort(&head,3);
	//InsertSort(&head,5);
	//deleteposition(&head,3);
	//printlist(head);
	//triplecount(head,150);
	//reversek(&head,4);
	//printlist(head);
	//findpair(head, 11);

	//aritmeticSub("5009878675654543564765876986785674563452","9486374526341523513342454356546765877567486544534243799");
	aritmeticProduct("7685674563452345246326451246235373468575746354253142432534654765874563452341325408078967856475364253143254365476587847364235465768989678564753646587678564753654658768986785647657586757678567587678567587698873654764536342523265746","756453423124354365476587698798876564534354365476587698709882335476587698797867856768576867675676576765657465756765748657875846864680778653423124325426547368547567456346547658769785674563452309876543233454567876543233465765876987978567576897678425436547658769785674658769785674563465475876987856745636534764");
}