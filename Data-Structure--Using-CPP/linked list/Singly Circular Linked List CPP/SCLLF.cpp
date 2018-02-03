#include "SCLL.h"

//constructor of Singly Linked List Class
SinglyCLL::SinglyCLL(){
	head=last=NULL;
}

//constructor of Singly Linked List Class
SinglyCLL::~SinglyCLL(){
	delete head;
	delete last;
}

//create node function definition
PNODE1 SinglyCLL::Create(int iVal) {
	PNODE1 nn=NULL;

	nn= new NODE1;
	nn->iData=iVal;
	nn->next=nn;

	return nn;
}


//insert_first function definition
void SinglyCLL::Insert_First(int iVal) {

	PNODE1 temp=NULL;
	temp=Create(iVal);

	if(head==NULL) {
		head=last=temp;
	}
	else{
		temp->next=head;
		head=temp;
		last->next=head;
	}
	Disp();
}



//insert at given position function definition
void SinglyCLL::Insert_Position(int iPos,int iVal) {
	
	int iMarker=0;
	int iLength=0;

	if(iPos<0) {
		cout<<"Position is Invalid"<<endl;
		return;
	}

	//we can check length when flow enters in function but if position is negative then iterations to calculate length will all become waste
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
	PNODE1 temp=NULL,temp1=NULL;

	if(iPos==(iLength+1)) {
		Insert_Last(iVal);		
		return;
	}

	temp=head;

	for(iMarker=1;iMarker<iPos-1;iMarker++) {
		temp=temp->next;
	}

	temp1=Create(iVal);
	temp1->next=temp->next;
	temp->next=temp1;

	if(temp1->next==head) {
		last=temp1;
	}
	Disp();
}


//insert last function definition
void SinglyCLL::Insert_Last(int iVal) {

	PNODE1 temp=NULL;
	temp=Create(iVal);

	if(head==NULL) {
		head=temp;
	}
	else {
		temp->next=last->next;
		last->next=temp;
	}
	last=temp;
	Disp();
}


//delete first node function definition
void SinglyCLL::Delete_First() {
	PNODE1 temp=NULL;
	temp=head;

	if(head==NULL) {
		cout<<"Linked list empty"<<endl;
		return;
	}

	if(temp->next==head) {
		delete head;
		last=head=NULL;
	}
	else{
		head=temp->next;
		delete temp;
		last->next=head;
	}
	Disp();
}


//delete node at given position
void SinglyCLL::Delete_Position(int iPos) {
	int iMarker=0;
	int iLength=0;

	if(iPos<0) {
		cout<<"Position is Invalid"<<endl;
		return;
	}

	//we can check length when flow enters in function but if position is negative then iterations to calculate length will all become waste
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

	PNODE1 temp=head,temp1=NULL;

	//if entered last position
	if(iPos==iLength) {
		if(head->next==head){
			delete head;
			head=last=NULL;
		}
		else{
			while(temp->next->next!=head){
				temp=temp->next;
			}
		
			temp1=temp->next;
			temp->next=head;
			last=temp;
			delete temp1;
		}
		return;
	}

	for(iMarker=1,temp=head;iMarker<iPos-1;iMarker++) {
		temp=temp->next;
	}

	temp1=temp->next;
	temp->next=temp1->next;
	delete temp1;

	if(temp->next==head) {
		last=temp;
	}
	Disp();
}


//delete node by value function definition
void SinglyCLL::Delete_By_Value(int iVal) {
	PNODE1 temp=NULL,temp1=NULL;

	if(head==NULL) {
		cout<<endl<<"Empty linked list"<<endl;
		return;
	}

	else if(head->next==head) {
		if(head->iData==iVal) {
			delete head;
			head=last=NULL;
			return;
		}
		else
			return;
	}

	for(temp=head,temp1=temp->next;temp->next!=head;temp=temp->next,temp1=temp1->next) {
		if(temp->iData==iVal) {
			if(temp1->next==head) {
				last=temp1;
			}

			head=temp1;
			last->next=head;
			delete temp;
		}
	}
	Disp();
}


//delete last node function definition
void SinglyCLL::Delete_Last() {
	PNODE1 temp=head,temp1=NULL;

	if(head==NULL) {
		return;
	}

	if(temp->next==head) {
		delete temp;
		head=last=NULL;
	}
	else{
		while(temp->next->next!=head)
			temp=temp->next;

		temp1=temp->next;
		temp->next=temp1->next;
		last=temp;
		delete temp1;
	}
	Disp();
}


//search node by its position function definition
int SinglyCLL::Search_By_Position(int iPos) {

	PNODE1 temp=NULL;
	int iMarker=0;
	temp=head;

	for(iMarker=1;(temp->next!=head)&&(iMarker!=iPos);temp=temp->next,iMarker++);

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
int SinglyCLL::Search_By_Value(int iVal) {

	PNODE1 temp=NULL;
	int iMarker=0;
	temp=head;

	do{
		if(temp->iData==iVal) {
			cout<<"Present"<<endl;
			return 0;
		}
		temp=temp->next;
	}while(temp!=head);

	cout<<"Not Present"<<endl;
	return 0;
}


//Disp function definition
void SinglyCLL::Disp() {

	PNODE1 temp=NULL;
	temp=head;

	do{
		cout<<temp->iData<<" -> ";
		temp=temp->next;
	}while(temp!=head);

	cout<<endl;
}


//Calculates length of linked list function definition
int SinglyCLL::Length() {

	cout<<endl;

	int iLen=0;
	PNODE1 temp=NULL;
	temp=head;

	if(head==NULL) {
		return 0;
	}

	do{
		temp=temp->next;
		iLen++;
	}while(temp!=head);

	return iLen;
}