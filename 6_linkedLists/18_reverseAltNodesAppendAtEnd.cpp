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
	if(head==NULL || head->next==NULL)
		return head;
	Nodeptr cur, next,pre;
	pre=NULL;
	cur=head;
	while(cur)
	{
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	return pre;
}

void auxFunc(Nodeptr head)
{
	if(head==NULL || head->next==NULL)
		return;

	Nodeptr cur,next,pre;
	Nodeptr sHead, sCur;

	sHead=NULL;
	cur=head;

	while(cur && cur->next)
	{
		next=cur->next->next;
		if(sHead==NULL)
			sHead=cur->next;
		else
			sCur->next=cur->next;
		sCur=cur->next;

		pre=cur;
		cur=next;
		pre->next=cur;
	}
	if(cur)
	{
		pre=cur;
		cur=cur->next;
	}


	sCur->next=NULL;
	sHead=reverse(sHead);
	pre->next=sHead;
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
		
