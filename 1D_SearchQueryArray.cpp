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


bool query(int *arr, int n, int x)                   // search elements x
{ 
	for(int k=0 ; k<n; k++) 
	{
	    if(arr[k]==x)
		return true;
    }
	
	return false;
}


int main()   
{ 
  int arr[10000];
  for(int i=0; i<10000; i++)
  arr[i] = i;
	
  for(int n=2000; n<=10000; n+=2000)
  {  
    cout<<"\n\tWhen n="<<n<<":"<<endl;

	
    double startTime;
	double endTime;                            
	
	startTime = time();   
 	for(int i=0; i<10000; i++)      
	update(arr, 0, n-1, 11);                                                        // update [2,5] by 9
    endTime = time(); 
    cout<<"Time taken by update function: "<< (endTime - startTime)/10000 <<" microseconds\n";
 
 	startTime = time(); 
    for(int i=0; i<10000; i++)    
	bool t =  query(arr,n,10000);                                                 // query to find 7
    endTime = time(); 
    cout<<"Time taken by search query function: "<< (endTime - startTime)/10000 <<" microseconds\n";    
  }
}

 







