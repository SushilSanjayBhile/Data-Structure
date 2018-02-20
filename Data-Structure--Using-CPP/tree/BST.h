//inclusion of required header file
#include<iostream>
using namespace std;

//node structure
typedef struct node{
    struct node *left;
    int iData;
    struct node *right;
}NODE,*PNODE;


//class of BST
class BST{
    private:
       PNODE root;
    public:
        BST();
        ~BST();
        PNODE CreateNode(int);
        void Insert(int);
        void Delete(int);
        void Search(int);
        void PreOrder();
        void PreOrder1(PNODE);
        void InOrder(PNODE);
        void PostOrder();
        void PostOrder1(PNODE);
};