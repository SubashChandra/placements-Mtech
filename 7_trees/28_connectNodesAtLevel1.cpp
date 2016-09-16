//binary search tree

#include<cstdio>
#include<iostream>
#include<map>
#include<stack>
#include<queue>

using namespace std;

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *next;
};

typedef struct tree Tree;
typedef Tree *Treeptr;


Treeptr getNew(int data)
{
	Treeptr newnode=(Treeptr)malloc(sizeof(Tree));
	newnode->data=data;
	newnode->left=newnode->right=newnode->next=NULL;
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


void preOrder1(Treeptr root)
{
	if(root)
	{
		cout<<root->data<<":";
		Treeptr temp=root->next;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
		preOrder1(root->left);
		preOrder1(root->right);
	}
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

void connect(Treeptr root, map<int,Treeptr> &m1, int level)
{
	if(root==NULL)
		return;
	if(m1.find(level)==m1.end())
		m1[level]=root;
	else
	{
		m1[level]->next=root;
		m1[level]=root;
	}

	connect(root->left,m1,level+1);
	connect(root->right,m1,level+1);
}

void auxFunc(Treeptr root)
{
	if(root==NULL)
		return;
	
	map<int,Treeptr> m1;
	connect(root,m1,1);
	cout<<"preorder level connected:"<<endl;
	preOrder1(root);
}

int main()
{
	int n;
	Treeptr root=NULL;
	cin>>n;
	while(n>0)
	{
		int data;
		cin>>data;
		root=insert(root,data);
		n--;

	}

	cout<<"preorder:"<<endl;
	preOrder(root);
	cout<<endl;
	cout<<"inorder:"<<endl;
	inOrder(root);
	cout<<endl;
	cout<<"postorder:"<<endl;
	postOrder(root);
	cout<<endl;
	auxFunc(root);
	return 0;
}
