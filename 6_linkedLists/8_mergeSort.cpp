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

void split(Nodeptr head, Nodeptr *first, Nodeptr *second)
{
	if(head==NULL || head->next==NULL)
	{
		*first=head;
		*second=NULL;
		return;
	}

	Nodeptr slow,fast,slowpre,fastpre;

	slow=fast=head;
	while(fast && fast->next)
	{
		slowpre=slow;
		slow=slow->next;

		fastpre=fast;
		fast=fast->next->next;
	}
	if(fast)
	{
		fastpre=fast;
		fast=fast->next;
	}
	while(fastpre->next)
		fastpre=fastpre->next;
	
	*first=head;
	slowpre->next=NULL;

	*second=slow;
	fastpre->next=NULL;
}

Nodeptr merge(Nodeptr l1, Nodeptr l2)
{
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	Nodeptr cur;
	if(l1->data < l2->data)
	{
		cur=l1;
		cur->next=merge(l1->next,l2);
	}
	else
	{
		cur=l2;
		cur->next=merge(l1,l2->next);
	}
	return cur;
}

Nodeptr mergeSort(Nodeptr head)
{
	if(head==NULL || head->next==NULL)
		return head;

	Nodeptr first,second;
	first=second=NULL;
	split(head,&first,&second);
	first=mergeSort(first);
	second=mergeSort(second);

	head=merge(first,second);

	return head;
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
	head=mergeSort(head);
	printList(head);

	return 0;
}
		
