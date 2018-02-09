using namespace std;
#include<iostream>


//node structure using typedef
typedef struct node {
	int iData;
	struct node* next;
}NODE, *PNODE;


//class declaration
class Stack{
    private:
        PNODE top;
    public:
        Stack();
        ~Stack();
        void push(int);
        void pop();
        void disp();
        PNODE create(int);
};