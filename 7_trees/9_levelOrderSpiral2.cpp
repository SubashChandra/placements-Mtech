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

void auxFunc1(Treeptr root, vector<vector<int> > &vec, int depth)
{
	if(root==NULL)
		return;
	if(vec.size()<=depth)
	{
		vector<int> temp;
		temp.push_back(root->data);
		vec.push_back(temp);
	}
	else
	{
		vec[depth].push_back(root->data);
	}
	auxFunc1(root->left,vec,depth+1);
	auxFunc1(root->right, vec, depth+1);
}




void auxFunc(Treeptr root)
{
	if(root==NULL)
		return;
	
	stack<Treeptr> s1,s2;
	s1.push(root);

	Treeptr temp;
	while(s1.size()!=0 || s2.size()!=0)
	{
		//right and then left
		if(s1.size()!=0)
		{
			while(s1.size()!=0)
			{
				temp=s1.top();
				cout<<temp->data<<" ";
				s1.pop();
				if(temp->right)
					s2.push(temp->right);
				if(temp->left)
					s2.push(temp->left);
			}
		}
		//left and then right
		else
		{
			while(s2.size()!=0)
			{
				temp=s2.top();
				cout<<temp->data<<" ";
				s2.pop();
				if(temp->left)
					s1.push(temp->left);
				if(temp->right)
					s1.push(temp->right);
			}
		}
	
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
	auxFunc(root);
	return 0;
}
