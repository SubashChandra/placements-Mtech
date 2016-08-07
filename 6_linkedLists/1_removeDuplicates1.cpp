//if extra space alowed

#include<cstdio>
#include<iostream>

struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;
typedef Node *Nodeptr;
using namespace std;

void printList(Nodeptr head)
{
	while(head)
	{
		cout<<head->data<<" -> ";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

void removeDup(Nodeptr head)
{
	if(head==NULL || head->next==NULL)
		return;

	Nodeptr cur,temp;

	while(head)
	{
		cur=head;
		while(cur->next)
		{
			if(cur->next->data == head->data)
			{
				temp=cur->next;
				cur->next=cur->next->next;
				free(temp);
			}
			else
				cur=cur->next;
		}
		head=head->next;
	}
}


int main()
{
	int n,val;
	cin>>n;
	Nodeptr head=NULL;
	Nodeptr cur=NULL,newnode;
	while(n>0)
	{
		cin>>val;
		newnode=(Nodeptr)malloc(sizeof(Node));
		newnode->data=val;
		newnode->next=NULL;
		if(head==NULL)
		{
			head=cur=newnode;
		}
		else
		{
			cur->next=newnode;
			cur=newnode;
		}
		n--;
	}


	//now remove duplcates
	printList(head);
	removeDup(head);
	printList(head);
	return 0;
}
