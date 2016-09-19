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

Treeptr check(Treeptr root,int sum, int &flag)
{
	if(root==NULL)
	{
		flag=false;
		return NULL;
	}

	if(root->left==NULL && root->right==NULL)
	{
		if(sum>root->data)
		{
			flag=false;
			free(root);
			return NULL;
		}
		
		return root;
	}

	
	int lflag,rflag;
	lflag=rflag=true;
	root->left= check(root->left,sum-root->data,lflag);
	root->right=check(root->right,sum-root->data,rflag);

	if(lflag || rflag)
	{
	
		flag=true;
		return root;
	}
		cout<<"****"<<endl;
	flag=false;
	free(root);
	return NULL;
}


Treeptr auxFunc(Treeptr root,int sum)
{
	if(root==NULL)
		return NULL;
	int flag;
	return check(root,sum,flag);
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
	int sum;
	cin>>sum;
	root=auxFunc(root,sum);
	cout<<"preorder:"<<endl;
	preOrder(root);
	cout<<endl;
	cout<<"inorder:"<<endl;
	inOrder(root);
	cout<<endl;

	return 0;
}
