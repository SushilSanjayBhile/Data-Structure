#include "DLLL.h"

//constructor of Singly Linked List Class
DoublyLLL::DoublyLLL(){
	head=NULL;
	last=NULL;
}

//Destructor of Singly Linked List Class
DoublyLLL::~DoublyLLL(){
	delete head;
	delete last;
}

//create node function definition
PNODE2 DoublyLLL::Create(int iVal) {
	PNODE2 nn=NULL;

	nn=new NODE2;
	nn->prev=NULL;
	nn->iData=iVal;
	nn->next=NULL;

	return nn;
}


//insert_first function definition
void DoublyLLL::InsertFirst(int iVal) {
	PNODE2 temp=NULL;
	temp=Create(iVal);

	if(head==NULL) {
		head=last=temp;
	}

	else{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}

	Disp();
}



//insert at given position function definition
void DoublyLLL::InsertPosition(int iPos,int iVal) {
	int iMarker=0;

	if(iPos<0) {
		cout<<"Position is Invalid"<<endl;
		return;
	}

	//we can check length when flow enters in function but if position is negative then iterations to calculate length will all become waste
	int iLength=0;
	iLength=Length();

	if(iLength==0) {
		cout<<endl<<"Emapty List";
		return;
	}

	//else is not necessary here as above 'if' condition is true, then return will execute
	if(iPos>(iLength+1)) {
		cout<<"Invalid position"<<endl;
		return;
	}

	//we can allocate temp,temp1 when flow comes in function, but if position is invalid memory initialization will become waste
	PNODE2 temp=NULL,nn=NULL;

	temp=head;
	if(iPos==1){
		InsertFirst(iVal);
	}
	else if(iPos==iLength+1){
		InsertLast(iVal); 
	}
	else{
		nn=Create(iVal);

		for(iMarker=1;iMarker<iPos-1;iMarker++) {
			temp=temp->next;
		}

		nn->next=temp->next;
		temp->next=nn;
		nn->prev=temp;
		nn->next->prev=nn;
	}

	Disp();
}


//insert last function definition
void DoublyLLL::InsertLast(int iVal) {
	PNODE2 nn=NULL;
	nn=Create(iVal);

	if(head==NULL) {
		head=nn;
	}
	else {
		nn->next=last->next;
		nn->prev=last;
		last->next=nn;
	}

	last=nn;
	Disp();
}


//delete first node function definition
void DoublyLLL::DeleteFirst() {
	PNODE2 temp=NULL;

	if(head==NULL) {
		cout<<"Linked list empty"<<endl;
		return;
	}
	else if(head->next==NULL) {
		delete head;
		head=last=NULL;
	}
	else{
		temp=head;
		head=head->next;
		delete temp;
		head->prev=NULL;
	}

	Disp();
}


//delete node at given position
void DoublyLLL::DeletePosition(int iPos) {
	if(iPos<0) {
		cout<<"Position is Invalid"<<endl;
		return;
	}

	//we can check length when flow enters in function but if position is negative then iterations to calculate length will all become waste
	int iLength=0;
	iLength=Length();

	if(iLength==0) {
		cout<<endl<<"Emapty List";
		return;
	}

	//else is not necessary here as above 'if' condition is true, then return will execute
	if(iPos>iLength) {
		cout<<"Invalid position"<<endl;
		return;
	}

	if(iPos==1){
		DeleteFirst();
	}
	else if(iPos==iLength){
		DeleteLast();
	}
	else{
		PNODE2 temp=NULL;
		int iMarker=0;

		for(iMarker=1,temp=head;iMarker<iPos-1;iMarker++) {
			temp=temp->next;
		}

		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev=temp;
	}	
	Disp();
}


//delete node by value function definition
void DoublyLLL::DeleteByValue(int iVal) {
	PNODE2 temp=NULL;

	if(head==NULL) {
		cout<<endl<<"Empty linked list"<<endl;
		return;
	}
	else if(head->next==NULL) {
		if(head->iData==iVal) {
			delete head;
			head=NULL;
			return;
		}
	}
	else{
		for(temp=head;temp->next!=NULL;temp=temp->next) {
			if(temp->iData==iVal) {
				if(temp->next==NULL) {
					DeleteLast();
					break;
				}
				else if(temp->prev==NULL){
					DeleteFirst();
					break;
				}
				else{
					temp=temp->prev;
					temp->next=temp->next->next;
					delete temp->next->prev;
					temp->next->prev=temp;
					break;
			    }
            }
		}
	}
}


//delete last node function definition
void DoublyLLL::DeleteLast() {
	if(head==NULL) {
		return;
	}

	PNODE2 temp=head;

	while(temp->next!=NULL) {
		temp=temp->next;
	}

	if(temp->prev==NULL){
		DeleteFirst();
	}
	else{
		last=temp->prev;
		last->next=NULL;
		delete temp;
	}

	Disp();
}


//search node by its position function definition
int DoublyLLL::SearchByPosition(int iPos) {

	PNODE2 temp=NULL;
	int iMarker=0;

	if(iPos > Length()){
		cout<<"Invalid Position"<<endl;
		return 0;
	}
	temp=head;

	for(iMarker=1;(temp!=NULL)&&(iMarker!=iPos);temp=temp->next,iMarker++);

	if(iMarker!=iPos) {
		cout<<"Invalid position"<<endl;
		return 0;
	}

	else {
		cout<<temp->iData<<endl;
		return 0;
	}

}


//search node by its value fucntion defiition
int DoublyLLL::SearchByValue(int iVal) {

	PNODE2 temp=NULL;
	int iMarker=0;

	temp=head;

	for(iMarker=0;temp!=NULL;iMarker++,temp=temp->next) {
		if(temp->iData==iVal) {
			cout<<"Present"<<endl;
			return 0;
		}

	}

	cout<<"Not Present"<<endl;

	return 0;

}


//Disp function definition
void DoublyLLL::Disp() {
	PNODE2 temp=NULL;
	temp=head;

	while(temp!=NULL) {
		cout<<temp->iData<<" -> ";
		temp=temp->next;
	}
	cout<<endl;
}


//Disp function definition
void DoublyLLL::DispRev() {
	PNODE2 temp=NULL;
	temp=last;

	while(temp!=NULL) {
		cout<<temp->iData<<" -> ";
		temp=temp->prev;
	}
	cout<<endl;
}


//Calculates length of linked list function definition
int DoublyLLL::Length() {
	int iLen=0;
	PNODE2 temp=NULL;
	temp=head;

	if(head==NULL) {
		return 0;
	}

	while(temp!=NULL) {
		temp=temp->next;
		iLen++;
	}
	return iLen;
}