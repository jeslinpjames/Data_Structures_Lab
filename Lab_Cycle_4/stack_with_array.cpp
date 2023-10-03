// Implement a stack using array with the following operations : PUSH, POP, ISEMPTY,
// SIZE()
#include<iostream>
using namespace std;
class Stack{
    private:
        int* arr;
        int top;
        int capacity;
    public:
        Stack(int capacity){
            this->capacity = capacity;
            this->top = -1;
            this->arr = new int[capacity];
        }
        ~Stack(){
            delete[] arr;
        }
        void push(int data){
            if(top == capacity-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            arr[++top] = data;
        }
        bool isEmpty(){
            return top == -1;
        }
        int getSize(){
            return top+1;
        }
        int pop(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return arr[top--];
        }
        int peek(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return arr[top];
        }
};
int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.pop()<<endl;
    cout<<s.getSize()<<endl;
    if(s.isEmpty()==true)
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Stack is not empty"<<endl;
    return 0;
}





// 40
// 3
// Stack is not empty