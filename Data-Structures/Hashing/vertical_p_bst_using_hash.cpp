#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;
};

Node* newNode(int a)
{
    Node* temp=new Node;
    temp->data=a;
    temp->right=NULL;
    temp->left=NULL;

    return temp;

}
void getverticalorder(Node* root, map<int,vector<int>>m,int hd)
{
	if(root==NULL)return;

	m[hd].push_back(root->data);
	getverticalorder(root->left,m,hd-1);
	getverticalorder(root->right,m,hd+1);
}


void printverticalorder(Node* root)
{
	map<int,vector<int>> m;
	int hd=0;
	getverticalorder(root,m,hd);

	map<int,vector<int>>:: iterator it;
	it=m.begin();

	for(;it!=m.end();it++)
			{  for(int i=0;i<it->second.size();i++)
					cout<<it->second[i]<<" ";
				cout<<endl;
}}

int main()
{
Node* root=newNode(2);
root->left=newNode(3);
root->right=newNode(4);
root->left->left=newNode(5);
root->left->right=newNode(6);
printverticalorder(root);
}
