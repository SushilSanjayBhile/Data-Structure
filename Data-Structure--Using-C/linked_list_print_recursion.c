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
	
    printf("Linked List printing using RECURSION:- \n\n");
    Disp(head);

    printf("\n");

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

    if(head==NULL) return;

    printf("%d -> ",head->iData);   //printing before recursive call leads to print in forword order

    Disp(head->next);    
}
