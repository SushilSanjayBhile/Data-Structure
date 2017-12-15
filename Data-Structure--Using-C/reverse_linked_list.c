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
	NODE Create(int);					//creates node
	NODE Insert_Last(NODE,int);			//parameters: (head,value)
	void Disp(NODE);					//parameters: (head)
    void Reverse(NODE);                 //parameters: (head)
//end of function prototypes



//main funcion definition
int main() {

	NODE head=NULL;
	int iValue=0,iCheck_Available=0,iLength=0;

//hard coded approach

	head=Insert_Last(head,1);
	head=Insert_Last(head,2);
	head=Insert_Last(head,3);
	head=Insert_Last(head,4);
	head=Insert_Last(head,5);
	head=Insert_Last(head,6);
	head=Insert_Last(head,7);
	head=Insert_Last(head,8);
	head=Insert_Last(head,9);
	head=Insert_Last(head,10);
	
    printf("I am printing addresses with data,\nBecause I just want to show that I've not swapped data of linked list,\nI've reversed all nodes of linked list\n\n");

    printf("Linked List:- \n");
    Disp(head);

    printf("\nReversed linked list:-\n");
    Reverse(head);

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

	return head;
}


//Disp function definition
void Disp(NODE head) {

	NODE temp=NULL;

	temp=head;

	while(temp!=NULL) {
		printf("%d -> ",temp->iData);
		temp=temp->next;
	}
    
    temp=head;

    printf("\n");

	while(temp!=NULL) {
		printf("%p -> ",temp);
		temp=temp->next;
	}

	printf("\n");
}


void Reverse(NODE head){
   NODE temp1=NULL, temp2=NULL;

    if(head->next==NULL){
        Disp(head);
        return;
    }

    while(head!=NULL){
        temp1=temp2;
        temp2=head;
        head=head->next;
        temp2->next=temp1;
    }
    head=temp2;

    Disp(head);
    return;
}
