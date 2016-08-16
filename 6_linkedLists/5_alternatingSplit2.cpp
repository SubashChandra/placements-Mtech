//if newnode cant be created and original nodes must be used

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

void auxFunc(Nodeptr head, Nodeptr *first, Nodeptr *second)
{
	*first=NULL;
	*second=NULL;
	Nodeptr next;
	Nodeptr firstCur;
	Nodeptr secondCur;

	while(head)
	{
		next=head->next;
		if(*first==NULL)
		{
			*first=head;
			firstCur=head;
		}
		else
		{
			firstCur->next=head;
			firstCur=head;
		}
		head=next;
		if(head)
			next=head->next;
		else
			next=NULL;
		if(head==NULL)
			break;
		if(*second==NULL)
		{
			*second=head;
			secondCur=head;
		}
		else
		{
			secondCur->next=head;
			secondCur=head;
		}
		head=next;
	}
	firstCur->next=NULL;
	secondCur->next=NULL;
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
	Nodeptr first,second;
	auxFunc(head,&first,&second);
	printList(first);
	printList(second);
	return 0;
}
		
