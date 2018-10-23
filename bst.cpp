#include<iostream>
#include<cstdlib>
using namespace std;
struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};
treeNode* FindMin(treeNode *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(node->left) 
        return FindMin(node->left);
    else if(node->right)
	return FindMin(node->right);
    
else
        return node;
}
treeNode *Insert(treeNode *node,int data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
        temp -> data = data;
        temp -> left =NULL;
	 temp -> right = NULL;
        return temp;
    }
    if(data >(node->data))
    {
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data))
    {
        node->left = Insert(node->left,data);
    }
        return node;
}
treeNode* Delet(treeNode *node, int data)
{
    treeNode *temp;
    if(node==NULL)
    {
        cout<<"Element Not Found";
    }
    else if(data < node->data)
    {
        node->left = Delet(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = Delet(node->right, data);
    }
    else
    {
        
        if(node->right && node->left)
        {
            temp = FindMin(node->right);
            node -> data = temp->data;
            node -> right = Delet(node->right,temp->data);
        }
        else
        {
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); 
        }
    }
    return node;
}
treeNode * Find(treeNode *node, int data)
{
    if(node==NULL)
    {
        
        return NULL;
    }
    if(data > node->data)
    {
        
        return Find(node->right,data);
    }
    else if(data < node->data)
    {
       return Find(node->left,data);
    }
    else
    {
        
        return node;
    }
}
void Inorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}
int main()
{
    treeNode *root = NULL,*temp;
    int ch;
    while(1)
    {
        cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Exit\n";
        cout<<"Enter ur choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter element to be insert:";
            cin>>ch;
            root = Insert(root, ch);
            cout<<"\nElements in BST are:";
            Inorder(root);
            break;
        case 2:
            cout<<"\nEnter element to be deleted:";
            cin>>ch;
            root = Delet(root,ch);
            cout<<"\nAfter deletion elements in BST are:";
            Inorder(root);
            break;
        case 3:
            cout<<"\nEnter element to be searched:";
            cin>>ch;
            temp = Find(root,ch);
            if(temp==NULL)
            {
                cout<<"Element is not found\n";
            }
            else
            {
                cout<<"Element "<<temp->data<<" is Found\n";
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"\nEnter correct choice:";
            break;
        }
    }
    return 0;
}
