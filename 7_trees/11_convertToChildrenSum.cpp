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

void add(Treeptr root, int val)
{
	if(root==NULL)
		return;
	root->data+=val;
	if(root->left)
		add(root->left,val);
	else
		add(root->right,val);
}

void auxFunc(Treeptr root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return;

	auxFunc(root->left);
	auxFunc(root->right);

	int lval=root->left?root->left->data:0;
	int rval=root->right?root->right->data:0;

	if(lval+rval>=root->data)
		root->data+=((lval+rval)-root->data);
	else
	{
		int diff=root->data-(lval+rval);
		if(root->left)
			add(root->left,diff);
		else
			add(root->right,diff);
	}
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
	cout<<"preorder:"<<endl;
	preOrder(root);
	cout<<endl;
	return 0;
}
