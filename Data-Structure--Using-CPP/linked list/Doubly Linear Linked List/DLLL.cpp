#include "DLLLF.cpp"

//main funcion definition
int main() {
	int iValue=0,iCheck_Available=0,iLength=0;

	DoublyLLL* obj = new DoublyLLL;

	cout<<endl<<"1 Inserted at Last position:"<<endl;
	obj->InsertLast(1);

	cout<<endl<<"2 Inserted at Last position:"<<endl;
	obj->InsertLast(2);

	cout<<endl<<"3 Inserted at Last position:"<<endl;
	obj->InsertLast(3);

	cout<<endl<<"0 Inserted at first position"<<endl;
	obj->InsertFirst(0);

	iLength=obj->Length();
	cout<<endl<<"Length of Linked list is "<<iLength<<endl;

	cout<<endl<<"4 is inserted at position 3:"<<endl;
	obj->InsertPosition(3,4);

	cout<<endl<<"5 is inserted at last position"<<endl;
	obj->InsertLast(5);
    
    cout<<endl<<"printing liked list in reverse order"<<endl;
    obj->DispRev();

	iLength=obj->Length();
	cout<<endl<<"Length of Linked list is "<<iLength<<endl;

	cout<<endl<<"Delete first node:"<<endl;
	obj->DeleteFirst();

	cout<<endl<<"Again Delete first node:"<<endl;
	obj->DeleteFirst();

	cout<<endl<<"Delete node at position 2:"<<endl;
	obj->DeletePosition(2);

	cout<<endl<<"Delete node by value 4:"<<endl;
	obj->DeleteByValue(4);

	cout<<endl<<"Insert 6 at last position:"<<endl;
	obj->InsertLast(6);

	iLength=obj->Length();
	cout<<endl<<"Length of Linked list is "<<iLength<<endl;

	cout<<endl<<"Insert 7 at last position:"<<endl;
	obj->InsertLast(7);

	cout<<endl<<"Delete last node of linked list:"<<endl;
	obj->DeleteLast();

	cout<<endl<<"value present on position: 2"<<endl;
	iCheck_Available=obj->SearchByPosition(2);

	cout<<endl<<"value present on position: -1"<<endl;
	iCheck_Available=obj->SearchByPosition(-1);

	cout<<endl<<"Check if value available: 6"<<endl;
	iCheck_Available=obj->SearchByValue(6);
	
	cout<<endl<<"Check if value available: -2"<<endl;
	iCheck_Available=obj->SearchByValue(-2);

	iLength=obj->Length();
	cout<<endl<<"Length of Linked list is "<<iLength<<endl;

	return 0;
}