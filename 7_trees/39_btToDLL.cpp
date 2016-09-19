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
};

typedef struct tree Tree;
typedef Tree *Treeptr;


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

void toDll(Treeptr root, Treeptr &pre, Treeptr &head)
{
	if(root)
	{
		toDll(root->left,pre,head);
		if(pre==NULL)
		{
			pre=root;
			head=root;
		}
		else
			pre->right=root;
		root->left=pre;
		pre=root;
		toDll(root->right,pre,head);
	}
}
		

Treeptr auxFunc(Treeptr root)
{
	Treeptr pre=NULL;
	Treeptr head=NULL;

	toDll(root,pre,head);
	return head;
}

void printList(Treeptr head)
{
	while(head)
	{
		cout<<head->data<< " ";
		head=head->right;
	}
	cout<<endl;
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
	root=auxFunc(root);
	printList(root);

	return 0;
}
