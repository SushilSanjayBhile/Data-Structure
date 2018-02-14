#include<iostream>
using namespace std;


//node structure using typedef
typedef struct node {
    struct node* prev;
	int iData;
	struct node* next;
}NODE, *PNODE;


//class declaration
class Queue{
    private:
        PNODE head;
        PNODE tail;
    public:
        Queue();
        void enqueue(int);
        void dequeue();
        void disp();
        PNODE create(int);
};