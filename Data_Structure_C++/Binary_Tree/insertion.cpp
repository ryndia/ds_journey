#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Binary_tree
{
public:
	int data;
	Binary_tree *left;
	Binary_tree *right;
	Binary_tree(int d)
	{
		this->data = d;
		left = nullptr;
		right= nullptr;
	}
};

Binary_tree *temp = nullptr;

void insert(Binary_tree **root, int data)
{
	Binary_tree *temp = new Binary_tree(data);

	if(*root == nullptr)
	{
		*root = temp;
		return;
	}

	queue <Binary_tree*> q;
	q.push(*root);

	while(!q.empty())
	{
		Binary_tree* roottemp = q.front();
		q.pop();
		if(roottemp->left!= nullptr)
		{
			q.push(roottemp->left);
		}
		else
		{
			roottemp->left = temp;
			return;
		}

		if(roottemp->right != nullptr)
		{
			q.push(roottemp->right);
		}
		else
		{
			roottemp->right = temp;
			return;
		}
	}
}

//deletion

int continuous(Binary_tree *root)
{
	if(root == nullptr)
	{
		return 1;
	}

	queue <Binary_tree*> q;
	q.push(root);

	while(!q.empty())
	{
		Binary_tree*temp = q.front();
		q.pop();
		if(temp->left !=nullptr)
		{
			if(temp->data - temp->left->data != 1 && temp->data - temp->left->data != -1)
			{
				return 0;
			}
			else
			{
				q.push(temp->left);
			}
		}
		if(temp->right !=nullptr)
		{
			if(temp->data - temp->right->data != 1 && temp->data - temp->right->data != -1)
			{
				return 0;
			}
			else
			{
				q.push(temp->right);
			}
		}
	}
	return 1;
}

//need to renew
void foldable(Binary_tree * root)
{
	queue <Binary_tree*> lefttree;
	queue <Binary_tree*>righttree;
	righttree.push(root->right);
	lefttree.push( root->left);
	queue<int>rt;
	queue<int>lt;

	while(!lefttree.empty())
	{
		Binary_tree * temp = lefttree.front();
		lefttree.pop();
		if(temp->left != nullptr)
		{
			lt.push(1);
			lefttree.push(temp->left);
		}
		else
		{
			lt.push(0);
		}
		if(temp->right != nullptr)
		{
			lt.push(1);
			lefttree.push(temp->right);
		}
		else
		{
			lt.push(0);
		}
	}
	while(!righttree.empty())
	{
		Binary_tree * temp = righttree.front();
		righttree.pop();
		if(temp->left != nullptr)
		{
			rt.push(1);
			righttree.push(temp->left);
		}
		else
		{
			rt.push(0);
		}
		if(temp->right != nullptr)
		{
			rt.push(1);
			righttree.push(temp->right);
		}
		else
		{
			rt.push(0);
		}
	}
}

void printinorder(Binary_tree *root)
{
	if(root == nullptr)
		return;

	printinorder(root->left);
	cout<<root->data<<endl;
	printinorder(root->right);
}

void printpreorder(Binary_tree *root)
{
	if(root == nullptr)
	{
		return;
	}

	cout<<root->data;
	printpreorder(root->left);
	printpreorder(root->right);
}

void printpostorder(Binary_tree *root)
{
	if(root == nullptr)
	{
		return;
	}
	printpostorder(root->left);
	printpostorder(root->right);
	cout<<root->data;
}

void printst(Binary_tree *root)
{
	stack <Binary_tree*> s;
	Binary_tree *temp = root;
	while(temp != nullptr || !s.empty())
	{
		while(temp != nullptr)
		{
			s.push(temp);
			temp = temp->left;
		}
		temp = s.top();
		cout<<temp->data<<endl;
		temp = temp->right;
		s.pop();
	}
}

