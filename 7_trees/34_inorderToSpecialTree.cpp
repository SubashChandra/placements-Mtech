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

Treeptr auxFunc(vector<int> vec, int l, int r)
{
	if(l>r)
		return NULL;

	int i;
	int max=l;
	for(i=l;i<=r;i++)
		if(vec[i]>vec[max])
			max=i;
	Treeptr temp=getNew(vec[max]);
	temp->left=auxFunc(vec,l,max-1);
	temp->right=auxFunc(vec,max+1,r);
	return temp;
}

int main()
{
	int n;
	Treeptr root=NULL;
	cin>>n;
	vector<int> vec(n);

	int i;
	while(i<n)
	{
		int data;
		cin>>data;
		vec[i]=data;
		i++;
	}

	root=auxFunc(vec,0,n-1);

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
