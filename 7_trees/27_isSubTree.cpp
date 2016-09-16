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

	//level order insert
	queue<Treeptr> q;
	q.push(root);
	Treeptr temp;
	while(q.size()!=0)
	{

		temp=q.front();
		q.pop();
		if(temp->left)
			q.push(temp->left);
		else
		{
			temp->left=getNew(data);
			break;
		}
		if(temp->right)
			q.push(temp->right);
		else
		{
			temp->right=getNew(data);
			break;
		}
	}
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

bool areIdentical(Treeptr r1, Treeptr r2)
{
	if((r1 && !r2) || (!r1 && r2))
		return false;
	if(r1==NULL && r2==NULL)
		return true;
	return r1->data==r2->data && areIdentical(r1->left,r2->left) && areIdentical(r1->right,r2->right);
}

bool isSubTree(Treeptr root1, Treeptr root2)
{
	if(root2==NULL)
		return true;
	if(root1== NULL)
		return false;

	if(areIdentical(root1,root2))
		return true;

	return isSubTree(root1->left,root2) || isSubTree(root1->right,root2);
}
int main()
{
	int n1,n2;
	Treeptr root1=NULL;
	cin>>n1;
	while(n1>0)
	{
		int data;
		cin>>data;
		root1=insert(root1,data);
		n1--;

	}

	cout<<"preorder:"<<endl;
	preOrder(root1);
	cout<<endl;

	Treeptr root2=NULL;
	cin>>n2;
	while(n2>0)
	{
		int data;
		cin>>data;
		root2=insert(root2,data);
		n2--;

	}

	cout<<"preorder:"<<endl;
	preOrder(root2);
	cout<<endl;

	//root2 is a subtree of root1
	if(isSubTree(root1,root2))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	return 0;
}
