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

Nodeptr auxFunc(Nodeptr head, int m, int n)
{
	if(head==NULL)
		return head;
	if(m==0)
		return NULL;

	Nodeptr cur=head,pre;
	int i=0;
	while(cur && i<m)
	{
		pre=cur;
		cur=cur->next;
		i++;
	}

	i=0;
	while(cur && i<n)
	{
		cur=cur->next;
		i++;

	}
	
	pre->next=auxFunc(cur,m,n);
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

	int m;
	cin>>m;
	cin>>n;
	head=auxFunc(head,m,n);

	printList(head);
	return 0;
}
		
