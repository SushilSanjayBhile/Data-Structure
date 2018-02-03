#include<iostream>
using namespace std;
#include "SLLL.h"

//constructor of Singly Linked List Class
SinglyLLL::SinglyLLL(){
	head=last=NULL;
}

//Destructor of SinglyLLL
SinglyLLL::~SinglyLLL(){
	delete head;
	delete last;
}

//create node function definition
PNODE1 SinglyLLL::Create(int iVal) {
	PNODE1 nn=NULL;

	nn=new NODE1;
	nn->iData=iVal;
	nn->next=NULL;

	return nn;
}


//insert_first function definition
void SinglyLLL::Insert_First(int iVal) {

	PNODE1 temp=NULL;
	temp=Create(iVal);

	if(head==NULL) {
		head=last=temp;
	}
	else{
		temp->next=head;
		head=temp;
	}
	
	Disp();
}



//insert at given position function definition
void SinglyLLL::Insert_Position(int iPos,int iVal) {
	
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
	PNODE1 temp=NULL,temp1=NULL;
	temp=head;

	for(iMarker=1;iMarker<iPos-1;iMarker++) {
		temp=temp->next;
	}

	temp1=Create(iVal);
	temp1->next=temp->next;
	temp->next=temp1;

	if(temp1->next==NULL) {
		last=temp1;
	}
	Disp();
}


//insert last function definition
void SinglyLLL::Insert_Last(int iVal) {

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
void SinglyLLL::Delete_First() {
	PNODE1 temp=NULL;

	if(head==NULL) {
		cout<<"Linked list empty"<<endl;
		return;
	}

	temp=head->next;

	if(temp->next==NULL) {
		last=temp->next;
	}

	delete head;
	head=temp;
	Disp();
}


//delete node at given position
void SinglyLLL::Delete_Position(int iPos) {
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

	PNODE1 temp=NULL,temp1=NULL;
	int iMarker=0;

	for(iMarker=1,temp=head;iMarker<iPos-1;iMarker++) {
		temp=temp->next;
	}

	temp1=temp->next;
	temp->next=temp1->next;
	delete temp1;

	if(temp->next==NULL) {
		last=temp;
	}
	Disp();
}


//delete node by value function definition
void SinglyLLL::Delete_By_Value(int iVal) {

	PNODE1 temp=NULL,temp1=NULL;

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

		else {
			return;
		}
	}

	for(temp=head,temp1=temp->next;temp->next!=NULL;temp=temp->next,temp1=temp1->next) {

		if(temp->iData==iVal) {

			if(temp1->next==NULL) {
				last=temp1;
			}

			head=temp1;
			delete temp;
		}
	}
	Disp();
}


//delete last node function definition
void SinglyLLL::Delete_Last() {

	if(head==NULL) {
		return;
	}

	PNODE1 temp=head,temp1=NULL;

	while(temp->next->next!=NULL) {
		temp=temp->next;
	}

	temp1=temp->next;
	temp->next=temp1->next;
	last=temp;

	delete temp1;
	Disp();
}


//search node by its position function definition
int SinglyLLL::Search_By_Position(int iPos) {

	PNODE1 temp=NULL;
	int iMarker=0;
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
int SinglyLLL::Search_By_Value(int iVal) {

	PNODE1 temp=NULL;
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
void SinglyLLL::Disp() {

	PNODE1 temp=NULL;
	temp=head;

	while(temp!=NULL) {
		cout<<temp->iData<<" -> ";
		temp=temp->next;
	}

	cout<<endl;
}


//Calculates length of linked list function definition
int SinglyLLL::Length() {
	cout<<endl;

	int iLen=0;
	PNODE1 temp=NULL;

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