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
	struct node *arbit;
};

typedef struct node Node;
typedef Node *Nodeptr;

Nodeptr createNew(int data)
{
	Nodeptr newnode=(Nodeptr)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->arbit=NULL;
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
		cout<<head->data;
		if(head->arbit)
			cout<<" "<<head->arbit->data;
		cout<<endl;
		head=head->next;
	}
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

Nodeptr auxFunc(Nodeptr head)
{
	if(head==NULL || head->next==NULL)
		return head;

	head=reverse(head);
	Nodeptr cur,maxNode;
	maxNode=head;
	cur=head->next;

	while(cur)
	{
		if(cur->data<maxNode->data)
			cur->arbit=maxNode;
		else
			maxNode=cur;
		cur=cur->next;
	}

	return reverse(head);
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
		
