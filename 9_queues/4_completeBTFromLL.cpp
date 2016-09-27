//binary search tree

#include<bits/stdc++.h>

using namespace std;

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

typedef struct tree Tree;
typedef Tree *Treeptr;

struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;
typedef Node *Nodeptr;

Nodeptr getnode(int data)
{
	Nodeptr newnode=(Nodeptr)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

Treeptr getNew(int data)
{
	Treeptr newnode=(Treeptr)malloc(sizeof(Tree));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}

Treeptr insert(Treeptr root, int data)
{
	if(root==NULL)
		return getNew(data);

	if(data<root->data)
		root->left=insert(root->left,data);
	else if(data>root->data)
		root->right=insert(root->right,data);
	return root;
}

void preOrder(Treeptr root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Treeptr root)
{
	if(root)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void postOrder(Treeptr root)
{
	if(root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

void printList(Nodeptr head)
{
	if(head==NULL)
		return;
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

Treeptr build(Nodeptr head)
{
	if(head==NULL)
		return NULL;
	queue<Treeptr> q1;
	Treeptr root=getNew(head->data);
	head=head->next;
	q1.push(root);
	while(head)
	{
		Treeptr temp=q1.front();
		q1.pop();

		temp->left=getNew(head->data);
		q1.push(temp->left);
		head=head->next;
		
		if(head==NULL)
			break;
		temp->right=getNew(head->data);
		q1.push(temp->right);
		head=head->next;
	}
	return root;
}

int main()
{
	int n;
	cin>>n;
	Nodeptr head=NULL,temp;
	while(n>0)
	{
		int data;
		cin>>data;
		temp=getnode(data);
		temp->next=head;
		head=temp;
		n--;
	}

	printList(head);


	Treeptr root=NULL;
	root=build(head);
	cout<<"preorder:"<<endl;
	preOrder(root);
	cout<<endl;
	cout<<"inorder:"<<endl;
	inOrder(root);
	cout<<endl;
	cout<<"postorder:"<<endl;
	postOrder(root);
	cout<<endl;
	return 0;
}
