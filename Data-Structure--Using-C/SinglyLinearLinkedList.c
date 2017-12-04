//header files inclusion
#include<stdio.h>
#include<stdlib.h>

//node structure using typedef
typedef struct node {
	int iData;
	struct node* next;
	}*NODE;


NODE last=NULL;

//start of function prototypes

	NODE Create(int);					//only for programmer, creates node	//parameters: (only value)
	NODE Insert_First(NODE,int);				//parameters: (head,value)
	NODE Insert_Position(NODE,int,int);			//parameters: (head,position,value)
	NODE Insert_Last(NODE,int);				//parameters: (head,value)
	NODE Delete_First(NODE);				//parameters: (head)
	NODE Delete_Position(NODE,int);				//parameters: (head,position)
	NODE Delete_By_Value(NODE,int);				//parametets: (head,value)
	NODE Delete_Last(NODE);					//parameters: (head)
	int Search_By_Position(NODE,int);			//parameters: (head,position)
	int Search_By_Value(NODE,int);				//parameters: (head,value)
	void Disp(NODE);					//parameters: (head)
	int Length(NODE);					//returns length of linked list
//end of function prototypes

//main funcion definition
int main() {

	NODE head=NULL;


	int iValue=0,iCheck_Available=0,iLength=0;

//hard coded approach

	printf("\n1 Inserted at Last position:\n");
	head=Insert_Last(head,1);

	printf("\n2 Inserted at Last position:\n");
	head=Insert_Last(head,2);

	printf("\n3 Inserted at Last position:\n");
	head=Insert_Last(head,3);

	printf("\n0 Inserted at first position\n");
	head=Insert_First(head,0);

	printf("\n4 is inserted at position 3:\n");
	head=Insert_Position(head,3,4);				//Parameters: (head,position,value)

	printf("\n5 is inserted at last position\n");
	head=Insert_Last(head,5);

	printf("\nDelete first node:\n");
	head=Delete_First(head);

	printf("\nAgain Delete first node:\n");
	head=Delete_First(head);

	printf("\nDelete node at position 2:\n");
	head=Delete_Position(head,2);

	printf("\nDelete node by value 4:\n");
	head=Delete_By_Value(head,4);

	printf("\nInsert 6 at last position:\n");
	head=Insert_Last(head,6);

	printf("\nInsert 7 at last position:\n");
	head=Insert_Last(head,7);

	printf("\nDelete last node of linked list:\n");
	head=Delete_Last(head);

	printf("\nvalue present on position: 2\n");
	iCheck_Available=Search_By_Position(head,2);

	printf("\nvalue present on position: -1\n");
	iCheck_Available=Search_By_Position(head,-1);

	printf("\nCheck if value available: 6\n");
	iCheck_Available=Search_By_Value(head,6);
	
	printf("\nCheck if value available: -2\n");
	iCheck_Available=Search_By_Value(head,-2);

	return 0;
}


//create node function definition
NODE Create(int iVal) {
	NODE nn=NULL;

	nn=(NODE)malloc(sizeof(NODE));
	nn->iData=iVal;
	nn->next=NULL;

	return nn;
}


//insert_first function definition
NODE Insert_First(NODE head, int iVal) {

	NODE temp=NULL;

	temp=Create(iVal);

	if(head==NULL) {
		head=last=temp;
	}

	else{
		temp->next=head;
		head=temp;
	}

	Disp(head);

	return head;
}



//insert at given position function definition
NODE Insert_Position(NODE head,int iPos,int iVal) {
	
	int iMarker=0;

	if(iPos<0) {
		printf("Position is Invalid\n");
		return head;
	}

//we can check length when flow enters in function but if position is negative then iterations to calculate length will all become waste
	int iLength=0;

	iLength=Length(head);

	if(iLength==0) {
		printf("\nEmapty List");
		return head;
	}

//else is not necessary here as above 'if' condition is true, then return will execute
	if(iPos>(iLength+1)) {
		printf("Invalid position\n");
		return head;
	}

//we can allocate temp,temp1 when flow comes in function, but if position is invalid memory initialization will become waste
	NODE temp=NULL,temp1=NULL;

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

	Disp(head);

	return head;
}


