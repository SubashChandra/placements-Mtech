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

Nodeptr auxFunc(Nodeptr head)
{
	int flag=0;

	if(head==NULL|| head->next==NULL)
		return head;
	Nodeptr ans=head;
	while(head && head->next)
	{
		if(flag==0)
		{
			if(head->data>head->next->data)
				swap(head->data, head->next->data);
		}
		else
		{
			if(head->data<head->next->data)
				swap(head->data,head->next->data);
		}
		head=head->next;
		flag=(flag+1)%2;
	}
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
	head=auxFunc(head);
	printList(head);
	return 0;
}
		
