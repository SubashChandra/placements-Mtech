//if number is stored as linked list in normal way

#include<cstdio>
#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;
typedef Node *Nodeptr;

void printList(Nodeptr head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

int len(Nodeptr head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}

Nodeptr fillZeros(Nodeptr head, int count)
{
	Nodeptr temp;
	while(count>0)
	{
		temp=(Nodeptr)malloc(sizeof(Node));
		temp->data=0;
		temp->next=head;
		head=temp;
		count--;
	}
	return head;
}

Nodeptr auxFunc(Nodeptr head1, Nodeptr head2, int &carry)
{
	if(head1==NULL)
	{
		carry=0;
		return NULL;
	}

	Nodeptr curNode=(Nodeptr)malloc(sizeof(Nodeptr));
	curNode->data=head1->data+head2->data;
	int nextCarry;
	curNode->next=auxFunc(head1->next,head2->next,nextCarry);
	curNode->data+=nextCarry;

	carry=curNode->data/10;
	curNode->data=curNode->data%10;

	return curNode;
}




Nodeptr add(Nodeptr head1, Nodeptr head2)
{
	int n1=len(head1);
	int n2=len(head2);

	if(n1<n2)
		head1=fillZeros(head1,n2-n1);
	else if(n1>n2)
		head2=fillZeros(head2,n1-n2);

	int carry=0;
	Nodeptr ans = auxFunc(head1,head2,carry);
	if(carry==1)
	{
		Nodeptr temp=(Nodeptr)malloc(sizeof(Nodeptr));
		temp->data=carry;
		temp->next=ans;
		ans=temp;
	}
	return ans;

}
	
int main()
{
	int n1,n2,data;
	cin>>n1;
	Nodeptr head1,head2,cur,newnode;
	head1=cur=NULL;

	while(n1>0)
	{
		cin>>data;
		newnode=(Nodeptr)malloc(sizeof(Node));
		newnode->data=data;
		newnode->next=NULL;
		if(head1==NULL)
		{
			head1=cur=newnode;
		}
		else
		{
			cur->next=newnode;
			cur=newnode;
		}
		n1--;
	}

	head2=cur=NULL;
	cin>>n2;
	while(n2>0)
	{
		cin>>data;
		newnode=(Nodeptr)malloc(sizeof(Node));
		newnode->data=data;
		newnode->next=NULL;
		if(head2==NULL)
		{
			head2=cur=newnode;
		}
		else
		{
			cur->next=newnode;
			cur=newnode;
		}
		n2--;
	}


	printList(head1);
	printList(head2);

	Nodeptr ans=add(head1,head2);
	printList(ans);

	return 0;
}
