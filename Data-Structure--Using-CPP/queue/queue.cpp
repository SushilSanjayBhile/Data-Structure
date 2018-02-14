#include "queueFunc.cpp"

int main(){
    Queue *obj = new Queue();

    obj->enqueue(0);
    obj->enqueue(1);
    obj->dequeue();
    obj->dequeue();
    obj->dequeue();
    obj->enqueue(2);
    obj->enqueue(3);
    obj->enqueue(4);
    obj->dequeue();
    obj->enqueue(5);
    obj->enqueue(6);
    obj->dequeue();
    obj->dequeue();
    obj->dequeue();
    obj->dequeue();

    return 0;
}