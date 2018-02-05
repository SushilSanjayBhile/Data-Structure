//header files inclusion
#include<iostream>
using namespace std;

//node structure using typedef
typedef struct node {
	struct node* prev;
	int iData;
	struct node* next;
}NODE,*PNODE;

//start of function prototypes

class DoublyCLL{
	private:
		PNODE head;
		PNODE last;
	public:
		DoublyCLL();									//constructor
		~DoublyCLL();								//destructor
		PNODE Create(int);							//Parameters: (int)
		void InsertFirst(int);						//parameters: (head,value)
		void InsertPosition(int,int);				//parameters: (head,position,value)
		void InsertLast(int);						//parameters: (head,value)
		void DeleteFirst();							//parameters: (head)
		void DeletePosition(int);					//parameters: (head,position)
		void DeleteByValue(int);					//parametets: (head,value)
		void DeleteLast();							//parameters: (head)
		int SearchByPosition(int);					//parameters: (head,position)
		int SearchByValue(int);						//parameters: (head,value)
		int Length();								//parameters: (head)
		void Disp();								//parameters: (head)
		void DispRev();
};
//end of function prototypes