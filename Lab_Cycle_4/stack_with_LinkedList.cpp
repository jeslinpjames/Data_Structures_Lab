#include<iostream>
using namespace std;
class Node{
    public:
        Node *next; 
        int data;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
class Stack{
    private:
        Node *top;
        int size;
    public:
        Stack(){
            this->top = NULL;
            this->size = 0;
        }
        void push(int data){
            Node *newNode = new Node(data);
            if(this->top == NULL){
                this->top = newNode;
            }
            else{
                newNode->next = this->top;
                this->top = newNode;
            }
            size++;
        }
        int pop(){
            if(this->top == NULL){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else{
                int data = this->top->data;
                this->top = this->top->next;
                size--;
                return data;
            }
        }
        bool isEmpty(){
            if(this->top == NULL){
                return true;
            }
            else{
                return false;
            }
        }
        int getSize(){
            return this->size;
        }
};
int main(){
    Stack *stack = new Stack();
    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->push(40);
    cout<<"Size of stack is "<<stack->getSize()<<endl;
    cout<<"Popped element is "<<stack->pop()<<endl;
    cout<<"Popped element is "<<stack->pop()<<endl;
    cout<<"Popped element is "<<stack->pop()<<endl;
    return 0;
}
