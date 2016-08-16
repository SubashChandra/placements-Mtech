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

int getLen(Nodeptr head)
{
	int len=0;
	while(head)
	{
		head=head->next;
		len++;
	}
	return len;
}

Nodeptr auxFunc(Nodeptr head, int k)
{
	int len=getLen(head);
	if(k>len)
		return head;

	Nodeptr first,second,firstPre,secondPre;
	Nodeptr cur;

	firstPre=NULL;
	secondPre=NULL;
	int i=0;
	first=head;
	while(i<k-1)
	{
		firstPre=first;
		first=first->next;
		i++;
	}

	cout<<first->data<<endl;
	i=0;
	second=head;
	int count=len-k;
	while(i<count)
	{
		secondPre=second;
		second=second->next;
		i++;
	}

	cout<<second->data<<endl;
	//case 1

	if(first==second)
		return head;
	
	//case 2
	else if(first->next==second)
	{
		if(firstPre)
			firstPre->next=second;
		first->next=second->next;
		second->next=first;
	}
	
	//case 3
	else if(second->next==first)
	{
		if(secondPre)
			secondPre->next=first;
		second->next=first->next;
		first->next=second;
	}

	else
	{
		swap(first->next,second->next);
		if(firstPre)
			firstPre->next=second;
		if(secondPre)
			secondPre->next=first;
	}
	if(k==1)
		head=second;
	else if(k==4)
		head=first;

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

	int k;
	cin>>k;

	printList(head);
	head=auxFunc(head,k);
	printList(head);
	
	return 0;
}
		
