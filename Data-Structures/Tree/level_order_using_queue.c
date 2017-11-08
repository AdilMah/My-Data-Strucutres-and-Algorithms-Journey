//Level Order Traversal using Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
/////////////////////////////////////////////
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

}T;
//////////////////////////////////////////////
void LevelOrder(T*);
void Enqueue(T*,int*,T**);
T* Dequeue(T**,int*);
T** createQueue(int *, int *);
//////////////////////////////////////////////
T* newnode(int value)
{
 	T* temp=(T*)malloc(sizeof(T));
 	temp->data=value;
 	temp->left=NULL;
 	temp->right=NULL;
 	return temp;

}
/////////////////////////////////////////////
void LevelOrder(T* root)
{
	T* temp=root;
    int front;
    int rear;
    T** queue=createQueue(&front,&rear);

    while(temp)
    {
    	printf("%d ",temp->data);
    	if(temp->left!=NULL)
    		Enqueue(temp->left,&rear,queue);
    	if(temp->right!=NULL)
    		Enqueue(temp->right,&rear,queue);
    	temp=Dequeue(queue,&front);
    }
}
/////////////////////////////////////////////
void Enqueue(T* temp,int* rear,T** queue)
{
    queue[*rear]=temp;

    (*rear)++;
}
/////////////////////////////////////////////
T* Dequeue(T** queue,int* front)
{
	T* temp=queue[*front];
	(*front)++;
	return temp;

}
/////////////////////////////////////////////
T** createQueue(int *front, int *rear)
{   *front=0;
	*rear=0;
    T **queue =(T**)malloc(sizeof(T*)*MAX_SIZE);
 
    *front = *rear = 0;
    return queue;
}
/////////////////////////////////////////////
int main()
{
	T* root=newnode(1);
	root->left=newnode(3);
	root->right=newnode(5);
	root->left->left=newnode(6);
	root->right->right=newnode(4);
	root->left->right=newnode(12);
	LevelOrder(root);

}
/////////////////////////////////////////////
