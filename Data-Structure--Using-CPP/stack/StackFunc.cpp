#include "stack.h"

//constructor which sets characteristics to default value
Stack::Stack(){
    top=NULL;
}


//destructor
Stack::~Stack(){
    delete top;
}


//function to display stack
void Stack::disp(){
    PNODE temp=top;

    if(top==NULL){
        cout<<"Stack Empty";
    }

    else{
        cout<<"TOP"<<endl;
  
        while(temp!=NULL){
            cout<<temp->iData<<endl;
            temp=temp->next;
        }
    }

    cout<<endl<<endl;
}


//function to create a node of stack structure
PNODE Stack::create(int iVal){
    PNODE nn = new NODE;
    nn->iData=iVal;
    nn->next=NULL;

    return nn;
}


//push function to store data on top of the stack
void Stack::push(int iVal){
    cout<<"push "<<iVal<<endl;

    PNODE temp=NULL;

    temp=create(iVal);
    
    if(top==NULL){
        top=temp;
    }
    else{
        temp->next=top;
        top=temp;
    }

    disp();
}


//pop function definition which removes the value present on the top of the stack
void Stack::pop(){
    cout<<"pop"<<endl;

    PNODE temp=NULL;
    temp=top;

    if(top==NULL){
        cout<<"Stack Empty"<<endl<<endl;
        return;
    }

    top=top->next;
    delete temp;

    disp();
}