void moristraversal(Binary_tree *root)
{
	if(root == nullptr)
	{
		return;
	}

	Binary_tree *previous = nullptr;
	Binary_tree *current = root;

	while(current != nullptr)
	{	
		if(current->left == nullptr)
		{
			cout<<current->data<<' ';
			current = current->right;
		}
		else
		{
			previous = current->left;
		
			while(previous->right != nullptr && previous->right != current)
			{
				previous = previous->right;
			}

			if(previous->right == nullptr)
			{
				previous->right = current;
				current = current->left;
			}
			else
			{
				cout<<current->data<<' ';
				previous->right = nullptr;
				current= current->right;
			}
		}
	}
}
void inordersumrep(Binary_tree **root, vector<int> &v, int *i)
{
	if(*root == nullptr)
	{
		return;
	}
	inordersumrep(&((*root)->left),v,i);
	(*root)->data = v[*i-1] + v[*i+1];
	++*i;
	cout<<endl<<i<<endl;
	inordersumrep(&((*root)->right),v,i);

}

void storeinorder(Binary_tree *root, vector <int> &v)
{
	if(root == nullptr)
		{
			return;
		}

	storeinorder(root->left,v);
	v.push_back(root->data);
	storeinorder(root->right,v);
}

void pushzero(Binary_tree ** root)
{
	vector<int> v;
	v.push_back(0);
	storeinorder((*root),v);
	v.push_back(0);
	int i = 1;
	inordersumrep(&(*root),v,&i);
}

/*
Binary_tree *nodesearch(Binary_tree *root, int node)
{
	if(root->data == node)
	{
		return root;
	}
	return nodesearch(root->left,node);
	return nodesearch(root->right,node);
}

Binary_tree* findInorderRecursive(Binary_tree* root, Binary_tree* x )
{
    if (!root)
        return NULL;
 
    if (root==x || (temp = findInorderRecursive(root->left,x)) ||
                   (temp = findInorderRecursive(root->right,x)))
    {
        if (temp)
        {
            if (root->left == temp)
            {
                cout << "Inorder Successor of " << x->data;
                cout << " is "<< root->data << "\n";
                return NULL;
            }
        }
 
        return root;
    }
 
    return NULL;
}

void utility(Binary_tree *root, int node)
{
	Binary_tree *temp = nodesearch(root,node);
	cout<<temp->data<<endl;
	if(temp->right != nullptr)
	{
		temp = temp->right;
		while(temp->left != nullptr)
		{
			temp = temp->left;
		}
		cout<<"sucessor: "<<temp->data<<endl;
		return;
	}
	else
	{
		Binary_tree *roottemp = root;
		while(roottemp->right != nullptr)
		{
			roottemp = roottemp->right;
		}
		if(roottemp == temp)
		{
			cout<<"null"<<endl;
			return;
		}
		//findInorderRecursive(root,temp);
	}
}
*/

void nsearch(Binary_tree *root, int n)
{
	if(root == nullptr)
	{
		return;
	}
	static int count = 0;

	if(count<=n)
	{
		nsearch(root->left,n);
		count++;
		if(count == n)
		{
			cout<<root->data<<endl;
			return;
		}
		nsearch(root->right,n);
	}

}

void nsearchpost(Binary_tree *root, int n)
{
	if(root == nullptr)
	{
		return;
	}
	static int count = 0;
	if(count <=n)
	{
		nsearchpost(root->left,n);
		nsearchpost(root->right,n);
		count++;
		if(count == n)
		{
			cout<<root->data<<endl;
			return;
		}
	}
}

void levelOrdering(Binary_tree *root)
{
	if(root == nullptr)
	{
		return;
	}
	queue<Binary_tree*> q;
	q.push(root);
	while(!q.empty()){
		Binary_tree *temp = q.front();
		q.pop();
		cout<<temp->data;
		if(temp->left != nullptr)
		{
			q.push(temp->left);
		}
		if(temp->right != nullptr){
			q.push(temp->right);
		}
	}
}

int height(Binary_tree *root)
{
	if(root == nullptr)
	{
		return 0;
	}

	int lh = height(root->left);
	int rh = height(root->right);

	if(lh > rh)
	{
		return (lh + 1);
	}
	else
	{
		return (rh + 1);
	}
}

void printlevel(Binary_tree *root, int i, bool rev)
{
	if(root == nullptr){
		return;
	}
	if(i == 1)
	{
		cout<<root->data;
	}
	else if( i > 1)
	{
		if(!rev)
		{
			printlevel(root->left,i - 1,rev);
			printlevel(root->right,i - 1,rev);
		}
		else
		{
			printlevel(root->right,i - 1,rev);
			printlevel(root->left,i - 1,rev);
		}
	}
}

