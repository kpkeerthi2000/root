#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;
 
struct avlnode
{
    int data;
    struct avlnode *left;
    struct avlnode *right;
}*root;
 
class avlTree
{
    public:
int height(avlnode *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int lheight = height (temp->left);
        int rheight = height (temp->right);
        int maxheight = max (lheight, rheight);
        h = maxheight+ 1;
    }
    return h;
}
 
int nullpathlength(avlnode *temp)
{
    int lheight = height (temp->left);
    int rheight = height (temp->right);
    int bfactor= lheight - rheight;
    return bfactor;
}
 
avlnode* rrrotation(avlnode *parent)
{
    avlnode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
avlnode* llrotation(avlnode *parent)
{
    avlnode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
avlnode* lrrotation(avlnode *parent)
{
    avlnode *temp;
    temp = parent->left;
    parent->left = rrrotation (temp);
    return llrotation (parent);
}
 
avlnode* rlrotation(avlnode *parent)
{
    avlnode *temp;
    temp = parent->right;
    parent->right = llrotation (temp);
    return rrrotation (parent);
}
 
avlnode* balance(avlnode *temp)
{
    int balfactor = nullpathlength(temp);
    if (balfactor > 1)
    {
        if (nullpathlength(temp->left) > 0)
            temp = llrotation (temp);
        else
            temp = lrrotation (temp);
    }
    else if (balfactor < -1)
    {
        if (nullpathlength(temp->right) > 0)
            temp = rlrotation (temp);
        else
            temp = rrrotation (temp);
    }
    return temp;
}
 
avlnode* insert(avlnode *root, int value)
{
    if (root == NULL)
    {
        root = new avlnode;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}
 
avlnode* display(avlnode *ptr)
{
    int i;
    if (ptr!=NULL)
    {
       avlTree::display(ptr->left);
       cout<<ptr->data<<endl;
      avlTree:: display(ptr->right);
    }
}

};
 
int main()
{
    int choice, item;
    avlTree avl;
    while (1)
    {
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            root = avl.insert(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display(root);
            break;
        case 3:
            exit(1);    
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
 
 

