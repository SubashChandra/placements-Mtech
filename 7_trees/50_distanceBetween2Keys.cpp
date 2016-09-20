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

int findLevel(Treeptr root, int k, int level)
{
	if(root==NULL)
		return -1;

	if(root->data==k)
		return level;
	int l=findLevel(root->left,k,level+1);
	return (l!=-1)?l:findLevel(root->right,k,level+1);
}


Treeptr findDist(Treeptr root, int k1, int k2, int &d1, int &d2, int &dist, int level)
{
	if(root==NULL)
		return NULL;
	if(root->data==k1)
	{
		d1=level;
		return root;
	}
	if(root->data==k2)
	{
		d2=level;
		return root;
	}
	
	Treeptr leftlca=findDist(root->left,k1,k2,d1,d2,dist,level+1);
	Treeptr rightlca=findDist(root->right,k1,k2,d1,d2,dist,level+1);

	if(leftlca && rightlca)
	{
		dist=d1+d2-2*level;
		return root;
	}

	return leftlca?leftlca:rightlca;
}

int auxFunc(Treeptr root, int k1, int k2)
{
	int d1=-1,d2=-1,dist;
	Treeptr lca=findDist(root,k1,k2,d1,d2,dist,0);

	if(d1!=-1 && d2 !=-1)
		return dist;

	if(d1!=-1)
	{
		dist=findLevel(lca,k2,0);
		return dist;
	}

	if(d2!=-1)
	{
		dist=findLevel(lca,k1,0);
		return dist;
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

	int d1,d2;
	cin>>d1>>d2;
	cout<<auxFunc(root,d1,d2)<<endl;
	return 0;
}
