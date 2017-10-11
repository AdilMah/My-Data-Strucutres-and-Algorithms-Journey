#include<bits/stdc++.h>
using namespace std;

class Minheap
{
  int* parr;//Pointer to array of heap elements   
  int capacity;//maximum possible size of the min heap
  int heap_size;//Stores current number of elements in min heap_size
  
  public:
  MinHeap(int capacity);
  void Minheapify(int);
  int parent(i){return (i-1)/2;}
  int left(i){return 2*i+1;}
  int right(i){return 2*i+2;}
  int extractmin();
  void DecreaseKey(int i,int new_val);
  int getMin(){return parr[0]};
  void deletekey(int i);
  void Insertkey(int k);
};
MinHeap::MinHeap(int cap)
{
  heap_size=0;
  capacity=cap;
  parr=new int[cap];
}

void MinHeap::InsertKey(int k)
{
  if(heap_size==capacity)
  {
    cout<<"\nOverflow:No more memory left"
    return;
  }
  heap_size++;
  int i=heap_size-1;
  parr[i]=k;
  
  while(i!=0 && parr[parent(i)>parr(i)]//Shifting Up 
  {
    swap(&parr[i],&parr[parent(i)]);
    i=parent(i);
  }
}

void MinHeap::extractmin()
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
  
  return 0;
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
      swap(&parr[smallest],&parr[i])
      Minheapify(smallest);
    }
}
void MinHeap::swap(int* a,int *b)
{
  *a=*a+*b;
  *a=*a-*b;
  *b=*a-*b;
}
int main()
{
 MinHeap heap_new(100); 
}
