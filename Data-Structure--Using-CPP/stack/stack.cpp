#include "StackFunc.cpp"

int main(){

    Stack *obj = new Stack();

    obj->push(0);
    obj->push(1);
    obj->pop();
    obj->pop();
    obj->pop();
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->pop();
    obj->push(5);
    obj->push(6);
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();

    delete obj;
    return 0;
}