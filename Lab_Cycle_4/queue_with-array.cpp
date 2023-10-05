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
            return this->currentSize;
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
        int dequeue(){
            if(this->currentSize == 0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            else{
                int data = this->arr[this->front];  
                this->front = (this->front+1)%Capacity;
                this->currentSize--;
                return data;
            }
        }
};
int main(){
    
}