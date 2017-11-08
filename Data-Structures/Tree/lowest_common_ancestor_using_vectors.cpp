#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

}T;
T* newnode(int );
int FindLCA(T*, int, int);
bool findpath(T*, vector<int>,int);
int main()
{
	T* root=newnode(1);
	root->left=newnode(3);
	root->right=newnode(5);
	root->left->left=newnode(6);
	root->right->right=newnode(4);
	root->left->right=newnode(12);
	cout<<FindLCA(root,3,5);
    cout<<"adil";
}

int FindLCA(T* root, int n1, int n2)
{
	vector<int>path1,path2;
	if(!findpath(root,path1,n1)&&!findpath(root,path2,n2))
			return -1;
	int i;
	for(int i=0;i<path1.size()&&i<path2.size();i++)
			if(path1[i]!=path2[i])
					break;
	return path1[i-1];
}

bool findpath(T* root, vector<int>path1,int n)
{
	if(root==NULL)return false;
	if(root->data==n)return root;

	if((root->left&&findpath(root,path1,n))||(root->right && findpath(root,path1,n)))
						return true;

	path1.pop_back();
	return false;
}

T* newnode(int value)
{
 	T* temp=(T*)malloc(sizeof(T));
 	temp->data=value;
 	temp->left=NULL;
 	temp->right=NULL;
 	return temp;

}
