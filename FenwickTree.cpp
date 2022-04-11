#include<bits/stdc++.h>
#include <sys/time.h>
using namespace std;


long time()                          // time in micro seconds
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}
 

void update(int *BIT, int n, int i, int x)         // increase arr[i] by x
{ 
	for(int iCN=i+1 ; iCN<n+1; iCN+=(iCN&(-iCN)))  // leftShiftRightmostSetBitOf'iCN'(indexNoOfCurrentNode) toReachIt's/Ancestor'sRightSiblings                       
	BIT[iCN] += x;
}


int query(int* BIT, int i)                         // sum of elements in [0,i]
{
	int sum = 0;
	
	for(int iCN=i+1;  iCN>0;  iCN-=(iCN&(-iCN)))   // removeRightmostSetBitOf'iCN'(indexNoOfCurrentNode) toReachIt'sParent/Ancestor
	sum += BIT[iCN];  
	
	return sum;
}


int main()          // FenwickTree/BinaryIndexedTree/BIT (noNeedToImplementBuildTreeFunction butInitializeBITarrayByZero)
{  
  int arr[50000];
  for(int i=0; i<50000; i++)
  arr[i] = i;
	
  for(int n=10000; n<=50000; n+=10000)
  {  
    cout<<"\n\tWhen n="<<n<<":"<<endl;

	
	int BIT[n+1]={0};                                                                      // Fenwick Tree (BIT) 
	for(int i=0; i<n; i++)                                                              
	update(BIT, n, i, (arr[i]-0));                                                         // building Fenwick Tree 
		

    double startTime;
	double endTime;                            
	
	startTime = time();   
	for(int i=0; i<100000000; i++)       
	update(BIT, n, n, 0);                                                                 // update arr[2] by 11
    endTime = time(); 
    cout<<"Time taken by update function: "<< (endTime - startTime)/100000000 <<" microseconds\n";
 
 	startTime = time(); 
	for(int i=0; i<100000000; i++)    
	int t =  query(BIT,n) - query(BIT, n/2);                                                  // query to find sum in [2,6]
    endTime = time(); 
    cout<<"Time taken by sum query function: "<< (endTime - startTime)/100000000 <<" microseconds\n";      
  }
}

 







