#include "queue.h"


//constructor to set default values to characteristics of Queue class
Queue::Queue(){
    head=NULL;
    tail=NULL;
}


//function to display data present in queue
void Queue::disp(){
    PNODE temp=tail;

    if(head==NULL){
        cout<<"Queue Empty";
    }

    else{
        cout<<"head -> ";
        while(temp!=NULL){
            cout<<temp->iData<<" -> ";
            temp=temp->next;
        }
        cout<<" tail"<<endl;
    }

    cout<<endl<<endl;
}


//function to create node of queue
PNODE Queue::create(int iVal){
    PNODE nn = new NODE;

    nn->prev=NULL;
    nn->iData=iVal;
    nn->next=NULL;

    return nn;
}


//function to put value in queue
void Queue::enqueue(int iVal){
    cout<<"enqueue "<<iVal<<endl;

    PNODE temp=NULL;

    temp=create(iVal);
    
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        head->next=temp;
        temp->prev=head;
        head=temp;
    }

    disp();
}


//function to remove value from queue
void Queue::dequeue(){
    cout<<"dequeue"<<endl;

    PNODE temp=NULL;
    temp=tail;

    if(tail==NULL){
        cout<<"queue Empty\n"<<endl;
        return;
    }
   
    if(tail->next == NULL){
        delete tail;
        tail=head=NULL;
    }
    else{
        tail=tail->next;
        delete tail->prev;
        tail->prev=NULL;
    }

    disp();
}