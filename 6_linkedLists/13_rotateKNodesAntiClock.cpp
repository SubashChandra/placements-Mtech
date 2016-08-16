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
		head=head->next;
		len++;
	}
	return len;
}


Nodeptr auxFunc(Nodeptr head, int k)
{
	int len=listLen(head);
	if(k%len==0 || k==0)
		return head;
	k=k%len;
	Nodeptr cur,pre;
	Nodeptr ans;
	cur=head;
	while(k>0 && cur)
	{
		pre=cur;
		cur=cur->next;
		k--;
	}
	ans=cur;
	pre->next=NULL;
	while(cur->next)
		cur=cur->next;
	cur->next=head;
	return ans;
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
	int k;
	cin>>k;
	head=auxFunc(head,k);
	printList(head);
	return 0;
}
		
