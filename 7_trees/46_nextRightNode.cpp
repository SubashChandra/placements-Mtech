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

int auxFunc(Treeptr root,int key)
{
	if(root==NULL)
		return -1;

	queue<Treeptr> q1;
	q1.push(root);
	q1.push(NULL);
	while(q1.size()!=0)
	{
		root=q1.front();
		q1.pop();

		if(root==NULL)
		{
			if(q1.size()!=0)
				q1.push(NULL);
			else
				break;
		}

		else if(root->data==key)
		{
			if(q1.front()==NULL)
				return -1;
			else
				return q1.front()->data;
		}
		else
		{
			if(root->left)
				q1.push(root->left);
			if(root->right)
				q1.push(root->right);
		}
	}
	return -1;
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
	int key;
	cin>>key;
	cout<<auxFunc(root,key)<<endl;
	return 0;
}
