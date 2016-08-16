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

int listLen(Nodeptr head)
{
	int len=0;
	while(head)
	{
		len++;
		head=head->next;
	}
	return len;
}


int auxFunc(Nodeptr head, int k)
{
	int len=listLen(head);
	if(k>len)
		return -1;
	while(k>1)
	{
		head=head->next;
		k--;
	}
	return head->data;
}

int main()
{
	int cases;
	cin>>cases;
	while(cases>0)
	{

		int n;
		cin>>n;
		int k;
		cin>>k;
		int i;
		Nodeptr head=NULL;
		int data;
		for(i=0;i<n;i++)
		{
			cin>>data;
			head=insert(head,data);
		}

		printList(head);
		cout<<auxFunc(head,k)<<endl;
		cases--;
	}
	return 0;
}
		
