#include<iostream>
using namespace std;
class Node{
    public :
        int data;
        static int key;
        Node* next;
        Node() : data(0), next(nullptr) {}
        Node(int Data) : data(Data), next(nullptr) {
            key++;  
        }
        Node(int Data, Node* Next) : data(Data), next(Next) {
            key++;
        }
};
int Node::key=0;
class LinkedList{
    public :
        Node* Head;
        Node* Tail;
        int size;
        LinkedList():size(0),Head(nullptr),Tail(nullptr){}
        void insertFirst(int val);
        void insertLast(int val);
        void insert_pos(int val,int k);
        void display();
};
void LinkedList :: insertFirst(int val){
    Node* node = new Node(val);
    node->next=Head;
    Head= node;
    if(Tail==nullptr){
        Tail= Head;
    }
    size++;
}
void LinkedList::insertLast(int val){
    if (Tail==nullptr){
        insertFirst(val);
        return;
    }
    Node* node = new Node(val);
    Tail->next=node;
    Tail= node;
    size++;
}
void LinkedList:: insert_pos(int val, int k){
    if(k==0){
        insertFirst(val);
        return;
    }
    if(k==size){
        insertLast(val);
        return;
    }
    if(k>size){
        cout<<"LIST TOO SMALL"<<endl;
        return;
    }
    Node* temp = Head;
    for(int i=1;i<k;i++){
        temp=temp->next;
    }
    Node* node = new Node(val,temp->next);
    temp->next=node;
    size++;
}
void LinkedList::display(){
    Node* temp = Head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp= temp->next;
    }    
    cout<<" END"<<endl;
}
class Alternative{
    private:
        LinkedList oddList;
        LinkedList evenList;
    public: 
        Alternative(LinkedList Lst);
        void displayLists(); 
};
Alternative::Alternative(LinkedList Lst){ 
    Node* current = Lst.Head;
    int count=0;
    while(current!=nullptr){
        if(count%2==0){
            evenList.insertLast(current->data);
        }else{
            oddList.insertLast(current->data);
        }
        current=current->next;
        count++;
    }
}
void Alternative::displayLists(){
    cout<<"The Even List is :";
    evenList.display();
    cout<<"The Odd List is :";
    oddList.display();
}
int main(){
    cout<<"Enter the number of Elements in the Linked List : ";
    int n=0;
    cin>> n;
    cout<<"Enter the Elements of the List seperated by space : ";
    int val;
    LinkedList Lst;
    for(int i=0;i<n;i++){
        cin>>val;
        Lst.insertLast(val);
    }
    Alternative Alt(Lst);    
    Alt.displayLists();    
    return 0;
}