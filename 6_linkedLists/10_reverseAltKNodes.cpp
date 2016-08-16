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

Nodeptr reverseAltK(Nodeptr head, int k)
{
	if(head==NULL || head->next==NULL)
		return head;
	if(k==1)
		return head;

	Nodeptr cur=head,pre,next;
	pre=NULL;
	
	int i=0;
	while(cur!=NULL && i<k)
	{
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
		i++;
	}
	if(cur==NULL)
		return pre;

	Nodeptr retNode=pre;
	head->next=cur;
	i=0;
	while(cur && i<k)
	{
		pre=cur;
		cur=cur->next;
		i++;
	}
	pre->next=reverseAltK(cur,k);
	return retNode;



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
	head=reverseAltK(head,k);
	printList(head);
	return 0;
}
		
