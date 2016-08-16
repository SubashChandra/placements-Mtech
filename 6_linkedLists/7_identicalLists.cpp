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


int auxFunc(Nodeptr head1, Nodeptr head2)
{
	while(head1 && head2)
	{
		if(head1->data!=head2->data)
			return 0;
		head1=head1->next;
		head2=head2->next;
	}
	if(head1!=NULL || head2!=NULL)
		return 0;
	return 1;

}
int main()
{
	int n1;
	cin>>n1;
	int i;
	Nodeptr head1=NULL;
	int data;
	for(i=0;i<n1;i++)
	{
		cin>>data;
		head1=insert(head1,data);
	}
	int n2;
	cin>>n2;
	Nodeptr head2=NULL;
	for(i=0;i<n2;i++)
	{
		cin>>data;
		head2=insert(head2,data);
	}


	printList(head1);
	printList(head2);
	cout<<auxFunc(head1,head2)<<endl;
	return 0;
}
		
