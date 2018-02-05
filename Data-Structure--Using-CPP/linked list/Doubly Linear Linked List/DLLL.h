//header files inclusion
#include<iostream>
using namespace std;

//node structure using typedef
typedef struct node2{
	struct node2* prev;
	int iData;
	struct node2* next;
}NODE2,*PNODE2;

//start of function prototypes
class DoublyLLL{
	private:
		PNODE2 head;
		PNODE2 last;
	public:
		DoublyLLL();									//constructor
		~DoublyLLL();								//destructor
		PNODE2 Create(int);							//Parameters: (int)
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