void printspiral(Binary_tree *root)
{
	int j = 0;
	bool rev = false;
	for(int i = 1; i <= height(root);i++)
	{
		printlevel(root,i,rev);
		cout<<endl;
		//if( i%2 == 0){rev = true;}
		j++;
		if(j == 2)
		{
			rev = true;
			j = 0;
		}
	}
}

 void printreverse(Binary_tree *root)
 {
 	bool rev = false;
 	for(int i = height(root); i > 0; i--)
 	{
 		printlevel(root,i,rev);
 		cout<<endl;
 	}
 }

/*
vector<Binary_tree*> findpath(Binary_tree *root,int data)
{
	if(root->data == data)
	{
		vector<Binary_tree*> v;
		return v.push_back(root);
	}
	findpath(root,data);
}*/
/*
void printleftright(Binary_tree *root)
{
	queue<deque<Binary_tree*>> q;
	deque<Binary_tree*> dq;
	deque<Binary_tree*> temp2;

	dq.push_back(root);
	q.push(dq);
	int i = 1;

	while(!q.empty())
	{
		dq = q.front();
		q.pop();
		while(!dq.empty())
		{
			if(i%2 != 0)
			{
				Binary_tree *temp = dq.front();
				cout<<temp->data;
				dq.pop_front();
			}
			else
			{
				Binary_tree *temp = dq.back();
				cout<<temp->data;
				dq.pop_back();
			}

			if(temp->left != nullptr)
			{
				temp2.push_back(temp->left);
			}
			if(temp->right != nullptr)
			{
				temp2.push_back(temp->right);
			}
			i++;
		}
		q.push(temp2);
		temp2.clear();
		i = 1;
	}
}*/

void printperfect(Binary_tree *root)
{
	if(root == nullptr)
	{
		return;
	}
	cout<<root->data<<" ";
	if(root->left != nullptr)
	{
		cout<<root->left->data<<" "<<root->right->data<<" ";
	}
	if(root->left->left == nullptr)
	{
		return;
	}
	Binary_tree* first = nullptr,*second = nullptr;
	queue<Binary_tree *>q;
	q.push(root->left);
	q.push(root->right);

	while(!q.empty())
	{
		first = q.front();
		q.pop();
		second = q.front();
		q.pop();

		cout<<first->left->data<<" "<<second->right->data<<" ";
		cout<<first->right->data<<" "<<second->left->data<<" ";

		if(first->left->left != nullptr)
		{
			q.push(first->left);
			q.push(second->right);
			q.push(first->right);
			q.push(second->left);
		} 
	}
}

void printperfectRev(Binary_tree *root)
{
	stack <Binary_tree*>s;
	if(root == nullptr)
	{
		return;
	}
	s.push(root);
	if(root->left != nullptr)
	{
		s.push(root->right);
		s.push(root->left);
	}
	if(root->left->left == nullptr)
	{
		return;
	}
	Binary_tree* first = nullptr,*second = nullptr;
	queue<Binary_tree *>q;
	q.push(root->left);
	q.push(root->right);

	while(!q.empty())
	{
		first = q.front();
		q.pop();
		second = q.front();
		q.pop();

		s.push(second->left);
		s.push(first->right);
		s.push(second->right);
		s.push(first->left);
		

		if(first->left->left != nullptr)
		{
			q.push(first->left);
			q.push(second->right);
			q.push(first->right);
			q.push(second->left);
		} 
	}

	while(!s.empty())
		{
			cout<<(s.top())->data<<" ";
			s.pop();
		}
}

void storealternate(Binary_tree *root, int l, int *index, int arr[])
{
	if(root == nullptr)
	{
		return;
	}
	storealternate(root->left,l+1,index,arr);
	if(l%2 != 0)
	{
		arr[*index] = root->data;
		cout<<root->data;
		(*index)++;
	}
	storealternate(root->right,l+1,index,arr);
}

void reversearr(int arr[],int index)
{
	int s = 0;
	int r = index - 1;
	while(s<r)
	{
		int temp = arr[s];
		arr[s] = arr[r];
		arr[r] = temp;
		s++;
		r--;
	}
}

