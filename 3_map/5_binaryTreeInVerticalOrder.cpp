#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct treenode
{
	int data;
	struct treenode *left;
	struct treenode *right;
};

typedef struct treenode TreeNode;

TreeNode* levelOrderInsert(TreeNode* root, int arr[], int n)
{
	int index=0;
	if(root==NULL)
	{
		root=(TreeNode *) malloc(sizeof(TreeNode));
		root->data=arr[index++];
		root->left=root->right=NULL;
	}

		

	queue<TreeNode*> que;
	que.push(root);
	TreeNode * temp;
	while(que.size()!=0 && index<n)
	{
		temp=que.front();
		que.pop();
		if(temp->left)
		{
			que.push(temp->left);
		}
		else
		{
			TreeNode *newnode = (TreeNode*)malloc(sizeof(TreeNode));
			newnode->data=arr[index++];
			newnode->left=newnode->right=NULL;
			temp->left=newnode;
			que.push(temp->left);

		}
		
		if(index>=n)
			break;
		if(temp->right)
		{
			que.push(temp->right);
		}
		else
		{
			TreeNode *newnode = (TreeNode*)malloc(sizeof(TreeNode));
			newnode->data=arr[index++];
			newnode->left=newnode->right=NULL;
			temp->right=newnode;
			que.push(temp->right);
		}
	}
	return root;

}

void preorder(TreeNode *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void preTrav(TreeNode *root, int pos, map<int,vector<int> > &m1)
{
	if(root)
	{
		map<int,vector<int> >::iterator it;

		it=m1.find(pos);
		if(it==m1.end())
		{
			vector<int> temp;
			temp.push_back(root->data);
			m1.insert(pair<int,vector<int> >(pos,temp));
		}

		else
			(it->second).push_back(root->data);

		preTrav(root->left,pos-1,m1);
		preTrav(root->right,pos+1,m1);
	}
}
void auxFunc(TreeNode *root)
{
	map<int,vector<int> > m1;
	
	preTrav(root,0,m1);
	map<int,vector<int> >::iterator it;

	vector<int> cur;
	for(it=m1.begin();it!=m1.end();it++)
	{
		cout<<it->first<<" -> ";
		cur=it->second;
		for(int i=0;i<cur.size();i++)
			cout<<cur[i]<<" ";
		cout<<endl;
	}


}

int main()
{
	TreeNode *root=NULL;
	int n;

	cin>>n;
	int i,arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	root=levelOrderInsert(root,arr,n);

	preorder(root);
	cout<<endl;

	auxFunc(root);
	return 0;
}

