#define TEMPLATE_H
template <class T>

class queue
{
    T *arr;         // array to store queue elements
    int capacity = 10;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue
 
public:
    queue(int size = 10);
    void pop();
    void push(T);
    T peek();
    int size();
    bool isEmpty();
    bool isFull();
};
