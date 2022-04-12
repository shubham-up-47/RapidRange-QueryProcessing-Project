#include<bits/stdc++.h>
#include <sys/time.h>
using namespace std;


long time()                          // time in micro seconds
{
   struct timeval start;
   gettimeofday(&start,NULL);
   return (start.tv_sec*1000000 + start.tv_usec); 
}
 

const int k = 2;                                                       // 2D KD tree


struct Node
{
	int point[k]; 
	Node *left, *right;
};


struct Node* newNode(int arr[])
{
	struct Node* temp = new Node;

	for (int i=0; i<k; i++)
	temp->point[i] = arr[i];

	temp->left = temp->right = NULL;
	return temp;
}


Node *insertRec(Node *root, int point[], unsigned depth)
{ 
	if (root == NULL)
	return newNode(point);
  
	unsigned cd = depth % k;                                           //   current dimension (cd) of comparison
 
	if(point[cd] < (root->point[cd]))
	root->left = insertRec(root->left, point, depth + 1);
	else
	root->right = insertRec(root->right, point, depth + 1);

	return root;
}


Node* insert(Node *root, int point[])
{
	return insertRec(root, point, 0);
}


Node *minNode(Node *x, Node *y, Node *z, int d)
{
    Node *res = x;
    if (y != NULL && y->point[d] < res->point[d])
       res = y;
    if (z != NULL && z->point[d] < res->point[d])
       res = z;
    return res;
}
  
  
Node *findMinRec(Node* root, int d, unsigned depth)
{ 
    if(root == NULL)
    return NULL;
  
 
    unsigned cd = depth % k;
   
    if(cd == d)
    {
        if(root->left == NULL)
        return root;
        else
        return findMinRec(root->left, d, depth+1);
    }
   
    return minNode(root, findMinRec(root->left,d,depth+1), findMinRec(root->right, d, depth+1), d);
}
  
  
Node *findMin(Node* root, int d)
{ 
    return findMinRec(root, d, 0);
}


bool arePointsSame(int point1[], int point2[])
{ 
	for(int i=0; i<k; ++i)
	{
		if(point1[i] != point2[i])
		return false;
    }
    
	return true;
}


void copyPoint(int p1[], int p2[])
{
    for(int i=0; i<k; i++)
    p1[i] = p2[i];
}


Node *deleteNodeRec(Node *root, int point[], int depth)
{ 
    if(root == NULL)
    return NULL;
  
  
    int cd = depth % k;
   
    if (arePointsSame(root->point, point))
    {
    	
        if(root->right != NULL)
        { 
            Node *min = findMin(root->right, cd); 
            copyPoint(root->point, min->point); 
            root->right = deleteNodeRec(root->right, min->point, depth+1);
        }
        else if(root->left != NULL) 
        {
            Node *min = findMin(root->left, cd);
            copyPoint(root->point, min->point);
            root->right = deleteNodeRec(root->left, min->point, depth+1);
        }
        else 
        {
            delete root;
            return NULL;
        }
        return root;
    }
   
   
    if(point[cd] < root->point[cd])
    root->left = deleteNodeRec(root->left, point, depth+1);
    else
    root->right = deleteNodeRec(root->right, point, depth+1);
    
	return root;
}
  
  
 Node* deleteNode(Node *root, int point[])
{ 
   return deleteNodeRec(root, point, 0);
}


bool searchRec(Node* root, int point[], unsigned depth)                //  depth is used to determine current axis
{ 
	if(root == NULL)
	return false;
	else if(arePointsSame(root->point, point))
	return true;
 
	unsigned cd = depth % k;
 
	if(point[cd] < root->point[cd])
	return searchRec(root->left, point, depth + 1);
    else
	return searchRec(root->right, point, depth + 1);
}

 
bool search(Node* root, int point[])
{ 
	return searchRec(root, point, 0);
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

	
	struct Node *root = NULL;
	for(int i=0; i<n; i++)
	root = insert(root, arr[i]);                                                    // building Kd Tree
 
 
    double startTime;
	double endTime;                            
	
	startTime = time();   
 	for(int i=0; i<10000; i++)                                                    // update function
	{   root = insert(root, arr[500]);                                                    
        root = deleteNode(root, arr[500]);   }
    endTime = time(); 
    cout<<"Time taken by update function: "<< (endTime - startTime)/10000 <<" microseconds\n";
 
 	startTime = time(); 
 	for(int i=0; i<10000; i++)    
	bool t = search(root, arr[500]);                                                  // search query function
    endTime = time(); 
    cout<<"Time taken by search query function: "<< (endTime - startTime)/10000 <<" microseconds\n";  
  }
}









