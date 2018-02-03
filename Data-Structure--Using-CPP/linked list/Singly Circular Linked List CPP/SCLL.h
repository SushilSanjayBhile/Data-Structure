//header files inclusion
#include<iostream>
using namespace std;

//node structure
typedef struct node1{
	int iData;
	struct node1* next;
}NODE1,*PNODE1;

//start of function prototypes
class SinglyCLL{
	private:
		PNODE1 head;
		PNODE1 last;
	public:
		SinglyCLL();									//constructor
		~SinglyCLL();									//Destructor
		PNODE1 Create(int);								//created a single node
		void Insert_First(int);							//insert at first position
		void Insert_Position(int,int);					//inserts at givn position
		void Insert_Last(int);							//inserts at last position
		void Delete_First();							//deletes node present at first node
		void Delete_Position(int);						//deletes node at given position
		void Delete_By_Value(int);						//deletes node by given value
		void Delete_Last();								//deletes last node
		int Search_By_Position(int);					//searches node y position
		int Search_By_Value(int);						//searches node by value
		int Length();									//gives length of linked list
		void Disp();									//diplays linked list
};
//end of function prototypes