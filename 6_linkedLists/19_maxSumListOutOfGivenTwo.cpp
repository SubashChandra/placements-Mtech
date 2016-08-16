//having common nodes

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


Nodeptr auxFunc(Nodeptr A, Nodeptr B)
{
	Nodeptr A1,A2,B1,B2;
	A1=A2=A;
	B1=B2=B;


	Nodeptr ansHead,ansCur;
	ansHead=NULL;
	int sum1,sum2;
	sum1=sum2=0;
	while(A1 || B1)
	{
		int data1=(A1?A1->data:INT_MAX);
		int data2=(B1?B1->data:INT_MAX);

		
		if(data1<data2)
		{
			sum1+=A1->data;
			A1=A1->next;
		}
		else if(data1>data2)
		{
			sum2+=B1->data;
			B1=B1->next;
		}
		else
		{
			if(sum1>sum2)
			{
				while(A2!=A1)
				{
					if(ansHead==NULL)
						ansHead=A2;
					else
						ansCur->next=A2;
					ansCur=A2;
					A2=A2->next;
				}
				if(ansHead==NULL)
					ansHead=A1;
				else
					ansCur->next=A1;
				ansCur=A1;
			}
			else
			{
				while(B2!=B1)
				{
					if(ansHead==NULL)
						ansHead=B2;
					else
						ansCur->next=B2;
					ansCur=B2;
					B2=B2->next;
				}
				if(ansHead==NULL)
					ansHead=B1;
				else
					ansCur->next=B1;
				ansCur=B1;
			}
			A1=A1->next;
			A2=A1;
			B1=B1->next;
			B2=B1;
			sum1=sum2=0;
		}
	}

	if(sum1!=0 || sum2!=0)
	{
		if(sum1>sum2)
		{
			ansCur->next=A2;
		}
		else
		{
			ansCur->next=B2;
		}
	}

	
	return ansHead;


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
	Nodeptr ans=auxFunc(head1,head2);
	printList(ans);

	return 0;
}
		
