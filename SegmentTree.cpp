#include<bits/stdc++.h>
#include <sys/time.h>
using namespace std;


long time()                                                        // time in micro seconds
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}
 

void buildLazySegmentTree(int *arr, int *ST, int rStart, int rEnd, int iCurrNode)      
{
	if(rStart == rEnd)
	{   ST[iCurrNode] = arr[rStart];
	    return;   }
	 
	 
	int rMid = (rStart+rEnd)/2;
	
	buildLazySegmentTree(arr, ST, rStart, rMid, 2*iCurrNode);	
	buildLazySegmentTree(arr, ST, rMid+1, rEnd, 2*iCurrNode+1);


	ST[iCurrNode] = ST[2*iCurrNode] + ST[2*iCurrNode+1]; 
}


void rangeUpdate_inLazySegmentTree(int *ST, int *PU, int rStart, int rEnd, int rLeft, int rRight, int x, int iCurrNode)
{
	if(PU[iCurrNode] !=0)                         // handlingPendingUpdates
	{
		ST[iCurrNode] += (rEnd-rStart+1)*PU[iCurrNode];

		if(rStart != rEnd)
		{	PU[2*iCurrNode] += PU[iCurrNode];
			PU[2*iCurrNode+1] += PU[iCurrNode];	  }
		
		PU[iCurrNode] = 0;
	}

	    
	if(rRight<rStart || rEnd<rLeft) 
	return;
	else if(rLeft<=rStart  && rEnd<=rRight)
	{	ST[iCurrNode] += (rEnd-rStart+1)*x;     // handlingCurrentUpdates
		
		if(rStart != rEnd)                      // PU[iCurrNode] is already handled
		{	PU[2*iCurrNode] += x;
			PU[2*iCurrNode+1] += x;   }
		
		return;	  }
		
	
	int rMid = (rStart+rEnd)/2;
	  
	rangeUpdate_inLazySegmentTree(ST, PU, rStart, rMid, rLeft, rRight, x, 2*iCurrNode);
	rangeUpdate_inLazySegmentTree(ST, PU, rMid+1, rEnd, rLeft, rRight, x, 2*iCurrNode+1);
 
	ST[iCurrNode] = ST[2*iCurrNode] + ST[2*iCurrNode+1]; 
}


int rangeQuery_inLazySegmentTree(int *ST, int *PU, int rStart, int rEnd, int rLeft, int rRight, int iCurrNode)     
{
	if(PU[iCurrNode] != 0)                       // handlingPendingUpdates
	{
		ST[iCurrNode] += (rEnd-rStart+1)*PU[iCurrNode];
		 
		if(rStart != rEnd)
		{   PU[2*iCurrNode] += PU[iCurrNode];   
			PU[2*iCurrNode+1] += PU[iCurrNode];   }	 
	 
		PU[iCurrNode] = 0;
	}
	
	
	if(rRight<rStart || rEnd<rLeft) 
	return 0;
	else if(rLeft<=rStart  && rEnd<=rRight)
	return ST[iCurrNode];
	
	
	int rMid=(rStart+rEnd)/2;
	
	int ans1 = rangeQuery_inLazySegmentTree(ST, PU, rStart, rMid, rLeft, rRight, 2*iCurrNode);
	int ans2 = rangeQuery_inLazySegmentTree(ST, PU, rMid+1, rEnd, rLeft, rRight, 2*iCurrNode+1);
	
	ST[iCurrNode] = ST[2*iCurrNode] + ST[2*iCurrNode+1];       // weAreHandlingPendingUpdatesAlso soWeNeedToDoTheUpdation 
	return (ans1 + ans2);
}
 	 
  
int main() 
{
  int arr[50000];
  for(int i=0; i<50000; i++)
  arr[i] = i;
	
  for(int n=10000; n<=50000; n+=10000)
  {  
    cout<<"\n\tWhen n="<<n<<":"<<endl;
    
  
	int ST[4*n] = {0};                                                                     // Segment Tree 
	int PU[4*n] = {0};                                                                     // Lazy Tree  
	buildLazySegmentTree(arr, ST, 0, n-1, 1);                                              // building Segment Tree                   
			

    double startTime;
	double endTime;                            
	
	startTime = time();   
	for(int i=0; i<1000000; i++)      
	rangeUpdate_inLazySegmentTree(ST, PU, 0, n-1, 0, 0, 0, 1);                             // increases all elements in [2,5] by 0 
    endTime = time(); 
    cout<<"Time taken by update function: "<< (endTime - startTime)/1000000 <<" microseconds\n";
 
 	startTime = time(); 
	for(int i=0; i<1000000; i++)    
	int t = rangeQuery_inLazySegmentTree(ST, PU, 0, n-1, 0, 0, 1) ;              // query to find sum in [2,6]
    endTime = time(); 
    cout<<"Time taken by sum query function: "<< (endTime - startTime)/1000000 <<" microseconds\n"; 
  }
}









