//header files inclusion
#include<iostream>
using namespace std;

//node structure
typedef struct node1{
	int iData;
	struct node1* next;
}NODE1,*PNODE1;

//start of function prototypes
class SinglyLLL{
	private:
		PNODE1 head;
		PNODE1 last;
	public:
		SinglyLLL();										//constructor
		~SinglyLLL();										//Destructor
		PNODE1 Create(int);							//Parameters: (int)
		void Insert_First(int);						//parameters: (head,value)
		void Insert_Position(int,int);				//parameters: (head,position,value)
		void Insert_Last(int);						//parameters: (head,value)
		void Delete_First();						//parameters: (head)
		void Delete_Position(int);					//parameters: (head,position)
		void Delete_By_Value(int);					//parametets: (head,value)
		void Delete_Last();							//parameters: (head)
		int Search_By_Position(int);				//parameters: (head,position)
		int Search_By_Value(int);					//parameters: (head,value)
		int Length();								//parameters: (head)
		void Disp();								//parameters: (head)
};
//end of function prototypes