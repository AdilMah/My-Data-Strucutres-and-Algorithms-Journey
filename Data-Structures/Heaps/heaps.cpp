#include<bits/stdc++.h>
using namespace std;
void swap(int*,int*);
class MinHeap
{
  int* parr;//Pointer to array of heap elements   
  int capacity;//maximum possible size of the min heap
  int heap_size;//Stores current number of elements in min heap_size
  
  public:
  MinHeap(int capacity);
  void Minheapify(int);
  int parent(int i){return (i-1)/2;}
  int left(int i){return 2*i+1;}
  int right(int i){return 2*i+2;}
  int extractmin();
  void DecreaseKey(int i,int new_val);
  int getMin(){return parr[0];}
  void deletekey(int i);
  void insertkey(int k);
};
MinHeap::MinHeap(int cap)
{
  heap_size=0;
  capacity=cap;
  parr=new int[cap];
}

void MinHeap::insertkey(int k)
{
  if(heap_size==capacity)
  {
    cout<<"\nOverflow:No more memory left";
    return;
  }
  heap_size++;
  int i=heap_size-1;
  parr[i]=k;
  
  while(i!=0 && parr[parent(i)]>parr[i])//Shifting Up 
  {
    swap(&parr[i],&parr[parent(i)]);
    i=parent(i);
  }
}

int MinHeap::extractmin()
{
  if(heap_size<=0)
    return INT_MAX;
  if(heap_size==1)
    {heap_size--;
    return parr[0];}
  
  int root=parr[0];
  parr[0]=parr[heap_size-1];
  heap_size--;
  Minheapify(0);
  
  return root;
}
void MinHeap::Minheapify(int i)
{
  int lt=left(i);
  int rt=right(i);
  int smallest=i;
  
  if(lt<heap_size && parr[lt]<parr[i])
        smallest=lt;
  if(rt<heap_size && parr[rt]<parr[smallest])
        smallest=rt;
  if(smallest!=i)
    {
      swap(&parr[smallest],&parr[i]);
      Minheapify(smallest);
    }
}
void swap(int* a,int* b)
{
  *a=*a+*b;
  *b=*a-*b;
  *a=*a-*b;
}
void MinHeap::DecreaseKey(int i,int value)
{
  parr[i]=value;
  while(i!=0 && parr[parent(i)]>parr[i])
    {swap(&parr[parent(i)],&parr[i]);
    i=parent(i);}
}


int main()
{
 MinHeap heap_new(100); 
 heap_new.insertkey(56);
 heap_new.insertkey(21);
 heap_new.insertkey(10);
 heap_new.insertkey(98);
 heap_new.insertkey(-58);
 heap_new.insertkey(2);
 heap_new.insertkey(51);
 heap_new.insertkey(59);
 heap_new.insertkey(62);
 heap_new.insertkey(44);
 heap_new.insertkey(11);
 heap_new.insertkey(22);
 cout<<heap_new.getMin();
 cout<<"\nMinimum Element::"<<heap_new.extractmin();
 cout<<endl<<"Minimum Deleted\n";
 
}
