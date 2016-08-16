#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;


struct node
{
	int data;
	struct node *pre;
	struct node *next;
};

typedef struct node Node;
typedef Node *Nodeptr;

Nodeptr createNew(int data)
{
	Nodeptr newnode=(Nodeptr)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->pre=NULL;
	return newnode;
}

Nodeptr insert(Nodeptr head, int data)
{
	if(head==NULL)
		return createNew(data);


	else
	{
		Nodeptr cur=head,pre=NULL;;
		while(cur->next)
		{
			pre=cur;
			cur=cur->next;
		}
		
		cur->next=createNew(data);
		cur->next->pre=cur;
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

Nodeptr auxFunc(Nodeptr head)
{
	if(head==NULL)
		return head;
	if(head->next==NULL)
	{
		head->pre=NULL;
		return head;
	}

	Nodeptr slow,fast,slowpre;
	slow=fast=head;
	while(fast&& fast->next)
	{
		slowpre=slow;
		slow=slow->next;
		fast=fast->next->next;
	}

	Nodeptr root=slow;
	slowpre->next=NULL;
	printList(head);
	printList(slow->next);
	root->pre=auxFunc(head);
	root->next=auxFunc(slow->next);
	return root;
}

void preorder(Nodeptr root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->pre);
		preorder(root->next);
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
	head=auxFunc(head);
	preorder(head);
	cout<<endl;
	return 0;
}
		
