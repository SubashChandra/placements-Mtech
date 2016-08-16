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

	Nodeptr firstCur;
	Nodeptr secondCur;

	while(head)
	{
		if(*first==NULL)
		{
			*first=createNew(head->data);
			firstCur=*first;
		}
		else
		{
			firstCur->next=createNew(head->data);
			firstCur=firstCur->next;
		}
		head=head->next;
		if(head==NULL)
			break;
		if(*second==NULL)
		{
			*second=createNew(head->data);
			secondCur=*second;
		}
		else
		{
			secondCur->next=createNew(head->data);
			secondCur=secondCur->next;
		}
		head=head->next;
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
	Nodeptr first,second;
	auxFunc(head,&first,&second);
	printList(first);
	printList(second);
	return 0;
}
		
