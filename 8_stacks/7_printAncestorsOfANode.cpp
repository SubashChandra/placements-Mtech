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

void auxFunc(Treeptr root, int data)
{
	if(root==NULL)
		return;

	stack<Treeptr> s1;

	while(1)
	{
		if(root)
		{
			if(root->data==data)
				break;
			else
			{
				s1.push(root);
				root=root->left;
			}
		}
		else
		{
			if(s1.size()==0)
				break;
			else if(s1.top()->right==NULL)
			{
				root=s1.top();
				s1.pop();
				while(s1.size()!=0 && s1.top()->right==root)
				{
					root=s1.top();
					s1.pop();
				}
			}
			if(s1.size()!=0)
				root=s1.top()->right;
			else
				root=NULL;
		}
	}
	while(s1.size()!=0)
	{
		cout<<s1.top()->data<<" ";
		s1.pop();
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
	int data;
	cin>>data;

	auxFunc(root,data);
	
	return 0;
}