void replaceTreeD(Binary_tree **root, int arr[], int l, int *index)
{
	if(*root == nullptr)
	{
		return;
	}
	replaceTreeD(&((*root)->left), arr,l+1,index);
	if(l %2 != 0)
	{
		(*root)->data = arr[*index];
		(*index)++;
	}
	replaceTreeD(&((*root)->right), arr,l+1,index);
}

void reverseoddperfect(Binary_tree**root)
{
	cout<<1<<endl;
	int *arr = new int[100];
	cout<<1<<endl;
	int index = 0;
	storealternate(*root, 0, &index,arr);
	cout<<1<<endl;
	reversearr(arr,index);
	cout<<1<<endl;
	index = 0;
	replaceTreeD(&(*root), arr, 0,&index);
}

void preMoristraversal(Binary_tree * root)
{
	if(root == nullptr)
	{
		return;
	}

	while(root)
	{
		if(root->left == nullptr)
		{
			cout<<root->data<<" ";
			root = root->right;
		}
		else
		{
			Binary_tree *l = root->left;
			while(l->right != nullptr && l->right != root)
			{
				l = l->right;
			}
			if(l->right == root)
			{
				l->right = nullptr;
				root = root->right;
			}
			else
			{
				cout<<root->data<<" ";
				l->right = root ;
				root = root->left;
			}
		}
	}
}

void preorderstack(Binary_tree *root)
{
	stack<Binary_tree*> s;
	s.push(root);
	while(!s.empty())
	{
		Binary_tree *temp = s.top();
		s.pop();
		cout<<temp->data<<" ";
		if(temp ->right != nullptr)
		{
			s.push(temp->right);
		}
		if(temp ->left != nullptr)
		{
			s.push(temp->left);
		}
	}
}

void postorderstack(Binary_tree *root)
{
	stack <Binary_tree*> s1;
	stack <Binary_tree*> s2;
	s1.push(root);
	while(!s1.empty())
	{
		Binary_tree *temp = s1.top();
		s2.push(s1.top());
		s1.pop();
		if(temp->left != nullptr)
		{
			s1.push(temp->left);
		}
		if(temp->right != nullptr)
		{
			s1.push(temp->right);
		}
	}
	while(!s2.empty())
	{
		cout<<(s2.top())->data<<" ";
		s2.pop();
	}
}

