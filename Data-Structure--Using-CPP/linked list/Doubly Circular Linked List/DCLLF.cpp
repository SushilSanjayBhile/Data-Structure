#include "DCLL.h"

//constructor of Singly Linked List Class
DoublyCLL::DoublyCLL(){
	head  =  NULL;
	last  =  NULL;
}


//constructor of Singly Linked List Class
DoublyCLL::~DoublyCLL(){
	delete head;
	delete last;
}


//create node function definition
PNODE DoublyCLL::Create(int iVal) {
	PNODE nn  =  NULL;
	nn  =  new NODE;

	nn->prev  =  nn;
	nn->iData  =  iVal;
	nn->next  =  nn;

	return nn;
}


//insert_first function definition
void DoublyCLL::InsertFirst(int iVal) {
	PNODE temp  =  NULL;
	temp  =  Create(iVal);

	if(head  ==   NULL) {
		head  =  last  =  temp;
	}
	else{
		temp->next  =  head;
		head->prev  =  temp;
		head = temp; 
	}

    head->prev  =  last;
    last->next  =  head;
	Disp();
}



//insert at given position function definition
void DoublyCLL::InsertPosition(int iPos,int iVal) {
	int iMarker  =  0;

	if(iPos<0) {
		cout<<"Position is Invalid"<<endl;
		return;
	}

	//we can check length when flow enters in function but if position is negative then iterations to calculate length will all become waste
	int iLength  =  0;
	iLength  =  Length();

	if(iLength == 0) {
		cout<<endl<<"Emapty List";
		return;
	}

	//else is not necessary here as above 'if' condition is true, then return will execute
	if(iPos>(iLength+1)) {
		cout<<"Invalid position"<<endl;
		return;
	}

	//we can allocate temp,temp1 when flow comes in function, but if position is invalid memory initialization will become waste
	PNODE temp = NULL,nn = NULL;
	temp = head;

	if(iPos ==  1){
		InsertFirst(iVal);
	}
	else if(iPos ==  iLength+1){
		InsertLast(iVal); 
	}
	else{
		nn = Create(iVal);

		for(iMarker  =  1;iMarker<iPos-1;iMarker++) {
			temp  =  temp->next;
		}

		nn->next  =  temp->next;
		temp->next = nn;
		nn->prev = temp;
		nn->next->prev = nn;

        head->prev = last;
        last->next = head;
	}
	Disp();
}


//insert last function definition
void DoublyCLL::InsertLast(int iVal) {
	PNODE nn = NULL;

	nn = Create(iVal);

	if(head == NULL) {
		head = nn;
	}
	else {
		nn->prev = last;
		last->next = nn;
	}

	last = nn;
	head->prev = last;
	last->next = head;

	Disp();
}


//delete first node function definition
void DoublyCLL::DeleteFirst() {
	PNODE temp = NULL;

	if(head == NULL) {
		cout<<"Linked list empty"<<endl;
		return;
	}
	else if(head->next ==  NULL) {
		delete head;
		head = last = NULL;
	}
	else{
		temp = head;
		head = head->next;
		delete temp;
		head->prev = NULL;
	}

    head->prev = last;
    last->next = head;

	Disp();
}


//delete node at given position
void DoublyCLL::DeletePosition(int iPos) {

	if(iPos<0) {
		cout<<"Invalid Position"<<endl;
		return;
	}

	//we can check length when flow enters in function but if position is negative then iterations to calculate length will all become waste
	int iLength = 0;
	iLength = Length();

	if(iLength ==  0) {
		cout<<endl<<"Empty List";
		return;
	}

	//else is not necessary here as above 'if' condition is true, then return will execute
	if(iPos>iLength) {
		cout<<"Invalid Position"<<endl;
		return;
	}

	if(iPos ==  1){
		DeleteFirst();
	}
	else if(iPos ==  iLength){
		DeleteLast();
	}
	else{
		PNODE temp = NULL;
		int iMarker = 0;

		for(iMarker = 1,temp = head;iMarker<iPos-1;iMarker++) {
			temp = temp->next;
		}

		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;

        head->prev = last;
        last->next = head;

	}	
	Disp();
}




//delete node by value function definition
void DoublyCLL::DeleteByValue(int iVal) {

	PNODE temp = NULL;

	if(head ==  NULL) {
		cout<<endl<<"Empty Linked List"<<endl;
		return;
	}

	else if(head->next ==  NULL) {
		if(head->iData ==  iVal) {
			delete head;
			head = NULL;
			return;
		}
	}

	else{
		for(temp = head;temp->next != NULL;temp = temp->next) {
			if(temp->iData == iVal) {
				if(temp->next == NULL) {
					DeleteLast();
					break;
				}
				else if(temp->prev == last){
					DeleteFirst();
					break;
				}
				else{
					temp = temp->prev;
					temp->next = temp->next->next;
					delete temp->next->prev;
					temp->next->prev = temp;
    
                    head->prev = last;    
                    last->next = head;

					Disp();

					break;
			    }
            }
		}
	}
}


//delete last node function definition
void DoublyCLL::DeleteLast() {
	PNODE temp = head;

	if(head ==  NULL) {
		return;
	}

	do{
		temp = temp->next;
	}while( temp->next != head);

	if(temp->prev ==  NULL){
		DeleteFirst();
	}
	else{
		temp = temp->prev;
		delete temp->next;
        last = temp;
	}

    head->prev = last;
    last->next = head;

	Disp();
}



//search node by its position function definition
int DoublyCLL::SearchByPosition(int iPos) {

	PNODE temp = NULL;
	int iMarker = 0;

	if((iPos > Length()) || (iPos < 0)){
		cout<<"Invalid Position"<<endl;
		return 0;
	}
	temp = head;

	for(iMarker = 1;(temp != NULL)&&(iMarker != iPos);temp = temp->next,iMarker++);

	if(iMarker != iPos) {
		cout<<"Invalid Position"<<endl;
		return 0;
	}

	else {
		cout<<temp->iData<<endl;
		return 0;
	}

}


//search node by its value fucntion defiition
int DoublyCLL::SearchByValue(int iVal) {
	PNODE temp = NULL;

	for(temp = head; temp->next != head; temp = temp->next) {
		if(temp->iData ==  iVal) {
			cout<<"Present"<<endl;
			return 0;
		}
	}

	cout<<"Not Present"<<endl;
	return 0;
}




//Disp function definition
void DoublyCLL::Disp() {
	PNODE temp = NULL;
	temp = head;

	do{
		cout<<temp->iData<<" -> ";
		temp = temp->next;
	}while(temp != head);
	cout<<endl;
	}


//Disp function definition
void DoublyCLL::DispRev() {
	PNODE temp = NULL;
	temp = last;

	do{
		cout<<temp->iData<<" -> ";
		temp = temp->prev;
	}while(temp != last);
	cout<<endl;
}


//Calculates length of linked list function definition
int DoublyCLL::Length() {
	cout<<endl;

	int iLen = 0;
	PNODE temp = NULL;
	temp = head;

	if(head ==  NULL) {
		return 0;
	}
	
    do{
		temp = temp->next;
		iLen++;
	}while(temp != head);
	
    return iLen;
}