#include "BSTF.cpp"

//main function definition
int main(){

    BST* obj = new BST;

    obj->Insert(50);
    obj->Insert(30);
    obj->Insert(90);
    obj->Insert(10);
    obj->Insert(40);
    obj->Insert(35);
    obj->Insert(70);
    obj->Insert(100);
    obj->Insert(100);

    obj->PreOrder();
    obj->PostOrder();

    return 0;
}