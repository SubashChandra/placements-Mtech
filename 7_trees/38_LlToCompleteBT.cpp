#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>

using namespace std;


struct node
{
	int data;
	struct node *next;
};


typedef struct node Node;
typedef Node *Nodeptr;

struct tree
{
	int data;
	struct tree *left,*right;
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

Nodeptr createNew(int data)
{
	Nodeptr newnode=(Nodeptr)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

Nodeptr insert(Nodeptr head, int data)
{
	if(head==NULL)
		return createNew(data);
	else
	{
		Nodeptr cur=head;
		while(cur->next)
			cur=cur->next;
		cur->next=createNew(data);
	}
	return head;
}
void printList(Nodeptr head)
{
	while(head)
	{
		cout<<head->data<<" -> ";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

Treeptr auxFunc(Nodeptr head)
{
	if(head==NULL)
		return NULL;

	queue<Treeptr> q1;
	Treeptr root=getNew(head->data);
	q1.push(root);
	head=head->next;

	while(head!=NULL)
	{
		Treeptr temp=q1.front();
		q1.pop();

		if(temp->left==NULL)
		{
			temp->left=getNew(head->data);
			head=head->next;
			q1.push(temp->left);
		}
		if(head==NULL)
			break;
		if(temp->right==NULL)
		{
			temp->right=getNew(head->data);
			head=head->next;
			q1.push(temp->right);
		}
	}
	return root;
}
		
void preorder(Treeptr root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);

	}
}

void inorder(Treeptr root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main()
{
	int n;
	cin>>n;
	int i;
	Nodeptr head=NULL;
	int data;
	for(i=0;i<n;i++)
	{
		cin>>data;
		head=insert(head,data);
	}

	printList(head);
	Treeptr root=auxFunc(head);
	cout<<"preorder"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"inorder"<<endl;
	inorder(root);
	cout<<endl;

	return 0;
}
		
