//in this program we've decalred stack_top GLOBALLY. And because of this we do not have
//to return address of updated stack_top and assign it to old stack_top.

#include<stdio.h>
#include<stdlib.h>


//node structure
typedef struct node {
	int iData;
	struct node *next;
}NODE;


//start of function prototypes
void Disp();				//parameters: (head)
void Push(int);				//parameters: (head, data)
void Pop();				//parameters: (head)
NODE* Create(int);			//parameters: (data)


//head node global declaration
NODE *stack_top=NULL;


//main function definition
int main() {

//hard-coded approach
	Pop();
	Push(1);
	Push(2);
	Pop();
	Push(3);
	Push(4);
	Push(5);
	Pop();
	Pop();
	Pop();
	Pop();

	return 0;
}



//Create node function definition
NODE* Create(int iValue) {
	NODE* temp=NULL;

	temp=(NODE*) malloc (sizeof(NODE*));
	temp->iData=iValue;
	temp->next=NULL;

	return temp;
}



//Push function definition
void Push(int iValue) {
	NODE* temp=NULL;

	temp=Create(iValue);

	temp->next=stack_top;
	stack_top=temp;

	printf("\nPush %d: ",iValue);
	Disp(stack_top);

}



//Pop function definition
void Pop() {

	printf("\nPop: ");

	if(stack_top==NULL) {
		printf("\n\tEmpty List\n");
		return;
	}


	NODE *temp=NULL;
	temp=stack_top;

	if(stack_top->next==NULL) {
		stack_top=NULL;
	}

	else {
		stack_top=stack_top->next;
	}

	free(temp);
	Disp(stack_top);
}


//display function definition
void Disp(NODE *stack_top) {

	if(stack_top==NULL) {
		printf("\n\tEmpty Stack\n");
		return;
	}

	NODE *temp=NULL;

	temp=stack_top;

	printf("\n\tSTACK TOP\n");
	do {
		printf("\t%d\n",temp->iData);
		temp=temp->next;
	}while(temp!=NULL);

}