void postorderWstack(Binary_tree *root)
{
	stack<Binary_tree*> s;
	do
	{
		while(root != nullptr)
		{
			if(root->right != nullptr)
			{
				s.push(root->right);
			}
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		if(root->right != nullptr && !s.empty() && root->right == s.top())
		{
			s.pop();
			s.push(root);
			root = root->right;
		}
		else
		{
			cout<<root->data<<" ";
			root = nullptr;
		}
	}while(!s.empty());
}

void diagonal(Binary_tree *root)
{
	queue<Binary_tree*> q;
	q.push(root);
		while(!q.empty())
		{
			Binary_tree *temp = q.front();
			q.pop();
			while(temp != nullptr)
			{
				cout<<temp->data<<" ";
				if(temp->left != nullptr)
				{
					q.push(temp->left);
				}
				temp = temp->right;
			}
		}
}
void printlowerbound(Binary_tree *root)
{
	if(root == nullptr)
	{
		return;
	}
	printlowerbound(root->left);
	if(root->left == nullptr && root->right == nullptr)
	{
		cout<<root->data<<" ";
	}
	printlowerbound(root->right);
}

void printright(Binary_tree *root)
{
	if(root->right == nullptr)
	{
		return;
	}
	printright(root->right);
	cout<<root->data<<" ";
}

void printboundary(Binary_tree *root)
{
	Binary_tree *temp = root;
	while(temp->left != nullptr)
	{
		cout<<temp->data<<" ";
		temp = temp->left;
	}
	printlowerbound(root);
	printright(root->right);
}

int sizeheight(Binary_tree *root , double &size)
{
	if(root == nullptr)
	{
		return 0;
	}
	int l = sizeheight(root->left,size);
	int r = sizeheight(root->right,size);

	size++;

	return (r>l)?:r+1,l+1;
}
void densisty(Binary_tree *root)
{
	double size = 0;
	double h = sizeheight(root,size);
	cout<<h<<size<<endl;
	cout<<(h/size);
}



long long int factorial(long long int n,long long int arr[])
{
	if(n == 1 || n == 0)
		return 1;
	if(arr[n] != 0)
	{
		return arr[n];
	}
	else
	{
		long long int temp = factorial(n - 1, arr) * n;
		arr[n] = temp;
		return temp;
	}
}

void catalanNum(int n)
{
	long long int *arr = new long long int[1000];
	arr[0] = arr[1] = 1;
	long long int cat = (factorial((2*n),arr)/(factorial((n+1),arr)*factorial(n,arr)));
	cout<<cat<<endl;
}

void searchD(int n, int arr[], int *index)
{
	while(true)
	{
		if(n == arr[*index])
		{
			return;
		}
		(*index)++;
	}
}
/*

Binary_tree* buildtree(int preorder[], int inorder[],int s, int l)
{
	static int preindex = 0;
	int inindex = 0;
	if(s>l)
	{
		return nullptr;
	}
	Binary_tree*root = new Binary_tree(preorder[preindex]);
	if(l == s)
	{
		return root;
	}
	searchD(preorder[preindex],inorder,&inindex);
	
	root->left = buildtree(preorder,inorder,s,inindex-1);
	root->right = buildtree(preorder,inorder,inindex + 1,l);
	return root;
}
*/

void arraytobt(Binary_tree **root, int arr[],int n)
{
	queue<Binary_tree*> bt;
	*root = new Binary_tree(arr[0]);
	bt.push(*root);
	int i = 1;
	while( i < n)
	{
		Binary_tree * temp = bt.front();
		bt.pop();
		Binary_tree * lefttree = nullptr, *righttree = nullptr;
		lefttree = new Binary_tree(arr[i]);
		i++;
		bt.push(lefttree);
		if(i < n)
		{
			righttree = new Binary_tree(arr[i]);
			bt.push(righttree);
			i++;
		}
		temp->left = lefttree;
		temp->right = righttree;
	}
}

Binary_tree *construct(int pre[], int post[], int s, int l,int size)
{
	static int preindex = 0;
	if(preindex >= size || s>l)
	{
		return nullptr;
	}
	Binary_tree *root = new Binary_tree(pre[preindex]);
	preindex++;
	if(s ==  l)
	{
		return root;
	}

	int postindex = 0;
	searchD(pre[preindex],post,&postindex);
	if(postindex <= l){
		root->left = construct(pre,post,s,postindex,size);
		root->right = construct(pre,post,postindex+1,l - 1,size);
	}
	return root;
}

Binary_tree *specialPreorder(int preorder[], char preLN[],int size)
{
	static int index = 0;
	if(index >=size)
	{
		return nullptr;
	}
	Binary_tree * temp = new Binary_tree(preorder[index]);

	if(preLN[index] == 'N')
	{
		index++;
		temp->left = specialPreorder(preorder,preLN,size);
		temp->right = specialPreorder(preorder,preLN,size);
	
	}
	else
	{
		index++;
		return temp;
	}

	return temp;
}

int findmax(int in[], int s, int l)
{
	int max = 0;
	for(int i = s;i<= l; i++)
	{
		if(in[i]>max)
		{
			max = i;
		}
	}
	return max;
}

Binary_tree *specialinorder(int inorder[],int s, int l, int size)
{
	int inorderindex = 0;
	if(s>l)
	{
		return nullptr;
	}
	inorderindex = findmax(inorder,s,l);
	cout<<inorderindex<<endl;
	Binary_tree* temp = new Binary_tree(inorder[inorderindex]);
	if(s == l)
	{
		return temp;
	}
	temp->left = specialinorder(inorder,s,inorderindex - 1, size);
	temp -> right = specialinorder(inorder, inorderindex+1,l, size);

	return temp;
}

Binary_tree *constructin_post(int in[],int post[], int s, int l)
{
	int static postOindex = l;
	if(s>l)
	{
		return nullptr;
	}
	Binary_tree *root = new Binary_tree(post[postOindex]);
	int inIndex = 0;
	searchD(post[postOindex], in, &inIndex);
	postOindex--;
	if(s==l)
	{
		return root;
	}
	root->right = constructin_post(in,post,inIndex+1,l);
	root->left = constructin_post(in,post,s,inIndex-1);
	return root;
}

int findindex(string str, int s , int l)
{
	stack<char> find;
	for(int i =s; i<=l;i++)
	{
		if(str[i]=='(')
		{
			find.push(str[i]);
		}
		if(str[i]==')')
		{
			find.pop();
			if(find.empty())
			{
				return i;
			}
		}
	}
	return 0;
}

Binary_tree *stringtobt(string str, int s,int l)
{
	if(s>l)
	{
		return nullptr;
	}

	Binary_tree *root = new Binary_tree(int(str[s]-48));

	if(s == l)
	{
		return root;
	}
	int index = findindex(str,s,l);
	root->left = stringtobt(str,s+2,index-1);
	root->right = stringtobt(str,index+2,l -1);
	return root;
}

void completeinsert(Binary_tree **root, int data)
{
	Binary_tree *temp = new Binary_tree(data);
	if(*root == nullptr)
	{
		*root = temp;
		return;
	}
	queue<Binary_tree*> q;
	q.push(*root);
	while(!q.empty())
	{
		Binary_tree* temp2 = q.front();
		q.pop();
		if(temp2->left != nullptr)
		{
			q.push(temp2->left);
		}
		else
		{
			temp2->left = temp;
			return;
		}
		if(temp2->right != nullptr)
		{
			q.push(temp2->right);
		}
		else
		{
			temp2->right = temp;
			return;
		}
	}

}

int childrenSumSpecial(Binary_tree **root)
{
	if(*root == nullptr)
	{
		return 0;
	}

	int left = childrenSumSpecial(&((*root)->left));
	int right = childrenSumSpecial(&((*root)->right));
	if((left == 0 && right == 0) || right + left == (*root)->data)
	{
		return (*root)->data;
	}
	if(left+right - (*root)->data > 0)
	{
		(*root)->data = left + right;
		return left+right;
	}
	else
	{
		if((*root)->left!= nullptr)
		{
			(*root)->left->data = (*root)->data - right;
			childrenSumSpecial(&((*root)->left));
			return ((*root)->data - right);
		}
		else
		{
			(*root)->right->data = ((*root)->data);
			childrenSumSpecial(&((*root)->right));
			return ((*root)->data);
		}
	}
	return 0;
}

int childSum(Binary_tree **root)
{
	if(*root == nullptr)
	{
		return 0;
	}

	int left = childSum(&((*root)->left));
	int right = childSum(&((*root)->right));
	(*root)->data = left + right;
	return(left + right);
}

int sumlefttree(Binary_tree *root)
{
	if(root == nullptr)
	{
		return 0;
	}Y
	int l = sumlefttree(root->left);
	l = l + root->data;
	int r = sumlefttree(root->right);
	return l + r;
}

void sumleftsubtree(Binary_tree **root)
{
	if(*root == nullptr)
	{
		return;
	}
	(*root)->data = (*root)->data + sumlefttree((*root)->left);
	sumleftsubtree(&((*root)->left));
	sumleftsubtree(&((*root)->right));
}

void mirror(Binary_tree **root)
{
	if(*root == nullptr)
	{
		return;
	}
	mirror(&(*root)->left);
	mirror(&(*root)->right);

	Binary_tree *temp = (*root)->left;
	(*root)->left = (*root)->right;
	(*root)->right = temp;
}

void bttospiralDll(Binary_tree *root)
{
	queue<deque<Binary_tree*>> q;
	deque<Binary_tree*> dq;
	Binary_tree *dll = nullptr;

	dq.push_back(root);
	q.push(dq);
	int lvl = 0;
	
	while(!q.empty())
	{
		dq = q.front();
		q.pop();
		deque<Binary_tree*> temp;

		while(!dq.empty())
		{
			Binary_tree *  tempQ = nullptr;
			if(lvl%2 == 0)
			{
				tempQ = dq.front();
				dq.pop_front();
				cout<<tempQ->data<<" ";
				if(tempQ->left != nullptr)
				{
					temp.push_back(tempQ->left);
				}
				if(tempQ->right != nullptr)
				{
					temp.push_back(tempQ->right);
				}
			}
			else
			{
				tempQ = dq.back();
				dq.pop_back();
				cout<<tempQ->data<<" ";
				if(tempQ->right != nullptr)
				{
					temp.push_front(tempQ->right);
				}
				if(tempQ->left != nullptr)
				{
					temp.push_front(tempQ->left);
				}
			}


		}
		lvl++;
		if(!temp.empty())
		{
			q.push(temp);
		}
		temp.clear();
	}
}

int checklogictree(Binary_tree **root)
{
	if((*root)->left == nullptr)
	{
		return (*root)->data;
	}
	int l = checklogictree(&(*root)->left);
	int r = checklogictree(&(*root)->right);

	(*root)->data = l * r;
	return l*r;
}

int main()
{
    Binary_tree *root =  new Binary_tree(1);
    root->left = new Binary_tree(2);
    root->right = new Binary_tree(3);
    root->left->left = new Binary_tree(4);
    root->left->right = new Binary_tree(5);
    root->right->left = new Binary_tree(6);
    root->right->right = new Binary_tree(7);
    root->left->left->left  = new Binary_tree(8);
    root->left->left->right  = new Binary_tree(9);
    root->left->right->left  = new Binary_tree(10);
    root->left->right->right  = new Binary_tree(11);
    root->right->left->left  = new Binary_tree(12);
    root->right->left->right  = new Binary_tree(13);
    root->right->right->left  = new Binary_tree(14);
    
 
	//cout<<continuous(root)<<endl;
	//moristraversal(root);
	//pushzero(root);
	//cout<<endl;
	//printst(root);
	moristraversal(root);
	cout<<endl;
	//utility(root,2);
	//nsearch(root,2);
	//printpostorder(root);
	//nsearchpost(root,4);
	//levelOrdering(root);
	//printspiral(root);
	//printreverse(root);
	//printleftright(root);
	//printperfectRev(root);
	//printperfect(root);
	//reverseoddperfect(&root);top
	//moristraversal(root);
	//preorderstack(root);
	//postorderstack(root);
	//cout<<endl;
	//postorderWstack(root);
	//cout<<endl;
	//diagonal(root);
	//printboundary(root);
	//cout<<endl;
	//densisty(root);
	//catalanNum(10);
	/*
	int in[] = { 4, 2, 5, 1, 6, 3 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int len = sizeof(in) / sizeof(in[0]);
    Binary_tree *root2 = buildtree(in, pre, 0, len - 1);

    cout << "Inorder traversal of the constructed tree is \n";
    moristraversal(root);*/

    //int arr[] = {1, 2, 3, 4, 5, 6};
    //Binary_tree *root3 = nullptr;
    //arraytobt(&root3,arr,6);
    //moristraversal(root3); 
    //int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    //int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    //int preOrder[] = {1,2,4,5,3,6,7};
    //int preOrderMirror[] = {1,3,7,6,2,5,4};
    //int s =0;
    //int l = 6;
    //while(s<l)
    //{
    //	int temp = preOrderMirror[s];
    //	preOrderMirror[s] = preOrderMirror[l];
    //	preOrderMirror[l] = temp;
    //	s++;
    //	l--;
    //}
    //int size = sizeof(pre)/sizeof(pre[0]);
    //cout<<size<<endl;
    //root3 = construct(pre,post, 0, size-1,size);
    //Binary_tree *root4 = nullptr;
    //root4 = construct(preOrder,preOrderMirror,0,6,7);
    //cout<<endl;
    //moristraversal(root3);
    //cout<<endl;
    //moristraversal(root4);
    //cout<<endl;
  	//int pre[] = {10, 30, 20, 5, 15};
    //char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    //Binary_tree *root5 = specialPreorder(pre,preLN,5);
    //moristraversal(root5);
    //cout<<endl;
    /*
    int inorder[] = {1, 5, 10, 40, 30, 15, 28, 20};
    Binary_tree * root6 = specialinorder(inorder,0,7,8);
    moristraversal(root6);
    cout<<endl;*/
	/*
    int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
 	int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
 	Binary_tree *root7 = constructin_post(in,post,0,7);
 	moristraversal(root7);
 	cout<<endl;*/
 	/*string str = "4(2(3)(1))(6(5))";
 	Binary_tree *root8 = stringtobt(str,0,str.length()-1);
 	moristraversal(root8);
 	cout<<endl;
 	preMoristraversal(root8);*/
 	//childrenSumSpecial(&root);
 	cout<<endl;
 	moristraversal(root);
 	cout<<endl;
 	bttospiralDll(root);
 	cout<<endl;
	return 0;
}