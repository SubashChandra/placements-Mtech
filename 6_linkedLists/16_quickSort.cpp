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

Nodeptr getTail(Nodeptr head)
{
	while(head && head->next)
		head=head->next;
	return head;
}


Nodeptr partition(Nodeptr head, Nodeptr tail, Nodeptr *newHead, Nodeptr *newTail)
{
	Nodeptr pivot=tail;
	Nodeptr pre, cur, end=pivot;
	pre=NULL;
	cur=head;

	while(cur!=pivot)
	{
		if(cur->data<pivot->data)
		{
			if(*newHead==NULL)
				*newHead=cur;
			pre=cur;
			cur=cur->next;
		}
		else
		{
			if(pre)
				pre->next=cur->next;
			Nodeptr temp=cur->next;
			cur->next=NULL;
			end->next=cur;
			end=cur;
			cur=temp;
		}
	}
	if(*newHead==NULL)
		*newHead=pivot;
	*newTail=end;
	return pivot;
}
		


Nodeptr quickSortRec(Nodeptr head, Nodeptr tail)
{
	if(head==NULL || head==tail)
		return head;

	Nodeptr newHead, newTail;
	newHead=newTail=NULL;

	Nodeptr pivot=partition(head, tail, &newHead, &newTail);


	//recur on the left part
	if(newHead!=pivot)
	{
		//set the node before the pivot node as NULL
		Nodeptr cur;
		cur=newHead;
		while(cur->next!=pivot)
			cur=cur->next;
		cur->next=NULL;

		newHead=quickSortRec(newHead,cur);

		cur=getTail(newHead);
		cur->next=pivot;
	}
	pivot->next=quickSortRec(pivot->next,newTail);
	return newHead;
}

Nodeptr quickSort(Nodeptr head)
{
	head=quickSortRec(head,getTail(head));
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
	head=quickSort(head);
	printList(head);
	return 0;
}
		
