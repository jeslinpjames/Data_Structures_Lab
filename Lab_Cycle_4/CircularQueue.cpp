// Implement a circular queue using array with the following operations : ENQUEUE,
// DEQUEUE, ISEMPTY, SIZE()
#include<iostream>
using namespace std;   
class CircularQueue{
    private:
        int *arr;
        int front;
        int rear;
        int Capacity;
        int currentSize;
    public:
        CircularQueue(int Capacity){
            this->Capacity = Capacity;
            this->arr = new int[Capacity];
            this->front = 0;
            this->rear = -1;
            this->currentSize = 0;
        }
        ~CircularQueue(){
            delete[] arr;
        }
        bool isEmpty(){
            return currentSize == 0;
        }
        int getSize(){
            return currentSize;
        }
        void enqueue(int data){
            if(currentSize== Capacity){
                cout<<"Queue is full"<<endl;
                return;
            }
            else if (isEmpty()){
                rear = front = 0;
            }
            else{
                rear = (rear+1)%Capacity;
            }
            arr[rear] = data;
            currentSize++;
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int data = arr[front];
            if(front==rear){
                front = rear = -1;
            }
            else{
                front = (front+1)%Capacity;
            }
            currentSize--;
            return data;
        }
};
int main(){
    CircularQueue queue (5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    cout << "Size of queue is " << queue.getSize() << endl;

    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;

    cout << "Size of queue is " << queue.getSize() << endl;

    queue.enqueue(60);
    queue.enqueue(70);

    cout << "Size of queue is " << queue.getSize() << endl;

    while (!queue.isEmpty()) {
        cout << "Dequeue: " << queue.dequeue() << endl;
    }

    cout << "Size of queue is " << queue.getSize() << endl;

    return 0;
}

// Size of queue is 5
// Dequeue: 10
// Dequeue: 20
// Size of queue is 3
// Size of queue is 5
// Dequeue: 30
// Dequeue: 40
// Dequeue: 50
// Dequeue: 60
// Dequeue: 70
// Size of queue is 0