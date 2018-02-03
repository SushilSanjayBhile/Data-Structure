#include "SCLLF.cpp"

//main funcion definition
int main() {
	int iValue=0,iCheck_Available=0,iLength=0;

	SinglyCLL *obj1 = new SinglyCLL;

	cout<<endl<<"1 Inserted at Last position:"<<endl;
	obj1->Insert_Last(1);

	cout<<endl<<"2 Inserted at Last position:"<<endl;
	obj1->Insert_Last(2);

	cout<<endl<<"3 Inserted at Last position:"<<endl;
	obj1->Insert_Last(3);

	cout<<endl<<"0 Inserted at first position"<<endl;
	obj1->Insert_First(0);

	iLength=obj1->Length();
	cout<<"Length of Linked list is "<<iLength<<endl;

	cout<<endl<<"4 is inserted at position 3:";
	obj1->Insert_Position(3,4);

	cout<<endl<<"5 is inserted at last position"<<endl;
	obj1->Insert_Last(5);

	iLength=obj1->Length();
	cout<<"Length of Linked list is "<<iLength<<endl;

	cout<<endl<<"Delete first node:"<<endl;
	obj1->Delete_First();

	cout<<endl<<"Again Delete first node:"<<endl;
	obj1->Delete_First();

	cout<<endl<<"Delete node at position 2:"<<endl;
	obj1->Delete_Position(2);

	cout<<endl<<"Delete node by value 4:"<<endl;
	obj1->Delete_By_Value(4);

	cout<<endl<<"Insert 6 at last position:"<<endl;
	obj1->Insert_Last(6);

	iLength=obj1->Length();
	cout<<"Length of Linked list is "<<iLength<<endl;

	cout<<endl<<"Insert 7 at last position:"<<endl;
	obj1->Insert_Last(7);

	cout<<endl<<"Delete last node of linked list:"<<endl;
	obj1->Delete_Last();

	cout<<endl<<"value present on position: 2"<<endl;
	iCheck_Available=obj1->Search_By_Position(2);

	cout<<endl<<"value present on position: -1"<<endl;
	iCheck_Available=obj1->Search_By_Position(-1);

	cout<<endl<<"Check if value available: 6"<<endl;
	iCheck_Available=obj1->Search_By_Value(6);
	
	cout<<endl<<"Check if value available: -2"<<endl;
	iCheck_Available=obj1->Search_By_Value(-2);

	iLength=obj1->Length();
	cout<<"Length of Linked list is "<<iLength<<endl;

	delete obj1;

	return 0;
}
