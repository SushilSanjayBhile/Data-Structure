//We've decalred head and tail of queue GLOBALLY, so there's no need to re-assign updated queue address to
//previous queue address

#include<stdio.h>
#include<stdlib.h>


//node structure
typedef struct node {
	int iData;
	struct node *next;
}NODE;



//start of function prototypes
void Disp();				//parameters: (head)
void Enqueue(int);				//parameters: (head, data)
void Dequeue();				//parameters: (head)
NODE* Create(int);				//parameters: (data)


NODE *head=NULL,*tail=NULL;


//main function definition
int main() {

//hard-coded approach
	Dequeue();
	Enqueue(1);
	Enqueue(2);
	Dequeue();
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	Dequeue();
	Dequeue();
	Dequeue();
	Dequeue();

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
void Enqueue(int iVal) {

	printf("\nEnqueue %d\n",iVal);

	NODE *temp=NULL;
	temp=Create(iVal);

	if(head==NULL) {
		head=tail=temp;
	}
	else {
		tail->next=temp;
		tail=temp;
	}

	Disp(head);
}



//Pop function definition
void Dequeue() {

	printf("\nDequeue: \n");

	NODE *temp=NULL;

	if(head==NULL) {
		printf("\nEmpty queue\n");
	}

	else if(head->next==NULL) {
		free(head);
		head=tail=NULL;
	}

	else {
		temp=head;
		head=head->next;
		free(temp);
	}

	Disp(head);
}

//display function definition
void Disp(NODE *head) {

	if(head==NULL) {
		printf("\n\tEmpty Queue\n");
		return;
	}

	NODE *temp=NULL;
	temp=head;

	printf("\nHEAD -> ");
	do {
		printf("%d -> ",temp->iData);
		temp=temp->next;
	}while(temp!=NULL);

	printf("Tail\n");
}
