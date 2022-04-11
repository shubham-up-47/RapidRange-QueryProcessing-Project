#include<bits/stdc++.h>
#include <sys/time.h>
using namespace std;


long time()                          // time in micro seconds
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}
 

void update(int *arr, int i, int j, int x)          // update [i,j] to x
{ 
	for(int k=i ; k<=j; k++)                                           
	arr[k] += x;
}


int query(int *arr, int i, int j)                   // sum of elements in [0,i]
{
	int sum = 0;
	
	for(int k=i ; k<=j; k++) 
	sum += arr[k];  
	
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

	
    double startTime;
	double endTime;                            
	
	startTime = time();   
	for(int i=0; i<10000; i++)      
	update(arr, 0, 10000, 11);                                                          // update [2,5] by 11
    endTime = time(); 
    cout<<"Time taken by update function: "<< (endTime - startTime)/10000 <<" microseconds\n";
 
 	startTime = time(); 
	for(int i=0; i<10000; i++)    
	int t =  query(arr,0,10000);                                                     // query to find sum in [2,6]
    endTime = time(); 
    cout<<"Time taken by sum query function: "<< (endTime - startTime)/10000 <<" microseconds\n";        
  }
}

 







