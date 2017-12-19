//As stack_top is local, Every time we've to return updated stack_top address and assign it to old stack_top address.

#include<stdio.h>
#include<stdlib.h>


//node structure
typedef struct node {
	int iData;
	struct node *next;
}NODE;



//start of function prototypes
void Disp(NODE*);				   //parameters: (stack_top)
NODE* Push(NODE *,int);		//parameters: (stack_top, data)
NODE* Pop(NODE *);				//parameters: (stack_top)
NODE* Create(int);				//parameters: (data)


//main function definition
int main() {
	NODE *stack_top=NULL;

//hard-coded approach
	stack_top=Pop(stack_top);
	stack_top=Push(stack_top,1);
	stack_top=Push(stack_top,2);
	stack_top=Pop(stack_top);
	stack_top=Push(stack_top,3);
	stack_top=Push(stack_top,4);
	stack_top=Push(stack_top,5);
	stack_top=Pop(stack_top);
	stack_top=Pop(stack_top);
	stack_top=Pop(stack_top);
	stack_top=Pop(stack_top);

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
NODE* Push(NODE* stack_top, int iValue) {
	NODE* temp=NULL;

	temp=Create(iValue);

	temp->next=stack_top;
	stack_top=temp;

	printf("\nPush %d: ",iValue);
	Disp(stack_top);

	return stack_top;
}



//Pop function definition
NODE* Pop(NODE *stack_top) {

	printf("\nPop: ");

	if(stack_top==NULL) {
		printf("\n\tEmpty List\n");
		return stack_top;
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

		return stack_top;
}


//display function definition
void Disp(NODE *stack_top) {

	if(stack_top==NULL) {
		printf("\n\tEmpty Stack\n");
		return;
	}

	NODE *temp=NULL;

	temp=stack_top;

	printf("\n\tstack_top\n");
	do {
		printf("\t%d\n",temp->iData);
		temp=temp->next;
	}while(temp!=NULL);

}
