#include "BST.h"

//BST class constructor
BST::BST(){
    root=NULL;
}


//BST destructor
BST::~BST(){
    delete root;
}


//creates a node
PNODE BST::CreateNode(int iVal){
    PNODE nn=new NODE;

    nn->iData=iVal;
    nn->left=NULL;
    nn->right=NULL;

    return nn;
}


//Insert node function definition
void BST::Insert(int iVal){
    cout<<endl<<"Insert "<<iVal<<endl;
    PNODE nn=NULL,tempRoot=NULL;
    
    tempRoot=root;
    nn=CreateNode(iVal);

    if(root==NULL){
        root=nn;
    }
    else{
        while(1){

            //takes flow to left
            if((tempRoot->iData)>iVal){
                if(tempRoot->left==NULL){
                    tempRoot->left=nn;
                    break;
                }
                else{
                    tempRoot=tempRoot->left;
                }
            }

            //takes flow to right
            else if((tempRoot->iData)<iVal){
                if(tempRoot->right==NULL){
                    tempRoot->right=nn;
                    break;
                }
                else{
                    tempRoot=tempRoot->right;
                }
            }

            //breaks the loop
            else{
                break;
            }
        }
    }

    InOrder(root);
    cout<<endl;
}


//inorder function definition
void BST::InOrder(PNODE tempRoot){
    if(tempRoot==NULL)
        return;

    InOrder(tempRoot->left);
    cout<<tempRoot->iData<<" ";
    InOrder(tempRoot->right);
}


//this function is needed because we cannot call preorder function from main function
//by sending the root, because root is private to class.
void BST::PreOrder(){
    cout<<endl<<"Preorder:"<<endl;
    PreOrder1(root);
}


//function to print preorder of given tree
void BST::PreOrder1(PNODE tempRoot){
    if(tempRoot==NULL)
        return;

    cout<<tempRoot->iData<<" ";
    PreOrder1(tempRoot->left);
    PreOrder1(tempRoot->right);
}


//this function is needed because we cannot send root from main function to this function,
//because root is private to class.
void BST::PostOrder(){
    cout<<endl<<endl<<"postorder:"<<endl;
    PostOrder1(root);
}


//this function prints postorder of the given tree
void BST::PostOrder1(PNODE tempRoot){
    if(tempRoot==NULL)
        return;

    PostOrder1(tempRoot->left);
    PostOrder1(tempRoot->right);
    cout<<tempRoot->iData<<" ";
}