//binary search tree

#include<cstdio>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<set>

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

void printNodes(Treeptr root, vector<int> vec, int k, set<int> &s1)
{
	if(root==NULL)
		return;

	vec.push_back(root->data);
	if(root->left==NULL && root->right==NULL)
	{
		if(k>=vec.size())
			return;
		s1.insert(vec[vec.size()-1-k]);
		return;
	}
	printNodes(root->left,vec,k,s1);
	printNodes(root->right,vec,k,s1);
}


void auxFunc(Treeptr root, int k)
{
	if(root==NULL)
		return;

	vector<int> vec;
	set<int> s1;
	printNodes(root,vec,k,s1);
	set<int>::iterator it;
	for(it=s1.begin();it!=s1.end();it++)
		cout<<*it<<" ";
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
	int k;
	cin>>k;
	auxFunc(root,k);
	return 0;
}
