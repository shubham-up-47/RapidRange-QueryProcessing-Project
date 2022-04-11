#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;


long time()                          // time in micro seconds
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}
 
  
 // BST(Binary Search Tree) =  sorted Binary Tree, inspired by Binary Search 
 
template <typename T> 
class BinaryTreeNode                                       // class for creating a node of BST                                                                                 
{      public:
	T data;                                            
	BinaryTreeNode *left;                     
	BinaryTreeNode *right;                         
 
	BinaryTreeNode(T d)                                  
	{  data = d;
	   left = NULL;
	   right = NULL;   }  
};     
                                                                          
class BST                                                  // class for creating a BST                      
{
	BinaryTreeNode<int> *root;
	                       
	   public:
	BST()
	{  root = NULL;	 }
	 
	   private:
	BinaryTreeNode<int>* remove(int x, BinaryTreeNode<int> *pp)
	{  
	   if(pp==NULL)
	   return pp;
	   
	   if(x < pp->data)
	   pp->left = remove(x, pp->left);
	   else if(x > pp->data)
	   pp->right = remove(x, pp->right); 
	   else                                                // removing/deleting root node of current BST
	   {  if(pp->left==NULL && pp->right==NULL)           
	   	  {  delete pp;
	   	  
	   	     pp = NULL;	 }
	   	  else if(pp->left==NULL)
	   	  {  BinaryTreeNode<int> *temp = pp->right;
	   	     pp->right = NULL;
	   	     delete pp;
	   	     
	   	     pp = temp;  }
	   	  else if(pp->right==NULL)
	   	  {  BinaryTreeNode<int> *temp = pp->left;
	   	     pp->left = NULL;
	   	     delete pp;
	   	     
	   	     pp = temp;  }
	   	  else 
	   	  {  BinaryTreeNode<int> *temp = pp->right;
	   	  
	   	     while(temp->left != NULL)
	   	     temp = temp->left;
	   	     
	   	     int rightBST_min = temp->data;
	   	     pp->data = rightBST_min;                      // making min element of right child BST as new root
	   	   
	   	     pp->right = remove(rightBST_min, pp->right);  }   } 
	   	     
	   return pp;	     
	} 
	                                                                                                        
	bool search(int x, BinaryTreeNode<int> *pp)
	{
	   if(pp==NULL)
	   return 0;   
	   
	   if(pp->data == x)
	   return 1;
	   else if(x > pp->data)
	   return search(x, pp->right);
	   if(x < pp->data)
	   return search(x, pp->left);
	   
	   return 0;
	}
	 
	BinaryTreeNode<int>* insert(int x, BinaryTreeNode<int> *pp)
    {
   	   if(pp==NULL)
	   {  BinaryTreeNode<int> *np = new BinaryTreeNode<int>(x);
	      return np;  }   
	   
	   if(x < pp->data)
	   pp->left = insert(x, pp->left);
	   else if(x >= pp->data)
	   pp->right = insert(x, pp->right); 
	   
	   return pp;
	}	
	
	    public:                // pp is not a input in these function, so create private helper functions, to apply recursion 
	void remove(int x)
	{  root = remove(x, root);	}
	
	bool search(int x)
	{  return search(x, root);  }
	 
    void insert(int x)
    {  root = insert(x, root);  } 
};

                  
int main()
{ 
  int arr[10000];
  for(int i=0; i<10000; i++)
  arr[i] = i;
	
  for(int n=2000; n<=10000; n+=2000)
  {  
    cout<<"\n\tWhen n="<<n<<":"<<endl;

	
	BST b;                                                
    for(int i=0; i<200; i++)
    b.insert(arr[i]);                                                               // building BST 
 
 
    double startTime;
	double endTime;                            
	
	startTime = time();   
	for(int i=0; i<10000; i++)                                                   // update function
	{   b.insert(10000);                                                    
        b.remove(10000);   }
    endTime = time(); 
    cout<<"Time taken by update function: "<< (endTime - startTime)/10000 <<" microseconds\n";
 
 	startTime = time(); 
	for(int i=0; i<10000; i++)    
	bool t = b.search(10000);                                                   // search query function
    endTime = time(); 
    cout<<"Time taken by search query function: "<< (endTime - startTime)/10000 <<" microseconds\n";  
  }
}
      

/*
 
use (recursion) most of the times to solve question related to (tree), considering (current node) as (parent node) 
BST = (left child data) < (parent data) <= (right child data)
Balanced BST = (ideal BST), (O(h) = O(logn)), ( |left child BST height - right child BST height| <= 1 )
(r=root), (rp=rootPointer), (c=child), (cp=childPointer), (p=parent), (pp=parentPointer), (ppList=parentPointerList), (n=noOfChildren)   

*/

                                                        

                                                                                    






 





