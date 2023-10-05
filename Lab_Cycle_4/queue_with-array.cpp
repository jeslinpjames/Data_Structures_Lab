// Implement a queue using array with the following operations : ENQUEUE, DEQUEUE,
// ISEMPTY, SIZE()
#include<iostream>
using namespace std;
class Queue{
    private:
        int *arr;
        int front;
        int rear;
        int Capacity;
        int currentSize;
    public:
        Queue(int Capacity){
            this->Capacity = Capacity;
            this->arr = new int[Capacity];
            this->front = 0;
            this->rear = -1;
            this->currentSize = 0;
        }
        ~Queue(){
            delete[] arr;
        }
        bool isEmpty(){
            if(this->currentSize == 0){
                return true;
            }
            else{
                return false;
            }
        }
        int getSize(){
            return this->currentSize+1;
        }
        void enqueue(int data){
            if (this->currentSize==Capacity){
                cout<<"Queue is full"<<endl;
            }
            else{
                this->rear = (this->rear+1)%Capacity;
                this->arr[this->rear] = data;
                this->currentSize++;
            }
        }
        
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int data = arr[front];
        front = (front + 1) % Capacity;
        currentSize--;

        if (isEmpty()) {
            front = 0;
            rear = -1;
        }

        return data;
    }
};
int main(){
    Queue *queue = new Queue(5);
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->enqueue(40);
    queue->enqueue(50);
    queue->enqueue(60);
    cout<<"Size of queue is "<<queue->getSize()<<endl;
    cout<<queue->dequeue()<<endl;
    cout<<queue->dequeue()<<endl;
    cout<<queue->dequeue()<<endl;
    cout<<queue->dequeue()<<endl;
    cout<<queue->dequeue()<<endl;
    if(queue->isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    return 0;
}


// Queue is full
// Size of queue is 6
// 10
// 20
// 30
// 40
// 50
// Queue is empty