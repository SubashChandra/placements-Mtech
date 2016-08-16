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

//assuming head2 is sorted in ascending nd head3 in descending
void  auxFunc(Nodeptr head1, Nodeptr head2,Nodeptr head3,int sum)
{
	Nodeptr cur1,cur2,cur3;
	cur1=head1;
	while(cur1)
	{
		cur2=head2;
		cur3=head3;
		while(cur2 && cur3)
		{
			if(cur1->data+cur2->data+cur3->data==sum)
			{
				cout<<cur1->data<<" "<<cur2->data<<" "<<cur3->data<<endl;
				return;
			}
			else if(cur1->data+cur2->data+cur3->data<sum)
				cur2=cur2->next;
			else
				cur3=cur3->next;
		}
		cur1=cur1->next;
	}
	cout<<"not found"<<endl;
		
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

	
	int n3;
	cin>>n3;
	Nodeptr head3=NULL;
	for(i=0;i<n3;i++)
	{
		cin>>data;
		head3=insert(head3,data);
	}

	printList(head1);
	printList(head2);
	printList(head3);

	int sum;
	cin>>sum;
	auxFunc(head1,head2,head3,sum);

	return 0;
}
		
