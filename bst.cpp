#include<iostream>
#include<string.h>
using namespace std;
 
typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}node;
 
node *create();
void insert(node *,node *);
void preorder(node *);
void inorder(node *);
void postorder(node *);
 
int main()
{
    char ch;
    node *root=NULL,*temp;
    
    do
    {
        temp=create();
        if(root==NULL)
            root=temp;
        else    
            insert(root,temp);
            
        cout<<"\nDo you want to enter more(y/n)?: ";
        getchar();
        cin>>ch;
    }while(ch=='y'|ch=='Y');
    
    cout<<"\n Preorder Traversal: ";
    preorder(root);
    cout<<"\n Inorder Traversal: ";
    inorder(root);
    cout<<"\n Postorder Traversal: ";
    postorder(root);
    return 0;
}
 
node *create()
{
    node *temp;
    cout<< "\nEnter data:";
    temp=new node;
    cin>>temp->data;
    temp->left=temp->right=NULL;
    return temp;
}
 
void insert(node *root,node *temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    
    if(temp->data>root->data)
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}
 
void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}


void postorder(node *root)
{
    if(root!=NULL)
    {
        
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
