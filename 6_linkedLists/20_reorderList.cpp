#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;


struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;
typedef Node *Nodeptr;

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

Nodeptr reverse(Nodeptr head)
{
	Nodeptr pre, next;
	pre=NULL;
	while(head)
	{
		next=head->next;
		head->next=pre;
		pre=head;
		head=next;
	}
	return pre;
}


void auxFunc(Nodeptr head)
{
	if(head==NULL || head->next==NULL)
		return;

	Nodeptr slow,fast,slowpre;
	slow=fast=head;
	while(fast && fast->next)
	{
		slowpre=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	if(fast)
	{
		slowpre=slow;
		slow=slow->next;
	}

	slowpre->next=NULL;
	slow=reverse(slow);
	Nodeptr next1, next2;

	while(head && slow)
	{
		next1=head->next;
		next2=slow->next;
		head->next=slow;
		slow->next=next1;

		head=next1;
		slow=next2;
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
	auxFunc(head);
	printList(head);
	return 0;
}
		
