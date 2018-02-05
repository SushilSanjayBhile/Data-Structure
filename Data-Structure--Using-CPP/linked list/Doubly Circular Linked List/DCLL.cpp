#include "DCLLF.cpp"

//main funcion definition
int main() {
	int iValue=0,iCheck_Available=0,iLength=0;

	DoublyCLL *obj1 = new DoublyCLL;

	cout<<endl<<"1 Inserted at Last position:"<<endl;
	obj1->InsertLast(1);

	cout<<endl<<"2 Inserted at Last position:"<<endl;
	obj1->InsertLast(2);

	cout<<endl<<"3 Inserted at Last position:"<<endl;
	obj1->InsertLast(3);

	cout<<endl<<"0 Inserted at first position"<<endl;
	obj1->InsertFirst(0);

	iLength=obj1->Length();
	cout<<"Length of Linked list is "<<iLength<<endl;

	cout<<endl<<"4 is inserted at position 3:";
	obj1->InsertPosition(3,4);

	cout<<endl<<"5 is inserted at last position"<<endl;
	obj1->InsertLast(5);
    
    cout<<endl<<"printing liked list in reverse order"<<endl;
    obj1->DispRev();

	iLength=obj1->Length();
	cout<<"Length of Linked list is "<<iLength<<endl;

	cout<<endl<<"Delete first node:"<<endl;
	obj1->DeleteFirst();

	cout<<endl<<"Again Delete first node:"<<endl;
	obj1->DeleteFirst();

	cout<<endl<<"Delete node at position 2:";
	obj1->DeletePosition(2);
    
	cout<<endl<<"Delete node by value 4:"<<endl;
	obj1->DeleteByValue(4);

	cout<<endl<<"Insert 6 at last position:"<<endl;
	obj1->InsertLast(6);

	iLength=obj1->Length();
	cout<<"Length of Linked list is "<<iLength<<endl;

	cout<<endl<<"Insert 7 at last position:"<<endl;
	obj1->InsertLast(7);

	cout<<endl<<"Delete last node of linked list:"<<endl;
	obj1->DeleteLast();

	cout<<endl<<"value present on position: 2";
	iCheck_Available=obj1->SearchByPosition(2);

	cout<<endl<<"value present on position: -1";
	iCheck_Available=obj1->SearchByPosition(-1);

	cout<<endl<<"Check if value available: 6"<<endl;
	iCheck_Available=obj1->SearchByValue(6);
	
	cout<<endl<<"Check if value available: -2"<<endl;
	iCheck_Available=obj1->SearchByValue(-2);

	iLength=obj1->Length();
	cout<<"Length of Linked list is "<<iLength<<endl;

	return 0;
}
