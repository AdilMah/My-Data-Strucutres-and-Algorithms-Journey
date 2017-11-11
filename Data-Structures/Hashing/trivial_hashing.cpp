//Index Mapping or Trivial Hashing
//Our task in to find whether the given number is present or not in constant time
#include<bits/stdc++.h>
using namespace std;

bool has[100][2]={false};
 

bool search(int X)
{   X=abs(X);//To cinvert negative values to positive
	//cout<<has[X][0];
	if(has[X][0]==1||has[X][1]==1)//Check whether the value is 1 or not
			return true;
	else
			return false;
}


void insert(int a[],int n)
{
	for(int i=0;i<n;i++){
		if(a[i]>=0)
			has[a[i]][0]=1;
		else
		    has[abs(a[i])][1]=1;
	}
}

int main()
{
	int arr[10]={-6,5,7,8,9,-1,2,6,10,-65};
	int x=-65;//To find whether the given number is presnt or not
    insert(arr,10);
    if(search(x))cout<<"Present\n";
    else
    	cout<<"Not Present";

}
