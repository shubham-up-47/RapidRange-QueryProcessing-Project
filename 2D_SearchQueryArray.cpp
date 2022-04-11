#include<bits/stdc++.h>
#include <sys/time.h>
using namespace std;


long time()                          // time in micro seconds
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}
 

void update(int arr[][2], int n, int x, int y, int p, int q)     // update {x,y} to {p,q}
{ 
	for(int k=0; k<n; k++)                                           
	{
	    if(arr[k][0]==x && arr[k][1]==y)
		{   arr[k][0] = p;
		    arr[k][1] = q;
		    return;   }
    }
}


bool query(int arr[][2], int n, int x, int y)                   // search elements {x,y}
{ 
	for(int k=0; k<n; k++) 
	{
	    if(arr[k][0]==x && arr[k][1]==y)
		return true;
    }
	
	return false;
}


int main()   
{ 
  int arr[10000][2];
  for(int i=0; i<10000; i++)
  { arr[i][0] = i;
    arr[i][1] = i+1; }
	
  for(int n=2000; n<=10000; n+=2000)
  {  
    cout<<"\n\tWhen n="<<n<<":"<<endl;

	
    double startTime;
	double endTime;                            
	
	startTime = time();   
 	for(int i=0; i<10000; i++)      
	update(arr, n, 10000, 10000, 10000, 10000);                                                    // update {2,2} to {4,4}
    endTime = time(); 
    cout<<"Time taken by update function: "<< (endTime - startTime)/1000 <<" microseconds\n";
 
 	startTime = time(); 
    for(int i=0; i<10000; i++)     
	bool t =  query(arr,n,10000,10000);                                                     // query to find {2,2}
    endTime = time(); 
    cout<<"Time taken by search query function: "<< (endTime - startTime)/1000 <<" microseconds\n";    
  }
}

 







