//
//  main.cpp
//  treetraversal
//
//  Created by Khushi Sidana on 18/10/21.
//

#include<iostream>
using namespace std;

//Declaring a structure
struct Tree
{
int value;
struct Tree *left;
struct Tree *right;
};

struct Tree *root=NULL;
struct Tree *temp;


//Function to add elements
void insertElements()
{
struct Tree *nc,*pNode;
    
//Taking user input
int val;
cout<<"Enter the Element: ";
cin>>val;

temp=new Tree;
temp->value=val;
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
{
root=temp;
}
else
{
nc=root;
while(nc!=NULL)
{
pNode=nc;
if(val<nc->value)
nc=nc->left;
else
nc=nc->right;
}
if(val<pNode->value)
{
pNode->left=temp;
}
else
pNode->right=temp;
}
}

//Function to get pre-order traversal
void preorder(struct Tree *temp)
{
if(temp!=NULL)
{
                cout<<temp->value<<" ";
                preorder(temp->left);
                preorder(temp->right);
}
}

//Function to get in-order traversal
void inorder(struct Tree *temp)
{
                if(temp!=NULL)
{
                inorder(temp->left);
                cout<<temp->value<<" ";
                inorder(temp->right);
}
}

//Function to get post-order traversal
void postorder(struct Tree *temp)
{
                if(temp!=NULL)
                {
                                postorder(temp->left);
                                postorder(temp->right);
                                cout<<temp->value<<" ";
                }
}


int main()
{
    //Taking the user input of the elements
    int num;
    cout<<"Enter the number of elements: ";
    cin>>num;
    cout<<endl;
    for( int i=0; i< num; i++)
    {
        insertElements();
    }
    
 int ch;
 while(1)
 {
cout<<"\n\n1.Preorder \n2.Inorder \n3.Postorder \n4.Exit";
  cout<<endl<<"Enter your choice: ";
  cin>>ch;
  switch(ch)
  {
    //When pre-order is selected
   case 1:preorder(root);
          break;
          
    //When in-order is selected
   case 2:inorder(root);
          break;
          
    //When post-order is selected
   case 3:postorder(root);
          break;
          
   case 4:exit(1);
          break;
          
   default:cout<<"Invalid Operation";
  }
 }
}
