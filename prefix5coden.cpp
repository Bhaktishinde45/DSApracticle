#include<iostream> 
#include<stack> 
#include<string> 
using namespace std; 
 
struct node 
{   char data; 
 node *left,*right; 
  
}; 
class tree 
{ 
 public: 
 node *root,*nnode,*curr; 
 stack<node*>s1,s2,s3; 
 
 void creation() 
 { 
  string exp; 
    cout<<"\n Enter the  expretion:-"; 
    int n; 
    cin>>exp; 
    cout<<"Prefix expreation:-"; 
    cout<<exp; 
    n=exp.length(); 
   /* for( int i=0; i<n;i++) 
     { 
      cin>>exp[i]; 
  }*/ 
   for(int i=n-1;i>=0;i--)  
   { 
    char ch; 
    ch=exp[i]; 
    nnode=new node(); 
    nnode->left=nnode->right=NULL; 
    nnode->data=ch; 
    if( (ch>=97 && ch<=122 ) || (ch>=65 && ch<=90 ) ) 
    { 
    s1.push(nnode); 
     } 
  else 
  { 
   
    if (s1.size() < 2) { 
                    cout << "Invalid expression\n"; 
                    return; 
                } 
     nnode->left=s1.top(); 
   s1.pop(); 
    nnode->right=s1.top();  
    s1.pop(); 
    
    s1.push(nnode); 
  }  }} 
    void display(node* temp) 
 {   
    if (temp!=NULL) 
    { 
     s2.push(temp); 
     while(!s2.empty()) 
     { 
          curr=s2.top(); 
          s3.push(curr); 
          s2.pop(); 
          if(curr->left!=NULL) 
          { 
           s2.push(curr->left); 
    } 
     if(curr->right!=NULL) 
          { 
           s2.push(curr->right); 
    } 
  } 
  while(!s3.empty()) 
  { 
  temp=s3.top(); 
  cout<<temp->data<<" "; 
  s3.pop(); 
  } 
  } 
   
 } 
  void display1(node* temp) 
 {  
  if( temp!=NULL) 
  {   
   display(temp->left); 
   display(temp->right); 
   cout<<temp->data; 
     
  } 
 } 
 void remove(node *temp) 
 {   
if(temp!=NULL) 
{ 
remove(temp->left); 
remove(temp->right); 
delete temp; 
}  
} 
}; 
int main() 
{ 
tree ob; 
ob.creation(); 
if (!ob.s1.empty())  
{ 
ob.root=ob.s1.top(); 
cout<<"\nPost order traversal="; 
ob.display(ob.root); 
ob.remove(ob.root); 
cout<<"\nTree is deleted"; 
ob.display1(ob.root); 
} 
return 0; 
} 