//insert last function definition
NODE Insert_Last(NODE head,int iVal) {

	NODE temp=NULL;

	temp=Create(iVal);

	if(head==NULL) {
		head=temp;
	}
	else {
		temp->next=last->next;
		last->next=temp;
	}

	last=temp;

	Disp(head);

	return head;
}


//delete first node function definition
NODE Delete_First(NODE head) {
	NODE temp=NULL;

	if(head==NULL) {
		printf("Linked list empty\n");
		return head;
	}

	temp=head->next;

	if(temp->next==NULL) {
		last=temp->next;
	}

	free(head);

	head=temp;

	Disp(head);

	return head;
}


//delete node at given position
NODE Delete_Position(NODE head,int iPos) {

	if(iPos<0) {
		printf("Position is Invalid\n");
		return head;
	}

//we can check length when flow enters in function but if position is negative then iterations to calculate length will all become waste
	int iLength=0;

	iLength=Length(head);

	if(iLength==0) {
		printf("\nEmapty List");
		return head;
	}

//else is not necessary here as above 'if' condition is true, then return will execute
	if(iPos>iLength) {
		printf("Invalid position\n");
		return head;
	}

	NODE temp=NULL,temp1=NULL;
	int iMarker=0;

	for(iMarker=1,temp=head;iMarker<iPos-1;iMarker++) {
		temp=temp->next;
	}

	temp1=temp->next;

	temp->next=temp1->next;

	free(temp1);

	if(temp->next==NULL) {
		last=temp;
	}

	Disp(head);

	return head;
}


//delete node by value function definition
NODE Delete_By_Value(NODE head,int iVal) {

	NODE temp=NULL,temp1=NULL;

	if(head==NULL) {
		printf("\nEmpty linked list\n");
		return head;
	}

	else if(head->next==NULL) {

		if(head->iData==iVal) {
			free(head);
			head=NULL;
			return head;
		}

		else {
			return head;
		}
	}

	for(temp=head,temp1=temp->next;temp->next!=NULL;temp=temp->next,temp1=temp1->next) {

		if(temp->iData==iVal) {

			if(temp1->next==NULL) {
				last=temp1;
			}

			head=temp1;
			free(temp);

		}

	Disp(head);

	return head;

	}
}


//delete last node function definition
NODE Delete_Last(NODE head) {

	if(head==NULL) {
		return head;
	}

	NODE temp=head,temp1=NULL;

	while(temp->next->next!=NULL) {
		temp=temp->next;
	}

	temp1=temp->next;
	temp->next=temp1->next;
	last=temp;

	free(temp1);

	Disp(head);

	return head;
}


//search node by its position function definition
int Search_By_Position(NODE head,int iPos) {

	NODE temp=NULL;
	int iMarker=0;

	temp=head;

	for(iMarker=1;(temp!=NULL)&&(iMarker!=iPos);temp=temp->next,iMarker++);

	if(iMarker!=iPos) {
		printf("Invalid position\n");
		return 0;
	}

	else {
		printf("%d\n",temp->iData);
		return 0;
	}

}


//search node by its value fucntion defiition
int Search_By_Value(NODE head,int iVal) {

	NODE temp=NULL;
	int iMarker=0;

	temp=head;

	for(iMarker=0;temp!=NULL;iMarker++,temp=temp->next) {
		if(temp->iData==iVal) {
			printf("Present\n");
			return 0;
		}

	}

	printf("Not Present\n");

	return 0;

}


//Disp function definition
void Disp(NODE head) {

	NODE temp=NULL;

	temp=head;

	while(temp!=NULL) {
		printf("%d -> ",temp->iData);
		temp=temp->next;
	}

	printf("\n");
}




//Calculates length of linked list function definition
int Length(NODE head) {

	printf("\n");

	int iLen=0;
	NODE temp=NULL;

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
